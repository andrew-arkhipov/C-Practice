/******************************************************************************
Vector, Matrix, and Permutation classes, and related fcns

For example:
  Vector v(5) gives avector v of 5 doubles, indexed from 0 to 4.
  Matrix m(5,12) gives a matrix of size 5X12 doubles,
                 indexed from 0 to 4 and 0 to 11.
******************************************************************************/

#ifndef Matrix_Included
#define Matrix_Included

#include <iostream>
#include <vector>

class Vector {
 private:
  int size;
  double* array;

 public:
  Vector(int n) { size = n;  array = new double[size]; };
  Vector() { size = 1, array = new double[size]; }; // class members initialization
  Vector(const Vector&);
  ~Vector() { delete[] array; }

  int n(int=0) const { return size; }  // return size of the vector

  double operator() (int i) const { return array[i]; }
     // access to return element of vector
  double& operator() (int i) { return array[i]; }
     // access to modify element of vector

  Vector& operator=(const Vector&);  // equate two vectors
  Vector& operator=(double);         // fill value into vector
  Vector& operator=(double*);        // copy array to vector. NOTE: unsafe
  Vector& operator=(std::vector<double>&);  // copy std::vector into vector. NOTE: safe
  Vector& operator+=(const Vector&); // increment vector by another vector
  Vector& operator-=(const Vector&); // decrement vector by another vector
  Vector& operator*=(double);        // multiplication by a scalar
  Vector& operator/=(double);        // division by a scalar

  double operator*(const Vector& v) const; // scalar dot product
};

class Matrix {
 private:
  int size[2];
  double* array;

 public:
  Matrix(int n0, int n1) { size[0] = n0; size[1] = n1;
    array = new double[size[0]*size[1]]; };
  Matrix(const Matrix&);
  ~Matrix() { delete[] array; }

  int n(int i) const { return size[i]; }

  double operator() (int i, int j) const { return array[i + size[0]*j]; }
     // access to return element of matrix
  double& operator() (int i, int j) { return array[i + size[0]*j]; }
     // access to modify element of matrix

  Matrix& operator=(const Matrix&);  // equate two matrices
  Matrix& operator=(double);         // fill value into matrix
  Matrix& operator+=(const Matrix&); // increment matrix by another matrix
  Matrix& operator-=(const Matrix&); // decrement matrix by another matrix
  Matrix& operator*=(double);        // multiplication by a scalar
  Matrix& operator/=(double);        // division by a scalar
};

class Permutation {
 private:
  int size;
  int* array;
  int my_parity;  

 public:
  Permutation(int n) { size = n;  array = new int[size]; identity(); };
  ~Permutation() { delete[] array; }

  int n(int=0) const { return size; }

  int operator() (int i) const { return array[i]; }

  void identity();
  void swap(int i, int j);
  double parity() const { return my_parity; }

  void permute(Vector& b) const;
};

std::ostream& operator<< (std::ostream&, const Vector&); // output vector
std::ostream& operator<< (std::ostream&, const Matrix&); // output matrix by rows
std::istream& operator>> (std::istream&, Vector&);       // input vector
std::istream& operator>> (std::istream&, Matrix&);       // input matrix by rows

double l2norm(const Vector&);  // L2-norm of the vector
double maxNorm(const Vector&); // L-infinity (max) norm of the vector
double maxNorm(const Matrix&); // L-infinity (max) norm of the matrix

double scDot(const Vector&, const Vector&); // Scalar dot product of vectors
int matVecMult(const Matrix& M, const Vector& x, Vector& y); // y = Mx
int matMatMult(const Matrix& A, const Matrix& B, Matrix& C); // C = AB


#endif
