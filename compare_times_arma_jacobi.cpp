#include <iostream>
#include <armadillo>
#include "project2lib.h"
#include <time.h>
#include <fstream>
using namespace std;
using namespace arma;

int main(){
	ofstream output;
	output.open("compare_times_arma_jacobi.out");
	output << "n_step, jacobi, armadillo" << '\n';
	int rho_max = 6;
	for (int n_step = 10; n_step <= 210; n_step += 20){
		cout << n_step<< endl;
		//The need for numerous iterations decrease as n_step gets bigger.
		int k_iterations = 10000/n_step; 
		
		SphericalQuantum system(n_step,rho_max);
		vec rho = system.get_rho();
		system.set_potential(plain_harmonic(rho));

		//Jacobi
		clock_t start_jacobi = clock(); //Time stamp
		for (int k=0; k<k_iterations;k++){
			system.solve("jacobi");
		}
		clock_t end_jacobi = clock();
		long double time_jacobi = (end_jacobi-start_jacobi)/(k_iterations * (double)CLOCKS_PER_SEC);


		//Armadillo
		clock_t start_armadillo = clock();
		for (int k=0; k<k_iterations;k++){
			system.solve("armadillo");
		}
		clock_t  end_armadillo = clock();
		long double time_armadillo = (end_armadillo-start_armadillo)/(k_iterations * (double)CLOCKS_PER_SEC);

		output << n_step << ", " << time_jacobi << ", " << time_armadillo << '\n'; 
		
	}
	output.close();
}