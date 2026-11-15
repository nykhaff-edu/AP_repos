#include <gtest/gtest.h>

#include "../tasks/9.2/macros.h"

TEST(MacrosTest, Max) { EXPECT_EQ(MAX(3, 5), 5); }

TEST(MacrosTest, Min) { EXPECT_EQ(MIN(3, 5), 3); }

TEST(MacrosTest, Abs) { EXPECT_EQ(ABS(-4), 4); }

TEST(MacrosTest, SqrWithExpression) { EXPECT_EQ(SQR(2 + 1), 9); }

TEST(MacrosTest, Cube) { EXPECT_EQ(CUBE(-2), -8); }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
