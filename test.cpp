#include <iostream>
#include <armadillo>
#include "project2lib.h"
using namespace std;
using namespace arma;

int main(){
	int N = 3;
	mat C = randu<mat>(N,N) - 0.5;
	mat A = C.t()*C; 
	mat A_jacobi = A;
	mat A_arma = A;
	cout << A << endl;
	vec eigval = zeros(N);
	mat eigvec = zeros(N,N);
	eig_jacobi(eigval,eigvec,A_jacobi,N);
	cout << "Eigenvectors by jacobi: " << endl;
	cout << eigvec << endl;
	eig_sym(eigval,eigvec,A_arma);
	cout << "Eigenvectors by armadillo: " << endl;
	cout << eigvec << endl;

}