#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>

#include "map.h"
#include "character.h"
#include "mapPainter.h"


int main() {
    Map map("maps/1.map");
    Character ch({15,15}, {0,1}, 0);

    std::unique_ptr<MapPainter::Painter> mapPainter = std::make_unique<MapPainter::SFML>();
    mapPainter->paint(map);

    return 0;
}