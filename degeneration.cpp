#include <iostream>
#include <armadillo>
#include "project2lib.h"
using namespace std;
using namespace arma;

int main(){
	int n_step = 100; 
	double rho_max = 10;
	SphericalQuantum system(n_step,rho_max);
	vec rho = system.get_rho();
	system.set_potential(plain_harmonic(rho,1));
	system.solve();
	system.print2file();
}