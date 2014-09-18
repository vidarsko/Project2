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
	mat B = A;
	vec klm;
	double m,tau,t,c,s,s2,c2,sc;
	int k,l; 

	//Initial error
	klm = odmmi(A,N);
	m = klm(2);

	//While loop until tolerance criteria is met.
	while (m>tol){
		//Finding the largest off-diagonal element and its value.
		k = klm(0),l = klm(1);

		//Jacobi rotate values
		tau = (A(l,l) - A(k,k))/(2*A(k,l));
		if (tau>=0){
			t = 1/(tau + sqrt(1 + tau*tau));
		}
		else {
			t = -1/(-tau+sqrt(1+tau*tau));
		}
		c = 1/sqrt(1+t*t);
		s = t*c;

		//Rotation product B
		for (int i = 0;i<N;i++){
			if (i!=k && i!=l){
				B(i,k) = A(i,k)*c - A(i,l)*s;
				B(k,i) = B(i,k);
				B(i,l) = A(i,l)*c + A(i,k)*s;
				B(l,i) = B(i,l);
			}
		}
		s2 = s*s; c2 = c*c; sc = s*c;
		B(k,k) = A(k,k)*c2 - 2*A(k,l)*sc + A(l,l)*s2;
		B(l,l) = A(l,l)*c2 + 2*A(k,l)*sc + A(k,k)*s2;
		B(k,l) = 0;
		B(l,k) = 0;

		//Update A and error estimate
		A = B;
		klm = odmmi(A,N);
		m = klm(2);
	}
	for (int i = 0; i<N; i++){
		eigval(i) = A(i,i);
	}
	cout << "Final matrix:" << endl;
	cout << A;
	
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
	- vec klm - A 3-vector (k,l,m) consisting of the indices of the maximum squared
	element m and m itself.
	*/
	vec klm = zeros(3);
	double m = 0;
	for (int i = 0; i<N; i++){
		for (int j = 0; j<N; j++){
			if (A(i,j)*A(i,j)>m && i != j){
				m = A(i,j)*A(i,j);
				klm(0) = i;
				klm(1) = j;
				klm(2) = m;
			}
		}
	}
	return klm;
}