#ifndef project2lib_h
#define project2lib_h
#include <iostream>
#include <armadillo>
#include <cmath>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
using namespace arma;

//Function for finding eigenvalues and eigenvectors using the jacobi method
void eig_jacobi(vec& eigval,mat& eigvec,mat A,int N,double tol = 1e-10);
//Help functions for completing that task
vec odmmi(mat A,int N); // Off Diagonal Max Matrix Indices

//Class for storing and solving the quantum problem
class SphericalQuantum{
	/*
	Class which stores the basic properties of a quantum system with a spherical 
	symmetric potential. It inclues functions which finds the energy levels of the 
	bound states and the corresponding eigenstates. 
	*/
	private:
		int n_step; 
		double rho_min,rho_max, h; 
		vec rho,V,Energies;
		mat Energy_states,H; 
	public:
		//Constructor
		SphericalQuantum (int a, double b, double c=0);

		//****************************Member functions*************************//
		//Configure functions
		void set_potential(vec potential);

		//Solvefunction
		void solve(string method="jacobi");

		//Data extraction functions
		vec get_rho(void);
		vec get_V(void);
		mat get_H(void);

		//Test and print functions
		void testprint(void);
		void print2file(void);
};	

//Different potential functions 
vec plain_harmonic(vec x,int l = 0);
vec two_elec(vec x,double omega_r=1);
#endif