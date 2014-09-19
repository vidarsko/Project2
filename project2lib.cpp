#include "project2lib.h"

void eig_jacobi(vec& eigval,mat& eigvec,mat A,int N,double tol){
	/* 
	Function that takes a (nxn) matrix A and returns its eigenvalues
	and corresponding eigenvectors as column vectors 
	stored in eigval and eigvec respectively.
	Input:
	- vec& eigval - n-vector for storing eigenvalues
	- mat& eigvec - (nxn).matrix for storing eigenvectors as colums.
	- mat A - the (nxn)-matrix we're interested in. 
	- int N - the dimension of the square A matrix.
	- tol [optional] - the tolerance for the off-diagonal elements. (default=1e-10)
	*/

	//Allocation of memory
	mat B = A,R(N,N);
	vec klm;
	double m,tau,t,c,s,s2,c2,sc,r_il,r_ik;
	int k,l; 

	//Initial error and R matrix
	R.eye();
	klm = odmmi(A,N);
	m = klm(2);

	//While loop until tolerance criteria is met.
	while (m>tol){
		cout << m << endl;
		//Print error to estimate time developement
		cout << m << endl;

		//Finding the largest off-diagonal element indices
		k = klm(0),l = klm(1);

		//Jacobi rotate values
		tau = (A(l,l) - A(k,k))/(2*A(k,l));
		if (tau>=0){
			t = 1/(tau + sqrt(1 + tau*tau));
		}
		else {
			t = -1/(-tau+sqrt(1+tau*tau));
		}
		c = 1/sqrt(1+t*t);
		s = t*c;

		//Rotation product B
		s2 = s*s; c2 = c*c; sc = s*c;
		B(k,k) = A(k,k)*c2 - 2*A(k,l)*sc + A(l,l)*s2;
		B(l,l) = A(l,l)*c2 + 2*A(k,l)*sc + A(k,k)*s2;
		B(k,l) = 0;
		B(l,k) = 0;

		for (int i = 0;i<N;i++){
			if (i!=k && i!=l){
				B(i,k) = A(i,k)*c - A(i,l)*s;
				B(k,i) = B(i,k);
				B(i,l) = A(i,l)*c + A(i,k)*s;
				B(l,i) = B(i,l);
			}
			//Update eigenvectors
			r_ik = R(i,k);
			r_il = R(i,l);
			R(i,k) = c*r_ik - s*r_il;
			R(i,l) = c*r_il + s*r_ik;
		}

		//Update A and error estimate
		A = B;
		klm = odmmi(A,N);
		m = klm(2);
	}

	//Fill inn eigenvalues and eigenvectors
	for (int i = 0; i<N; i++){
		eigval(i) = A(i,i);
	}
	eigvec = R;

	//Sort
	uvec sort_indices = sort_index(eigval);
	mat eigvec_copy(N,N); 	eigvec_copy = eigvec; 
	vec eigval_copy(N);  	eigval_copy = eigval;
	for (int i = 0;i<N;i++){
		eigvec.col(i) = eigvec_copy.col(sort_indices(i));
		eigval(i) = eigval_copy(sort_indices(i));
	}
}

vec odmmi(mat A,int N){
	/*
	Off Diagonal Max Matrix Indices:
	Function that takes a square matrix A and returns the indices as a
	of the maximum off-diagonal element of the A matrix and its value m.
	Input:
	- mat A - The matrix in question
	- int N - The dimension of the square matrix
	Output:
	- vec klm - A 3-vector (k,l,m) consisting of the indices of the maximum squared
	element m and m itself.
	*/
	vec klm = zeros(3);
	double m = 0;
	for (int i = 0; i<N; i++){
		for (int j = 0; j<N; j++){
			if (A(i,j)*A(i,j)>m && i != j){
				m = A(i,j)*A(i,j);
				klm(0) = i;
				klm(1) = j;
				klm(2) = m;
			}
		}
	}
	return klm;
}


//******************SphericalQuantum class functions***********************//
//Constructor
SphericalQuantum::SphericalQuantum(int a, double b, double c){
	/*
	Constructor for the Spherical quantum class. 
	Takes arguments
	int a - n_step, the number of steps. (i.e. the resolution)
	double b - rho_max, the largest value of rho. 
	double c - rho_min [default=0], the smallest value of rho. 
	*/
	n_step = a; rho_max=b; rho_min=c;
	h = (rho_max-rho_min)/n_step;
	rho = linspace(rho_min,rho_max,n_step+1); //position array
}

