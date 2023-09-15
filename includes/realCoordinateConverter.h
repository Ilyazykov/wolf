#ifndef REAL_COORDINATE_CONVERTER_H
#define REAL_COORDINATE_CONVERTER_H

struct Vec2d {
    int x;
    int y;

    bool operator==(const Vec2d& other) const;
};

class RealCoordinateConverter {
    static int scale;
public:
    static int getScale();
    static Vec2d toMapCoordinate(Vec2d input);
    static Vec2d toTopLeftCornerRealCoordinate(Vec2d mapCoordinate);
};

#endif // REAL_COORDINATE_CONVERTER_H