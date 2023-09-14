#include "realCoordinateConverter.h"
#include "config.h"

int RealCoordinateConverter::scale = SCALE;

bool Vec2d::operator==(const Vec2d& other) const {
    return x == other.x && y == other.y;
}

int RealCoordinateConverter::getScale(){
    return scale;
}

Vec2d RealCoordinateConverter::toMapCoordinate(Vec2d input) {
    return {input.x / scale, input.y / scale};
}

Vec2d RealCoordinateConverter::toTopLeftCornerRealCoordinate(Vec2d mapCoordinate) {
    return { mapCoordinate.x * scale, mapCoordinate.y * scale };
}