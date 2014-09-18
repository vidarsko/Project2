#include <iostream>
#include <armadillo>
#include "project2lib.h"
using namespace std;
using namespace arma;

int main(){
	int N = 5;
	mat A = randu<mat>(N,N);
	cout << A << endl;
	vec ijm = odmmi(A,N);
	cout << "Off diagonal maximum matrix indices: " << endl << ijm << endl;
}