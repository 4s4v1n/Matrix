/**
 * @file   tests.cpp
 * @author Savin A. S. <sav1nru<at>mail.ru>
 * @date   18/08/22
 */

#include <gtest/gtest.h>

#include "matrix.h"

TEST(TestConstructors, default)
{
    Matrix<int> matrix;
    ASSERT_EQ(matrix.rows(), 3);
    ASSERT_EQ(matrix.cols(), 3);
}

TEST(TestConstructors, withParams)
{
    Matrix<double> matrix {5, 12};
    ASSERT_EQ(matrix.rows(), 5);
    ASSERT_EQ(matrix.cols(), 12);
}

auto main(int argc, char** argv) -> int
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


