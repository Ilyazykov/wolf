#include <iostream>

#include <SFML/Graphics.hpp>

#include "map.h"
#include "character.h"
#include "config.h"
#include "realCoordinateConverter.h"

int main() {
    Map map("maps/1.map");
    Character ch({15,15}, {0,1}, 0);
    std::cout << map << std::endl;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Example");

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

    return 0;
}