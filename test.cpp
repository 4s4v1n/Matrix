#include <gtest/gtest.h>

#include "matrix_oop.h"

TEST(Test, based_constructor) {
  Matrix M;
  ASSERT_EQ(M.get_rows(), STANDART_MATRIX_SIZE);
  ASSERT_EQ(M.get_cols(), STANDART_MATRIX_SIZE);
}

TEST(Test, param_constructor) {
  Matrix M(5, 6);
  ASSERT_EQ(M.get_rows(), 5);
  ASSERT_EQ(M.get_cols(), 6);
}

TEST(Test, move_construct) {
  Matrix A(3, 3);
  A.set_elem(-1., 0, 0);
  Matrix B(std::move(A));
  ASSERT_DOUBLE_EQ(B.get_elem(0, 0), -1.);
}

TEST(Test, cpy_construct) {
  Matrix A(2, 2);
  A.set_elem(2., 0, 0);
  Matrix B(A);
  ASSERT_DOUBLE_EQ(B.get_elem(0, 0), 2.);
}

TEST(Test, eq_matrix_wrong_size) {
  Matrix A(2, 3);
  Matrix B(3, 3);
  ASSERT_FALSE(A.eq_matrix(B));
}

TEST(Test, eq_matrix_1) {
  Matrix A(3, 3);
  Matrix B(3, 3);
  ASSERT_TRUE(A.eq_matrix(B));
}

TEST(Test, eq_matrix_2) {
  Matrix A(3, 3);
  Matrix B(3, 3);
  A.set_elem(1.5, 1, 1);
  B.set_elem(1.5, 1, 1);
  ASSERT_TRUE(A.eq_matrix(B));
}

TEST(Test, eq_matrix_3) {
  Matrix A(3, 3);
  Matrix B(3, 3);
  A.set_elem(1.5, 1, 1);
  B.set_elem(2.5, 1, 1);
  ASSERT_FALSE(A.eq_matrix(B));
}

TEST(Test, sum_2) {
  Matrix A(3, 3);
  Matrix B(3, 3);
  A.set_elem(15.5, 2, 2);
  B.set_elem(14.5, 2, 2);
  A.set_elem(1., 1, 1);
  B.set_elem(1., 1, 1);
  A.sum_matrix(B);
  ASSERT_DOUBLE_EQ(A.get_elem(2, 2), 30.);
  ASSERT_DOUBLE_EQ(A.get_elem(1, 1), 2.);
}

TEST(Test, sub_2) {
  Matrix A(3, 3);
  Matrix B(3, 3);
  A.set_elem(3.5, 1, 1);
  B.set_elem(1., 1, 1);
  B.set_elem(2., 2, 2);
  A.sub_matrix(B);
  ASSERT_DOUBLE_EQ(A.get_elem(1, 1), 2.5);
  ASSERT_DOUBLE_EQ(A.get_elem(2, 2), -2.);
}

TEST(Test, mul_n_1) {
  Matrix A(3, 3);
  A.set_elem(8., 1, 1);
  A.set_elem(1., 2, 2);
  A.mul_number(-3.);
  ASSERT_DOUBLE_EQ(A.get_elem(1, 1), -24.);
  ASSERT_DOUBLE_EQ(A.get_elem(2, 2), -3.);
}

TEST(Test, mul_matrix_2) {
  Matrix A(2, 2);
  Matrix B(2, 2);
  A.set_elem(2., 0, 0);
  A.set_elem(4., 1, 1);
  B.set_elem(-1., 0, 0);
  B.set_elem(3., 1, 0);
  A.mul_matrix(B);
  ASSERT_EQ(A.get_rows(), 2);
  ASSERT_EQ(A.get_cols(), 2);
  ASSERT_DOUBLE_EQ(A.get_elem(0, 0), -2.);
  ASSERT_DOUBLE_EQ(A.get_elem(1, 0), 12.);
}

TEST(Test, mul_matrix_3) {
  Matrix A(2, 3);
  Matrix B(3, 1);
  A.set_elem(4., 0, 0);
  A.set_elem(17., 0, 2);
  A.set_elem(-290., 1, 1);
  B.set_elem(-1., 0, 0);
  B.set_elem(3., 1, 0);
  B.set_elem(1., 2, 0);
  A.mul_matrix(B);
  ASSERT_DOUBLE_EQ(A.get_elem(0, 0), 13.);
  ASSERT_DOUBLE_EQ(A.get_elem(1, 0), -870.);
}

