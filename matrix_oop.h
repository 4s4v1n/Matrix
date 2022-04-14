#ifndef MATRIX_OOP_H_
#define MATRIX_OOP_H_

#include <cmath>
#include <iostream>

#define STANDART_MATRIX_SIZE 3

class Matrix {
 private:
  int rows, cols;
  double** matrix;

 public:
  // Конструкторы
  Matrix();
  Matrix(int rows, int cols);
  Matrix(const Matrix& other);
  Matrix(Matrix&& other);
  ~Matrix();

  // Основные методы
  bool eq_matrix(const Matrix& other);
  void sum_matrix(const Matrix& other);
  void sub_matrix(const Matrix& other);
  void mul_number(const double num);
  void mul_matrix(const Matrix& other);
  Matrix transpose();
  Matrix calc_complements();
  double determinant();
  Matrix inverse_matrix();

  // Операторы
  Matrix operator+(const Matrix& other);
  Matrix operator-(const Matrix& other);
  Matrix operator*(const Matrix& other);
  Matrix operator*(const double num);
  friend Matrix operator*(const double num, const Matrix&);
  bool operator==(const Matrix& other);
  void operator=(const Matrix& other);
  void operator+=(const Matrix& other);
  void operator-=(const Matrix& other);
  void operator*=(const Matrix& other);
  void operator*=(const double num);
  double& operator()(const int i, const int j);

  // accessor'ы и mutator'ы
  int get_rows();
  void set_rows(const int i);
  int get_cols();
  void set_cols(const int j);
  double get_elem(const int i, const int j);
  void set_elem(const double n, const int i, const int j);
  double& get_adress(const int i, const int j);

  // Вспомогательные функции
  void print_matrix();
  void new_matrix_wo_row_col(const Matrix& other, int r, int c);
};

#endif  // MATRIX_OOP_H_
