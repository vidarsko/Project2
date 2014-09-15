#include "project2lib.h"

void eig_jacobi(vec& eigval,mat& eigvec,mat A){
	/* 
	Function that takes a (nxn) matrix A and returns its eigenvalues
	and corresponding eigenvectors as column vectors 
	stored in eigval and eigvec respectively.
	Input:
	- vec& eigval - n-vector for storing eigenvalues
	- mat& eigvec - (nxn).matrix for storing eigenvectors as colums
	- mat A - the (nxn)-matrix we're interested in. 
	*/
	cout << "kaping!" << endl;
	cout << eigval << endl;
	eigval(0) = 22;
	cout << eigval << endl;
}