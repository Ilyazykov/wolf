#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>

#include "map.h"
#include "camera.h"
#include "mapPainter.h"
#include "realCoordinateConverter.h"


int main() {
    Map map("maps/1.map");

    Vec2d<int> cameraPos = RealCoordinateConverter::toCenterRealCoordinate({1, 1});
    Camera camera({(double)cameraPos.x, (double)cameraPos.y}, {1,2}, 0);

    std::unique_ptr<MapPainter::Painter> mapPainter = std::make_unique<MapPainter::RayCasting>();
    mapPainter->paint(map, camera);

    return 0;
}