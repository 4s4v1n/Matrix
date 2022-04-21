# Matrix 

![matix](./images/matrix.png)

## This project presents the implementation of matrices in the form of a class, and operations on matrices in the form of objects of this class

The concept of a matrix is implemented using the `Matrix` class

This class contains fields `_matrix` - data, `_rows` - rows, `_cols` - columns

## All operations are implemented as public methods

 1) `bool eq_matrix(const Matrix& other)` - matrix comparison
 2) `void sum_matrix(const Matrix& other)` - addition of the current matrix to another
 3) `void sub_matrix(const Matrix& other)` - difference of the current matrix with another
 4) `void mul_number(const double num)` - multiplication of a matrix by a number
 5) `void mul_matrix(const Matrix& other)` - multiplying a matrix by another matrix
 6) `Matrix transpose()` - calculating the transposed matrix from the current one
 7) `Matrix calc_complements()` - calculation of the matrix of algebraic additions from the current one
 8) `double determinant()` - determinant calculation
 9) `Matrix inverse_matrix()` - calculation of the inverse matrix for the current

## Additionally, for simplified use of methods - operator overloading is implemented

 1) `Matrix operator+(const Matrix& other)` - sum of two matrices (A * B)
 2) `Matrix operator-(const Matrix& other)` - difference of two matrices (A - B) 
 3) `Matrix operator*(const Matrix& other)` - product of two matrices (A * B)
 4) `Matrix operator*(const double num)` - product of a matrix and a number (A * x)
 5) `friend Matrix operator*(const double num, const Matrix&)` - product of number and matrix (x * A)
 6) `bool operator==(const Matrix& other)` - equality of two matrices (A == B)
 7) `void operator=(const Matrix& other)` - assigning values from one matrix to another (A = B)
 8) `void operator+=(const Matrix& other)` - addition of one matrix to another (A += B)
 9) `void operator-=(const Matrix& other)` - subtracting one matrix from another (A -= B)
 10) `void operator*=(const Matrix& other)` - multiplying a matrix by another matrix (A*= B)
 11) `void operator*=(const double num)` - multiplication of a matrix by a number (A*= x)
 12) `double& operator()(const int i, const int j)` - getting a reference to a matrix element by index A(i, j)


The library is built using makefile with g++ version 9.4.0, on Linux. Unit tests are written in gtest.All source materials and makefile are in the src folder.