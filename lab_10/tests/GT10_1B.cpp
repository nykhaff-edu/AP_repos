#include <gtest/gtest.h>
#include "../tasks/10.1B/student.h"

TEST(Student10_1BTest, CountPhysicsFive) {
  Student group[2];

  group[0] = {"Іваненко", 1, KN, 5, 4, 0};
  group[0].prohramuvannya = 4;

  group[1] = {"Петренко", 2, INF, 3, 5, 0};
  group[1].chyselni_metody = 4;

  EXPECT_EQ(CountPhysicsFive(group, 2), 1);
}