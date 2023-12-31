#include "mapPainter.h"

#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>

#include "config.h"
#include "realCoordinateConverter.h"

namespace MapPainter {
    void RayCasting::paint(const Map& map, const Camera& camera) const {
        auto distances = camera.getDistancesToIntersections(map);
        auto distances_screen = camera.getDistancesToScreen();

        sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME);
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            window.clear();

            for (int x = 0; x < WINDOW_WIDTH; ++x) {
                double distance_coef = distances_screen[x]/distances[x];
                double screen_wall_height = WALL_HEIGHT * distance_coef;
                int y_ceiling = WINDOW_HEIGHT/2 - screen_wall_height/2;
                int y_floor = WINDOW_HEIGHT/2 + screen_wall_height/2;

                sf::VertexArray line(sf::Lines, 2);

                line[0] = sf::Vertex(sf::Vector2f(x, WINDOW_HEIGHT/2), sf::Color(100,166,255));
                line[1] = sf::Vertex(sf::Vector2f(x, 0), sf::Color(100,166,255));
                window.draw(line);

                line[0] = sf::Vertex(sf::Vector2f(x, WINDOW_HEIGHT/2), sf::Color(128,128,128));
                line[1] = sf::Vertex(sf::Vector2f(x, WINDOW_HEIGHT), sf::Color(128,128,128));
                window.draw(line);

                
                line[0] = sf::Vertex(sf::Vector2f(x, y_ceiling), sf::Color(0, 255*distance_coef*2, 0));
                line[1] = sf::Vertex(sf::Vector2f(x, y_floor), sf::Color(0, 255*distance_coef, 0));
                window.draw(line);
            }
            //---------------------------------------------------------

            window.display();
        }
    }

    void Stdout::paint(const Map& map, [[maybe_unused]] const Camera& camera) const {
        std::cout << map << std::endl;
    }

    void SFML::paint(const Map& map, const Camera& camera) const {
        auto screenCoords = camera.getScreenPointCoords();
        auto secondCoords = camera.getIntersectionPointCoords(map);

        sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME);

        int scale = RealCoordinateConverter::getScale();

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            window.clear();

            for (int x = 0; x < map.getWidth(); ++x) {
                for (int y = 0; y < map.getHeight(); ++y) {
                    if (map.getValue(x, y) != MAP_TILE_SPACE) {
                        sf::RectangleShape rect(sf::Vector2f(scale, scale));

                        if (map.getValue(x, y) == MAP_TILE_WALL) {
                            rect.setFillColor(sf::Color::Blue);
                        } else if (map.getValue(x, y) == MAP_TILE_CHARACTER) {
                            rect.setFillColor(sf::Color::Green);
                        }

                        Vec2d pos = RealCoordinateConverter::toTopLeftCornerRealCoordinate({x, y});
                        rect.setPosition(pos.x, pos.y);

                        window.draw(rect);
                    }
                }
            }

            sf::CircleShape point(2.0f);
            point.setFillColor(sf::Color::Yellow);

            point.setPosition(camera.getPosition().x, camera.getPosition().y);
            window.draw(point);
            
            for (auto secondCoord : secondCoords) {
                sf::VertexArray lines(sf::Lines, 2);
                lines[0] = sf::Vertex(sf::Vector2f(camera.getPosition().x, camera.getPosition().y));
                lines[1] = sf::Vertex(sf::Vector2f(secondCoord.x, secondCoord.y));
                window.draw(lines);
            }

            for (auto secondCoord : secondCoords) {
                point.setFillColor(sf::Color::Red);
                point.setPosition(secondCoord.x, secondCoord.y);
                window.draw(point);
            }

            for (auto screenCoord : screenCoords) {
                point.setFillColor(sf::Color::Yellow);
                point.setPosition(screenCoord.x, screenCoord.y);
                window.draw(point);
            }

            window.display();
        }
    }
}