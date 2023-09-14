#include <gtest/gtest.h>
#include <filesystem>
#include "map.h"

TEST(GameMapTest, DisplayEmptyMap) {
    Map map{2, 3}; // map(width, height)

    testing::internal::CaptureStdout();
    std::cout << map;
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "0 0 \n0 0 \n0 0 \n");
}

TEST(GameMapTest, LoadValidMapFromFile) {
    std::string filepath = "maps/correct_test_map.map";

    EXPECT_TRUE(std::filesystem::exists(filepath));
    EXPECT_NO_THROW(Map{filepath}); // map(mapfile path)
}

TEST(GameMapTest, LoadMapFromNonexistFile) {
    std::string filepath = "maps/nonexist_test_map.map";

    EXPECT_FALSE(std::filesystem::exists(filepath));
    EXPECT_THROW(Map{filepath}, std::runtime_error); // map(mapfile path)
}

TEST(GameMapTest, LoadMapWithUnequallySizedRowsFile) {
    std::string filepath = "maps/unequally_sized_rows_test_map.map";

    EXPECT_TRUE(std::filesystem::exists(filepath));
    EXPECT_THROW(Map{filepath}, std::runtime_error); // map(mapfile path)
}

TEST(GameMapTest, LoadMapFromFile) {
    std::string filepath = "maps/correct_test_map.map";
    EXPECT_TRUE(std::filesystem::exists(filepath));
    
    Map map{filepath}; // map(mapfile path)

    testing::internal::CaptureStdout();
    std::cout << map;
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "1 2 3 \n4 5 6 \n");
}

TEST(GameMapTest, LoadIncorrectMapFromFile) {
    std::string filepath = "maps/correct_letter_test_map.map";
    EXPECT_TRUE(std::filesystem::exists(filepath));

    Map map{filepath}; // map(mapfile path)

    testing::internal::CaptureStdout();
    std::cout << map;
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "1 2 3 \na 4 5 \n");
}

TEST(GameMapTest, RealTestMap) {
    std::string filepath = "maps/real_test.map";

    EXPECT_TRUE(std::filesystem::exists(filepath));
    EXPECT_NO_THROW(Map{filepath}); // map(mapfile path)
}