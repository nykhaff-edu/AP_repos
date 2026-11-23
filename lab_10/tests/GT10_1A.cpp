#include <gtest/gtest.h>
#include "../tasks/10.1A/student.h"

TEST(Student10_1ATest, CountPhysicsFive) {
  Student group[3] = {
      {"Іваненко", 1, KN, 5, 4, 5},
      {"Петренко", 2, INF, 4, 5, 4},
      {"Сидоренко", 1, ME, 5, 3, 2}
  };

  EXPECT_EQ(CountPhysicsFive(group, 3), 2);
}