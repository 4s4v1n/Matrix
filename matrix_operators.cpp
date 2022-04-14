#include "matrix_oop.h"

Matrix Matrix::operator+(const Matrix& other) {
  Matrix A(*this);
  A.sum_matrix(other);
  return A;
}

Matrix Matrix::operator-(const Matrix& other) {
  Matrix A(*this);
  A.sub_matrix(other);
  return A;
}

Matrix Matrix::operator*(const Matrix& other) {
  Matrix A(*this);
  A.mul_matrix(other);
  return A;
}

Matrix Matrix::operator*(const double num) {
  Matrix A(*this);
  A.mul_number(num);
  return A;
}

bool Matrix::operator==(const Matrix& other) { return this->eq_matrix(other); }

void Matrix::operator=(const Matrix& other) {
  this->rows = other.rows;
  this->cols = other.cols;
  for (int i = 0; i < this->rows; i++) {
    for (int j = 0; j < this->cols; j++) {
      this->matrix[i][j] = other.matrix[i][j];
    }
  }
}

void Matrix::operator+=(const Matrix& other) { this->sum_matrix(other); }

void Matrix::operator-=(const Matrix& other) { this->sub_matrix(other); }

void Matrix::operator*=(const Matrix& other) { this->mul_matrix(other); }

void Matrix::operator*=(const double num) { this->mul_number(num); }

double& Matrix::operator()(const int i, const int j) {
  if (i < 0 || j < 0 || i > rows || j > cols) {
    throw std::invalid_argument("Index outside matrix");
  }
  return matrix[i][j];
}

Matrix operator*(const double num, const Matrix& other) {
  Matrix A(other);
  A.mul_number(num);
  return A;
}
