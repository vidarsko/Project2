#include "project2lib.h"

void eig_jacobi(vec& eigval,mat& eigvec,mat A,int N,double tol){
	/* 
	Function that takes a (nxn) matrix A and returns its eigenvalues
	and corresponding eigenvectors as column vectors 
	stored in eigval and eigvec respectively.
	Input:
	- vec& eigval - n-vector for storing eigenvalues
	- mat& eigvec - (nxn).matrix for storing eigenvectors as colums
	- mat A - the (nxn)-matrix we're interested in. 
	- int N - the dimension of the square A matrix.
	- tol [optional] - the tolerance for the off-diagonal elements. (default=1e-10)
	*/

	//Allocation of memory
	vec ijm;

	//Initial error estimate, larger than tol 
	double eps = 1;

	//While loop until tolerance criteria is met.
	while (eps>tol){
		//Finding the largest of diagonal element and its value.
		ijm = odmmi(A,N);
	}
}

vec odmmi(mat A,int N){
	/*
	Off Diagonal Max Matrix Indices:
	Function that takes a square matrix A and returns the indices as a
	of the maximum off-diagonal element of the A matrix and its value m.
	Input:
	- mat A - The matrix in question
	- int N - The dimension of the square matrix
	Output:
	- vec ijm - A 3-vector (i,j,m) consisting of the indices of the maximum element 
	m and m itself.
	*/
	vec ijm = zeros(3);
	double m = 0;
	for (int i = 0; i<N; i++){
		for (int j = 0; j<N; j++){
			if (abs(A(i,j))>m && i != j){
				m = abs(A(i,j));
				ijm(0) = i;
				ijm(1) = j;
				ijm(2) = m;
			}
		}
	}
	return ijm;
}