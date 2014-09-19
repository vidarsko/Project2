#include <iostream>
#include <armadillo>
#include "project2lib.h"
using namespace std;
using namespace arma;

int main(){
	int n_step = 100;
	double rho_max = 10;
	SphericalQuantum test(n_step,rho_max);
	vec rho = test.get_rho();
	test.set_potential(two_elec(rho,1));
	test.solve();
	test.print2file();
}