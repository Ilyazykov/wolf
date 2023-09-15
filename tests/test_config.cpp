#include <gtest/gtest.h>
#include "config.h"

TEST(GameConstTest, CheckWall) {
    EXPECT_EQ(MAP_TILE_WALL, '#');
}

TEST(GameConstTest, CheckSpace) {
    EXPECT_EQ(MAP_TILE_SPACE, '_');
}

TEST(GameConstTest, CheckCharacter) {
    EXPECT_EQ(MAP_TILE_CHARACTER, 'c');
}
