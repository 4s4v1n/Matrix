#include "matrix.h"

// Конструктор с параметрами
Matrix::Matrix(int rows, int cols) {
  if (rows > 0 && cols > 0) {
    this->rows = rows;
    this->cols = cols;
    matrix = new double*[this->rows];
    for (int i = 0; i < this->rows; i++) {
      matrix[i] = new double[this->cols];
    }
    for (int i = 0; i < this->rows; i++) {
      for (int j = 0; j < this->cols; j++) {
        matrix[i][j] = 0.;
      }
    }
  } else {
    throw std::invalid_argument("Invalid size of matrix");
  }
}

// Конструктор по умолчанию
Matrix::Matrix() {
  rows = STANDART_MATRIX_SIZE;
  cols = STANDART_MATRIX_SIZE;
  matrix = new double*[STANDART_MATRIX_SIZE];
  for (int i = 0; i < STANDART_MATRIX_SIZE; i++) {
    matrix[i] = new double[STANDART_MATRIX_SIZE];
  }
  for (int i = 0; i < STANDART_MATRIX_SIZE; i++) {
    for (int j = 0; j < STANDART_MATRIX_SIZE; j++) {
      matrix[i][j] = 0.;
    }
  }
}

// Деструктор
Matrix::~Matrix() {
  if (matrix != nullptr) {
    for (int i = 0; i < rows; i++) {
      delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
    cols = 0;
    rows = 0;
  }
}

// Конструктор копирования
Matrix::Matrix(const Matrix& other) {
  this->rows = other.rows;
  this->cols = other.cols;
  this->matrix = new double*[this->rows];
  for (int i = 0; i < this->rows; i++) {
    this->matrix[i] = new double[this->cols];
  }
  for (int i = 0; i < this->rows; i++) {
    for (int j = 0; j < this->cols; j++) {
      this->matrix[i][j] = other.matrix[i][j];
    }
  }
}

// Конструктор переноса
Matrix::Matrix(Matrix&& other) {
  if (this != &other) {
    this->rows = other.rows;
    this->cols = other.cols;
    this->matrix = other.matrix;
    other.rows = 0;
    other.cols = 0;
    other.matrix = nullptr;
  }
}
