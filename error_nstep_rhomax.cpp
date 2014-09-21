#include <iostream>
#include <armadillo>
#include <fstream>
#include "project2lib.h"
using namespace std;
using namespace arma;

int main(){
	ofstream output;
	output.open("error_nstep_rhomax.out");

	int 	n_step_min = 10, 	n_step_max = 100, 	n_step_indent=10;
	double 	rho_max_min = 1,	rho_max_max = 25,	rho_max_indent=5;
	int number_eig_max = 3;

	//Title_bar
	output << "n_step, ";
	for (double rho_max=rho_max_min;rho_max<rho_max_max;rho_max+=rho_max_indent){
		for (int number_eig = 0; number_eig<number_eig_max;number_eig++){
			output << "rho_max" << rho_max << "_E" << number_eig << ", ";
		}
	}
	output << '\n';

	//Content
	for (int n_step=n_step_min; n_step <=n_step_max; n_step +=n_step_indent){
		output << n_step << ", ";
		cout << n_step << endl;
		for (double rho_max=rho_max_min;rho_max<rho_max_max;rho_max+=rho_max_indent){
			SphericalQuantum system(n_step, rho_max);
			vec rho = system.get_rho();
			system.set_potential(plain_harmonic(rho));
			system.solve();
			vec E = system.get_lambda(number_eig_max);
			for (int i=0;i<number_eig_max;i++){
				output << E(i) << ", ";
			}
		}
		output << '\n';
	}
	output.close();
	return 0;
}