TEST(Test, det_1) {
  Matrix A(2, 2);
  A.set_elem(3., 0, 0);
  A.set_elem(2., 0, 1);
  A.set_elem(4., 1, 1);
  A.set_elem(-1., 1, 0);
  ASSERT_DOUBLE_EQ(A.determinant(), 14.);
}

TEST(Test, det_2) {
  Matrix A(4, 4);
  A.set_elem(7., 0, 0);
  A.set_elem(2., 0, 1);
  A.set_elem(1., 0, 2);
  A.set_elem(3., 0, 3);
  A.set_elem(3., 1, 2);
  A.set_elem(2., 2, 0);
  A.set_elem(5., 2, 2);
  A.set_elem(1., 3, 0);
  A.set_elem(6., 3, 1);
  A.set_elem(-9., 3, 3);
  ASSERT_DOUBLE_EQ(A.determinant(), -216.);
}

TEST(Test, calc_compl_1) {
  Matrix A(4, 4);
  A.set_elem(-1, 0, 0);
  A.set_elem(3., 0, 2);
  A.set_elem(2., 1, 1);
  A.set_elem(4., 1, 2);
  A.set_elem(7., 1, 3);
  A.set_elem(5., 2, 2);
  A.set_elem(2., 3, 0);
  A.set_elem(6., 3, 1);
  A.set_elem(9., 3, 3);
  Matrix B(A.calc_complements());
  ASSERT_DOUBLE_EQ(B.get_elem(0, 0), -120.);
  ASSERT_DOUBLE_EQ(B.get_elem(0, 1), 70.);
  ASSERT_DOUBLE_EQ(B.get_elem(0, 2), 0.);
  ASSERT_DOUBLE_EQ(B.get_elem(0, 3), -20.);
  ASSERT_DOUBLE_EQ(B.get_elem(1, 1), -45.);
  ASSERT_DOUBLE_EQ(B.get_elem(1, 3), 30.);
  ASSERT_DOUBLE_EQ(B.get_elem(2, 0), 72.);
  ASSERT_DOUBLE_EQ(B.get_elem(2, 1), -6.);
  ASSERT_DOUBLE_EQ(B.get_elem(2, 2), 24.);
  ASSERT_DOUBLE_EQ(B.get_elem(2, 3), -12.);
  ASSERT_DOUBLE_EQ(B.get_elem(3, 1), 35.);
  ASSERT_DOUBLE_EQ(B.get_elem(3, 3), -10.);
}

TEST(Test, transpose) {
  Matrix A(3, 2);
  A.set_elem(-1., 0, 1);
  Matrix B(A.transpose());
  ASSERT_DOUBLE_EQ(B.get_elem(1, 0), -1.);
  ASSERT_EQ(B.get_rows(), 2);
  ASSERT_EQ(B.get_cols(), 3);
}

TEST(Test, inverse_1) {
  Matrix A(3, 3);
  A.set_elem(1., 0, 0);
  A.set_elem(3., 0, 1);
  A.set_elem(2., 1, 1);
  A.set_elem(4., 1, 2);
  A.set_elem(-5., 2, 1);
  Matrix B(A.inverse_matrix());
  ASSERT_DOUBLE_EQ(B.get_elem(0, 0), 1.);
  ASSERT_DOUBLE_EQ(B.get_elem(0, 2), 0.6);
  ASSERT_DOUBLE_EQ(B.get_elem(1, 2), -0.2);
  ASSERT_DOUBLE_EQ(B.get_elem(2, 1), 0.25);
  ASSERT_DOUBLE_EQ(B.get_elem(2, 2), 0.1);
}

TEST(Test, oper_plus) {
  Matrix A(3, 3);
  Matrix B(3, 3);
  A.set_elem(15.5, 2, 2);
  B.set_elem(14.5, 2, 2);
  A.set_elem(1., 1, 1);
  B.set_elem(1., 1, 1);
  Matrix C(A + B);
  ASSERT_DOUBLE_EQ(C.get_elem(2, 2), 30.);
  ASSERT_DOUBLE_EQ(C.get_elem(1, 1), 2.);
}

