#include <gtest/gtest.h>
#include "config.h"
#include "character.h"

TEST(CoordinateConverterTest, CheckTopLeft) {
    Vec2d realPos = { 0, 0 };

    Vec2d mapPos = RealCoordinateConverter::toMapCoordinate(realPos);

    Vec2d expected = { 0, 0 };
    EXPECT_EQ(mapPos, expected);
}

TEST(CoordinateConverterTest, CheckTopRight) {
    Vec2d realPos = { RealCoordinateConverter::getScale()*5, 0 };

    Vec2d mapPos = RealCoordinateConverter::toMapCoordinate(realPos);
    
    Vec2d expected = { 5, 0 };
    EXPECT_EQ(mapPos, expected);
}

TEST(CoordinateConverterTest, CheckBottomLeft) {
    Vec2d realPos = { 0, RealCoordinateConverter::getScale()*5 };

    Vec2d mapPos = RealCoordinateConverter::toMapCoordinate(realPos);
    
    Vec2d expected = { 0, 5 };
    EXPECT_EQ(mapPos, expected);
}

TEST(CoordinateConverterTest, CheckBottomRight) {
    Vec2d realPos = { RealCoordinateConverter::getScale()*5, RealCoordinateConverter::getScale()*5 };

    Vec2d mapPos = RealCoordinateConverter::toMapCoordinate(realPos);
    
    Vec2d expected = { 5, 5 };
    EXPECT_EQ(mapPos, expected);
}

TEST(CoordinateConverterTest, CheckCenter) {
    Vec2d realPos = { static_cast<int>(RealCoordinateConverter::getScale()*2.5), static_cast<int>(RealCoordinateConverter::getScale()*2.5) };

    Vec2d mapPos = RealCoordinateConverter::toMapCoordinate(realPos);
    
    Vec2d expected = { 2, 2 };
    EXPECT_EQ(mapPos, expected);
}
