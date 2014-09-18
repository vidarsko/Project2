#ifndef project2lib_h
#define project2lib_h
#include <iostream>
#include <armadillo>
#include <cmath>
using namespace std;
using namespace arma;

//Function for finding eigenvalues and eigenvectors using the jacobi method
void eig_jacobi(vec& eigval,mat& eigvec,mat A,int N,double tol = 1e-10);
//Help functions for completing that task
vec odmmi(mat A,int N); // Off Diagonal Max Matrix Indices

#endif