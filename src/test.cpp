#include <gtest/gtest.h>

#include "matrix.h"

TEST(Test, based_constructor) {
  Matrix M;
  ASSERT_EQ(M.rows(), 3);
  ASSERT_EQ(M.cols(), 3);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
