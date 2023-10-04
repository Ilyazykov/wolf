#ifndef REAL_COORDINATE_CONVERTER_H
#define REAL_COORDINATE_CONVERTER_H

template <typename T>
struct Vec2d {
    T x;
    T y;

    bool operator==(const Vec2d& other) const {
        return x == other.x && y == other.y;
    }

    // TODO: add cast method (from int to double)
};

class RealCoordinateConverter {
    static int scale;
public:
    static int getScale();
    static Vec2d<int> toMapCoordinate(Vec2d<int> input);
    static Vec2d<int> toTopLeftCornerRealCoordinate(Vec2d<int> mapCoordinate);
    static Vec2d<int> toCenterRealCoordinate(Vec2d<int> mapCoordinate);
};

#endif // REAL_COORDINATE_CONVERTER_H