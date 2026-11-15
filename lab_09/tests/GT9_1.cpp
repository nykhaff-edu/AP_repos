#include <gtest/gtest.h>
#include <math.h>

#include "../tasks/9.1/dod.h"
#include "../tasks/9.1/sum.h"
#include "../tasks/9.1/var.h"

using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

TEST(SumTest, X1) {
  x = 1;
  eps = 0.0001;
  sum();
  EXPECT_NEAR(S, exp(1.0), 0.001);
}

TEST(SumTest, X05) {
  x = 0.5;
  eps = 0.0001;
  sum();
  EXPECT_NEAR(S, exp(0.25), 0.001);
}

TEST(DodTest, FirstTerm) {
  x = 2;
  n = 1;
  a = 1;
  dod();
  EXPECT_DOUBLE_EQ(a, 4.0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
