///////////////////////////////////////////////////////////////////////////////
// GAUSS ELIMINATION (with partial pivoting)
//    Ax = b
//
// This package contains three functions to perform
//    A = PLU                  (luFactorize)
//    x = U^{-1} L^{-1} P^T b  (luSolve)
//    Both                     (solve)
//
// luFactorize
//   Factors the matrix
//
//   Inputs
//     a      The matrix
//   Outputs
//     a      The LU factored matrix
//     p      The permutation of the factorization
//   Return
//     s      The status (SUCCESS, SINGULAR, or BADDATA)
//
// luSolve
//   Call only after factoring the matrix!  Solves the system.
//
//   Inputs
//     a      The factored matrix
//     p      The permutation of the factorization
//     x      The vector b
//   Outputs
//     x      The solution
//   Return
//     s      The status (SUCCESS, SINGULAR, or BADDATA)
//
// solve
//   Solves the system by calling the above two functions.
//
//   Inputs
//     a      The matrix
//     x      The vector b
//   Outputs
//     a      The LU factored matrix
//     p      The permutation of the factorization
//     x      The solution
//   Return
//     s      The status (SUCCESS, SINGULAR, or BADDATA)
//
///////////////////////////////////////////////////////////////////////////////

#ifndef GAUSSELIM_INCLUDED
#define GAUSSELIM_INCLUDED

#include "matrix.h"

enum ge_state {SUCCESS, SINGULAR, BADDATA};

ge_state luFactorize(Matrix& a, Permutation& p);
ge_state luSolve(const Matrix& a, const Permutation& p, Vector& x);

ge_state solve(Matrix& a, Permutation& p, Vector& x);

#endif
