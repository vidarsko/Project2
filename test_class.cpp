#include <iostream>
#include <armadillo>
#include "project2lib.h"
using namespace std;
using namespace arma;

int main(){
	SphericalQuantum test(2,5,-3);
	vec x = test.get_pos();
	test.set_potential(x%x);
	cout << test.get_V();
}