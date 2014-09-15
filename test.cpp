#include <iostream>
#include <armadillo>
#include "project2lib.h"
using namespace std;
using namespace arma;

int main(){
	int N = 2;
	mat A (N,N);
	vec eigval = zeros(N);
	mat eigvec = zeros(N,N);
	eig_jacobi(eigval,eigvec,A);
}