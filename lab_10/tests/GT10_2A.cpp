#include <gtest/gtest.h>

#include "../tasks/10.2A/student.h"

TEST(Student10_2ATest, BinSearchFound) {
  Student group[3] = {{"Іваненко", 1, CS, 4, 4, 4},
                      {"Петренко", 2, CS, 5, 5, 5},
                      {"Сидоренко", 1, INF, 5, 4, 3}};

  Sort(group, 3);

  EXPECT_EQ(BinSearch(group, 3, "Петренко", CS, 5.0), 2);
  EXPECT_EQ(BinSearch(group, 3, "Відсутній", CS, 5.0), -1);
}