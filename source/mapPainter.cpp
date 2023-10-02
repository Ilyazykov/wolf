#include "mapPainter.h"

#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>

#include "config.h"
#include "realCoordinateConverter.h"

namespace MapPainter {
    void Stdout::paint(const Map& map) {
        std::cout << map << std::endl;
    }

    void SFML::paint(const Map& map) {
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
                            rect.setFillColor(sf::Color::Red);
                        }

                        Vec2d pos = RealCoordinateConverter::toTopLeftCornerRealCoordinate({x, y});
                        rect.setPosition(pos.x, pos.y);

                        window.draw(rect);
                    }
                }
            }

            window.display();
        }
    }
}