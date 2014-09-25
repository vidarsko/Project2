#include <iostream>
#include <armadillo>
#include <fstream>
#include "project2lib.h"
using namespace std;
using namespace arma;

int main(){

	//Output results
	ofstream output;
	output.open("number_rotations_dim.out");
	output << "n_step ," << "Rotations \n";

	//Parameteres
	double rho_max = 10;

	for (int n_step = 2; n_step<360; n_step +=20){
		cout << n_step << endl;
		SphericalQuantum system(n_step,rho_max);
		vec rho = system.get_rho();
		system.set_potential(plain_harmonic(rho));
		system.solve();
		output << n_step << ", " << system.get_rotation_counter() << '\n';
	}
	output.close();
}