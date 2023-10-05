#include "mapPainter.h"

#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>

#include "config.h"
#include "realCoordinateConverter.h"

namespace MapPainter {
    void RayCasting::paint([[maybe_unused]] const Map& map, [[maybe_unused]] const Camera& camera) const {
        // TODO
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