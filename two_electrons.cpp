#include <iostream>
#include <armadillo>
#include "project2lib.h"
using namespace std;
using namespace arma;

int main(){
	//Different omega_r's to be tested
	vec omega_rs(4);
	omega_rs(0) = 0.01; omega_rs(1) = 0.5; omega_rs(2)=1.0; omega_rs(3)=5; 

	//Rho_max's for the different omega_r's
	double rho_max = 20;

	//Dimension
	int n_step = 200;

	for (int i=0;i<4;i++){
		double omega_r = omega_rs(i);
		SphericalQuantum system(n_step,rho_max);
		vec rho = system.get_rho();
		system.set_potential(two_elec(rho,omega_r));
		system.solve();
		system.print2file();

	}
}