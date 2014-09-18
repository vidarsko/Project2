#include <iostream>
#include <armadillo>
#include "project2lib.h"
using namespace std;
using namespace arma;

int main(){
	int N = 5;
	mat C = randu<mat>(N,N) - 0.5;
	mat A = C.t()*C; 
	cout << A << endl;
	vec eigval = zeros(N);
	mat eigvec = zeros(N,N);
	eig_jacobi(eigval,eigvec,A,N);
	cout << "Eigenvalues by jacobi: " << endl;
	cout << eigval << endl;
	eig_sym(eigval,A);
	cout << "Eigenvalues by armadillo: " << endl;
	cout << eigval << endl;

}