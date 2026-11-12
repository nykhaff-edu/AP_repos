#define TEST_MODE
#include <gtest/gtest.h>

#include "../tasks/8_1it.cpp"

TEST(GT8_1it, FindThirdComma) {
  char str[] = "1/1.1.,,,1";

  EXPECT_EQ(findThirdSymbol(str, ','), 8);
}

TEST(GT8_1it, Replace) {
  char str[] = "1,1,1,1,1";
  char* result = change(str, ',');

  char expected[] = "1**1**1**1**1";

  for (int i = 0; !(result[i] == '\0'); i++) {
    EXPECT_EQ(result[i], expected[i]);
  }

  delete[] result;
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}