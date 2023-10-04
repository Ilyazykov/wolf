#ifndef REAL_COORDINATE_CONVERTER_H
#define REAL_COORDINATE_CONVERTER_H

template <typename T>
struct Vec2d {
    T x;
    T y;

    bool operator==(const Vec2d& other) const {
        return x == other.x && y == other.y;
    }

    operator Vec2d<int>() const {
        int int_x = static_cast<int>(x);
        int int_y = static_cast<int>(y);

        Vec2d<int> res = {int_x, int_y};

        return res;
    }; // TODO test

    operator Vec2d<double>() const {
        double double_x = static_cast<double>(x);
        double double_y = static_cast<double>(y);

        Vec2d<double> res = {double_x, double_y};

        return res;
    }; // TODO test

    // TODO: add cast method (from int to double)
};

class RealCoordinateConverter {
    static int scale;
public:
    static int getScale();
    static Vec2d<int> toMapCoordinate(Vec2d<int> input);
    static Vec2d<int> toTopLeftCornerRealCoordinate(Vec2d<int> mapCoordinate);
    static Vec2d<int> toCenterRealCoordinate(Vec2d<int> mapCoordinate);

    static int toLeftSideRealXCoordinate(int mapXCoordinate) {
        return mapXCoordinate * scale; // TODO refactoring
    }

    static int toRightSideRealXCoordinate(int mapXCoordinate) {
        return (mapXCoordinate + 1) * scale - 1; // TODO refactoring
    }

    static int toTopSideRealYCoordinate(int mapYCoordinate) {
        return mapYCoordinate * scale; // TODO refactoring
    }

    static int toBottomSideRealYCoordinate(int mapYCoordinate) {
        return (mapYCoordinate + 1) * scale - 1; // TODO refactoring
    }
};

#endif // REAL_COORDINATE_CONVERTER_H