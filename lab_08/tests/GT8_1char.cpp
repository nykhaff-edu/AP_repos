#define TEST_MODE
#include <gtest/gtest.h>

#include "../tasks/8_1char.cpp"

TEST(GT8_1char, FindThirdComma) {
  char str[] = "1/1.1.,,,1";

  EXPECT_EQ(findThirdSymbol(str, ','), 8);
}

TEST(GT8_1char, Replace) {
  char str[] = "1,1,1,1,1";
  char* result = new char[strlen(str) * 2 + 1];
  change(str, ',', result);

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