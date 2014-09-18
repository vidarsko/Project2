#include <iostream>
#include <armadillo>
#include "project2lib.h"
using namespace std;
using namespace arma;

int main(){
	int N = 5;
	mat A = 10*randu<mat>(N,N) - 5;
	cout << A << endl;
	vec ijm = odmmi(A,N);
	cout << "Off diagonal maximum matrix indices: " << endl << ijm << endl;
}