//Configuration functions
void SphericalQuantum::set_potential(vec potential){
	/*
	Function that adds the potential to the system. 
	*/
	V = potential;
}

//Solve functions 
void SphericalQuantum::solve(string method){
	/*
	Solves the system using specified method.
	Input:
	- string method:
		"jacobi" (default)	-uses the jacobi rotation method.
		"armadillo"			-uses the method provided by the armadillo library. 
	*/
	//Dimensions on hamiltonian and energystates
	H = zeros(n_step,n_step);
	Energies = zeros(n_step);
	Energy_states = zeros(n_step,n_step);

	double ode = -1/(h*h); //off-diagonal element
	double h2 = h*h;
	//Set Hamiltonian matrix elements
	for (int i = 0;i<n_step;i++){
		H(i,i) = 2/h2 + V(i+1); //V goes from 0 to n_step, we want the middle part.
		if 		(i==0)			{H(i,i+1) = ode;}
		else if (i==n_step-1)	{				 H(i,i-1) = ode;}
		else 					{H(i,i+1) = ode; H(i,i-1) = ode;}
	}
	//Find the eigenvalues and states
	if (method == "jacobi"){
		eig_jacobi(Energies,Energy_states,H,n_step);
	}
	else if (method == "armadillo"){
		eig_sym(Energies,Energy_states,H);
	}
}

//Data extraction functions
vec SphericalQuantum::get_rho(void){
	/*
	Function that returns the position vector of the system.
	*/
	return rho;
}

vec SphericalQuantum::get_V(void){
	/*
	Fucntion that returns the potential of the system.
	*/
	return V;
}

mat SphericalQuantum::get_H(void){
	return H;
}

//Test and print functions
void SphericalQuantum::testprint(void){
	/* 
	Prints out values of different variables.
	*/
	cout << "rho_min = " << rho_min << endl;
	cout << "rho_max = " << rho_max << endl;
	cout << "n_step = " << n_step << endl;
	cout << "h =" << h << endl;
}

void SphericalQuantum::print2file(void){
	/*
	Prints the solved system to a datafile in the following format:
	Filename: "SphericalQuantum-[Date and time].out"
	Content:
	"""
	rho 	,V 		,psi_0 	, ... 	,psi_{n_{step}}	,E
	0,		,0.33	,0.00	, ... 	,0.00			,E_0
	h,		,0.423	,0.21	, ... 	,0.11 			,E_1
	...
	rho_max,0.22	,0.00	, ... 	,0.00			,E_{n_step}
	"""
	*/
	//Syntax to get time stamp
	time_t timer = time(NULL);
	struct tm * timeinfo  = localtime(&timer);
	char TID[80];
	strftime(TID,80,"%c",timeinfo);
	
	//Open file syntax
	ofstream myfile;
	string tmp = "SphericalQuantum-"; tmp.append(string(TID)); 
	tmp.append(".out"); const char* name = tmp.c_str(); 
	myfile.open(name);

	//Print data to file
	//Top row
	myfile << "rho, V, ";
	for (int i=0;i<n_step;i++){myfile<<"psi_"<<i<<", ";}
	myfile << "E\n";
	

	//Content
	//Zero position
	myfile << rho(0) << ", " << V(0) << ", ";
	for (int i=0;i<n_step;i++){myfile << "0, ";}
	myfile << Energies(0)<<",\n";
	for (int i = 1; i<n_step; i++){ //the middle part
		myfile << rho(i) << ", " << V(i) << ", "; //We want the middle part 
		for (int j=0;j<n_step;j++){myfile << Energy_states(i,j) << ", ";}
		myfile << Energies(i)<< ",\n";
	}

	//Close file
	myfile.close();
}


//*******************Potential functions ******************//
vec plain_harmonic(vec x, int l){
	/*
	The plain harmonic potential. 
	Input:
	- vec x: 			position coordinates
	- int l(default=0): angular momentum quantum number
	*/
	return x%x + l*(l+1)/(x%x);
}

vec two_elec(vec x,double omega_r){
	/*
	The potential used in the two-electron problem.
	Input:
	- vec x: 				position coordinates
	- omega_r (default=1):	strength of the harmonic oscillator
	*/
	return omega_r*x%x + 1/x;

}