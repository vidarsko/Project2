#ifndef project2lib_h
#define project2lib_h
#include <iostream>
#include <armadillo>
using namespace std;
using namespace arma;

//Function for finding eigenvalues and eigenvectors using the jacobi method
void eig_jacobi(vec& eigval,mat& eigvec,mat A);
//Help functions for completing that task


#endif