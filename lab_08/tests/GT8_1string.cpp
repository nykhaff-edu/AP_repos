#define TEST_MODE
#include <gtest/gtest.h>

#include "../tasks/8_1string.cpp"

TEST(GT8_1string, FindThirdComma) {
  string str = "1/1.1.,,,1";

  EXPECT_EQ(findThirdSymbol(str, ','), 8);
}

TEST(GT8_1string, Replace) {
  string str = "1,1,1,1,1";
  string res = change(str, ',');

  string expected = "1**1**1**1**1";

  EXPECT_EQ(res, expected);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}