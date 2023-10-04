#include <gtest/gtest.h>
#include "config.h"
#include "camera.h"

TEST(CoordinateConverterTest, CheckTopLeft) {
    Vec2d<int> realPos = { 0, 0 };

    Vec2d<int> mapPos = RealCoordinateConverter::toMapCoordinate(realPos);

    Vec2d<int> expected = { 0, 0 };
    EXPECT_EQ(mapPos, expected);
}

TEST(CoordinateConverterTest, CheckTopRight) {
    Vec2d<int> realPos = { RealCoordinateConverter::getScale()*5, 0 };

    Vec2d<int> mapPos = RealCoordinateConverter::toMapCoordinate(realPos);
    
    Vec2d<int> expected = { 5, 0 };
    EXPECT_EQ(mapPos, expected);
}

// TEST(CoordinateConverterTest, CheckBottomLeft) {
//     Vec2d<int> realPos = { 0, RealCoordinateConverter::getScale()*5 };

//     Vec2d<int> mapPos = RealCoordinateConverter::toMapCoordinate(realPos);
    
//     Vec2d<int> expected = { 0, 5 };
//     EXPECT_EQ(mapPos, expected);
// }

// TEST(CoordinateConverterTest, CheckBottomRight) {
//     Vec2d<int> realPos = { RealCoordinateConverter::getScale()*5, RealCoordinateConverter::getScale()*5 };

//     Vec2d<int> mapPos = RealCoordinateConverter::toMapCoordinate(realPos);
    
//     Vec2d<int> expected = { 5, 5 };
//     EXPECT_EQ(mapPos, expected);
// }

// TEST(CoordinateConverterTest, CheckCenter) {
//     Vec2d<int> realPos = { static_cast<int>(RealCoordinateConverter::getScale()*2.5), static_cast<int>(RealCoordinateConverter::getScale()*2.5) };

//     Vec2d<int> mapPos = RealCoordinateConverter::toMapCoordinate(realPos);
    
//     Vec2d<int> expected = { 2, 2 };
//     EXPECT_EQ(mapPos, expected);
// }

// TEST(CoordinateConverterTest, CheckMapToRealTopLeftCorner) {
//     Vec2d<int> mapPos = { 1, 1 };

//     Vec2d<int> realPosRes = RealCoordinateConverter::toTopLeftCornerRealCoordinate(mapPos);
    
//     Vec2d<int> realPosExpected = { static_cast<int>(RealCoordinateConverter::getScale()), 
//                               static_cast<int>(RealCoordinateConverter::getScale()) };
//     EXPECT_EQ(realPosRes, realPosExpected);
// }
