#include "matrix.h"

// Матрица с вычеркнутыми i, j строкой и столбцом
void Matrix::new_matrix_wo_row_col(const Matrix& other, int r, int c) {
  int offset_row = 0;
  for (int i = 0; i < other.rows - 1; i++) {
    if (i == r) {
      offset_row = 1;
    }
    int offset_col = 0;
    for (int j = 0; j < other.cols - 1; j++) {
      if (j == c) {
        offset_col = 1;
      }
      this->matrix[i][j] = other.matrix[i + offset_row][j + offset_col];
    }
  }
}

void Matrix::print_matrix() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int Matrix::get_rows() { return rows; }

void Matrix::set_rows(const int i) { rows = i; }

void Matrix::set_cols(const int j) { cols = j; }

int Matrix::get_cols() { return cols; }

double Matrix::get_elem(const int i, const int j) { return matrix[i][j]; }

void Matrix::set_elem(const double n, const int i, const int j) {
  matrix[i][j] = n;
}

double& Matrix::get_adress(const int i, const int j) { return matrix[i][j]; }
