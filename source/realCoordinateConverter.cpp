#include "realCoordinateConverter.h"
#include "config.h"

int RealCoordinateConverter::scale = SCALE;

int RealCoordinateConverter::getScale(){
    return scale;
}

Vec2d<int> RealCoordinateConverter::toMapCoordinate(Vec2d<int> input) {
    return {input.x / scale, input.y / scale};
}

Vec2d<int> RealCoordinateConverter::toTopLeftCornerRealCoordinate(Vec2d<int> mapCoordinate) {
    return { mapCoordinate.x * scale, mapCoordinate.y * scale };
}

Vec2d<int> RealCoordinateConverter::toCenterRealCoordinate(Vec2d<int> mapCoordinate) {
    return { ((2*mapCoordinate.x + 1) * scale)/2, ((2*mapCoordinate.y + 1) * scale)/2 };
}

int RealCoordinateConverter::toLeftSideRealXCoordinate(int mapXCoordinate) {
    return mapXCoordinate * scale;
}

int RealCoordinateConverter::toRightSideRealXCoordinate(int mapXCoordinate) {
    return (mapXCoordinate + 1) * scale - 1; // TODO magic number -1 brake smoothness of ray casting
}

int RealCoordinateConverter::toTopSideRealYCoordinate(int mapYCoordinate) {
    return mapYCoordinate * scale;
}

int RealCoordinateConverter::toBottomSideRealYCoordinate(int mapYCoordinate) {
    return (mapYCoordinate + 1) * scale - 1; // TODO magic number -1 brake smoothness of ray casting
}