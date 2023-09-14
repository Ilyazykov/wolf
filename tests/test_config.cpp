#include <gtest/gtest.h>
#include "config.h"

TEST(GameConstTest, CheckWall) {
    EXPECT_EQ(WALL, '#');
}

TEST(GameConstTest, CheckSpace) {
    EXPECT_EQ(SPACE, '_');
}

TEST(GameConstTest, CheckCharacter) {
    EXPECT_EQ(CHARACTER, 'c');
}
