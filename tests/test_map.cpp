#include <gtest/gtest.h>
#include "map.h"

TEST(GameMapTest, DisplayEmptyMap) {
    Map map(2, 3); // map(width, height)

    testing::internal::CaptureStdout();
    std::cout << map;
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "0 0 \n0 0 \n0 0 \n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}