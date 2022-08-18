/**
 * @file   matrix.h
 * @author Savin A. S. sav1nru<at>mail.ru
 * @date   18/08/22
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <cmath>
#include <utility>
#include <stdexcept>

/**
 * @class Matrix
 * @brief Realization of matrix on cpp language
 */

class Matrix {

public:
  Matrix();
  Matrix(const int rows, const int cols);
  Matrix(const Matrix& other);
  Matrix(Matrix&& other);
  ~Matrix();
  auto operator=(const Matrix& other) -> Matrix&;

public:
  auto eq_matrix(const Matrix& other) const -> bool;
  auto sum_matrix(const Matrix& other) -> void;
  auto sub_matrix(const Matrix& other) -> void;
  auto mul_number(const double num) -> void;
  auto mul_matrix(const Matrix& other) -> void;
  auto transpose() const -> Matrix;
  auto calc_complements() const -> Matrix;
  auto determinant() const  -> double;
  auto inverse_matrix() const -> Matrix;

public:
  auto rows() const -> int;
  auto cols() const -> int;
  auto operator()(const int i, const int j) -> double&;

public:
  friend auto operator+(const Matrix& lhs, const Matrix& rhs) -> Matrix;
  friend auto operator-(const Matrix& lhs, const Matrix& rhs) -> Matrix;
  friend auto operator*(const Matrix& lhs, const Matrix& rhs) -> Matrix;
  friend auto operator*(const Matrix& lhs, const double rhs) -> Matrix;
  friend auto operator*(const double lhs, const Matrix& rhs) -> Matrix;
  friend auto operator==(const Matrix& lhs, const Matrix& rhs) -> bool;
  friend auto operator+=(Matrix& lhs, const Matrix& rhs) -> void;
  friend auto operator-=(Matrix& lhs, const Matrix& rhs) -> void;
  friend auto operator*=(Matrix& lhs, const Matrix& rhs) -> void;
  friend auto operator*=(Matrix& lhs, const double rhs) -> void;

private:
  void newMatrixWithoutRowAndCol(const Matrix& other, const int row, const int col);

private:
    static constexpr int standardSize = 3;

private:
    int      m_rows   {};
    int      m_cols   {};
    double** m_matrix {};

};

#endif  // MATRIX_H