TEST(Test, oper_sub) {
  Matrix A(3, 3);
  Matrix B(3, 3);
  A.set_elem(3.5, 1, 1);
  B.set_elem(1., 1, 1);
  B.set_elem(2., 2, 2);
  Matrix C(std::move(A - B));
  ASSERT_DOUBLE_EQ(C.get_elem(1, 1), 2.5);
  ASSERT_DOUBLE_EQ(C.get_elem(2, 2), -2.);
}

TEST(Test, oper_mul_num) {
  Matrix A(3, 3);
  A.set_elem(8., 1, 1);
  A.set_elem(1., 2, 2);
  A = (A * -3.);
  ASSERT_DOUBLE_EQ(A.get_elem(1, 1), -24.);
  ASSERT_DOUBLE_EQ(A.get_elem(2, 2), -3.);
}

TEST(Test, oper_mul_matrix) {
  Matrix A(2, 3);
  Matrix B(3, 1);
  A.set_elem(4., 0, 0);
  A.set_elem(17., 0, 2);
  A.set_elem(-290., 1, 1);
  B.set_elem(-1., 0, 0);
  B.set_elem(3., 1, 0);
  B.set_elem(1., 2, 0);
  A = (A * B);
  ASSERT_DOUBLE_EQ(A.get_elem(0, 0), 13.);
  ASSERT_DOUBLE_EQ(A.get_elem(1, 0), -870.);
}

TEST(Test, oper_plus_eq) {
  Matrix A(3, 3);
  Matrix B(3, 3);
  A.set_elem(15.5, 2, 2);
  B.set_elem(14.5, 2, 2);
  A.set_elem(1., 1, 1);
  B.set_elem(1., 1, 1);
  A += B;
  ASSERT_DOUBLE_EQ(A.get_elem(2, 2), 30.);
  ASSERT_DOUBLE_EQ(A.get_elem(1, 1), 2.);
}

TEST(Test, oper_sub_eq) {
  Matrix A(3, 3);
  Matrix B(3, 3);
  A.set_elem(3.5, 1, 1);
  B.set_elem(1., 1, 1);
  B.set_elem(2., 2, 2);
  A -= B;
  ASSERT_DOUBLE_EQ(A.get_elem(1, 1), 2.5);
  ASSERT_DOUBLE_EQ(A.get_elem(2, 2), -2.);
}

TEST(Test, oper_mul_num_eq) {
  Matrix A(3, 3);
  A.set_elem(8., 1, 1);
  A.set_elem(1., 2, 2);
  A *= -3;
  ASSERT_DOUBLE_EQ(A.get_elem(1, 1), -24.);
  ASSERT_DOUBLE_EQ(A.get_elem(2, 2), -3.);
}

TEST(Test, oper_mul_eq_matrix) {
  Matrix A(2, 3);
  Matrix B(3, 1);
  A.set_elem(4., 0, 0);
  A.set_elem(17., 0, 2);
  A.set_elem(-290., 1, 1);
  B.set_elem(-1., 0, 0);
  B.set_elem(3., 1, 0);
  B.set_elem(1., 2, 0);
  A *= B;
  ASSERT_DOUBLE_EQ(A.get_elem(0, 0), 13.);
  ASSERT_DOUBLE_EQ(A.get_elem(1, 0), -870.);
}

TEST(Test, oper_eq) {
  Matrix A(2, 2);
  A.set_elem(-12.3, 0, 0);
  Matrix B(A);
  ASSERT_TRUE(A == B);
}

TEST(Test, bracket_val) {
  Matrix A(2, 3);
  A.set_elem(7.5, 1, 1);
  ASSERT_DOUBLE_EQ(A(1, 1), 7.5);
}

TEST(Test, bracket_adr) {
  Matrix A(2, 3);
  ASSERT_EQ(A.get_adress(1, 2), A(1, 2));
}

TEST(Test, num_mul) {
  Matrix A(2, 3);
  A(1, 1) = 6.;
  Matrix B(2 * A);
  ASSERT_DOUBLE_EQ(B(1, 1), 12.);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
