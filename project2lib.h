#ifndef project2lib_h
#define project2lib_h
#include <iostream>
#include <armadillo>
#include <cmath>
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
		vec pos,V,Energies;
		mat Energy_states; 
	public:
		//Constructor
		SphericalQuantum (int a, double b, double c=0);

		//****************************Member functions*************************//
		//Configure functions
		void set_potential(vec potential);

		//Solvefunctions
		void solve(void);

		//Data extraction functions
		vec get_pos(void);
		vec get_V(void);

		//Test functions
		void testprint(void);
};	

#endif