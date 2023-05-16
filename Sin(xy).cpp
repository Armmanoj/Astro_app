# include <iostream>
# include <iomanip>
# include <math.h>
# include <fstream>
using namespace std;

struct point {
	double* x;
	double* y;
	int N; //size of arrays
};
typedef struct point point;

double step_size(double xi, double yi, double xf, double err) {
	// This generates a bound on step size to solve under that error bound
	double K = yi - xi;
	return sqrt(2.4*err / ((xf - xi)*((K+2*xf)*(K+2*xf)+xf*(xf+2*K)+2)));
}

point solveqn(double xi, double yi, double xf, double err) {
	double step = step_size(xi, yi, xf, err);
	int N = floor((xf - xi)
		/ step); // number of steps to takes
	int i=0; // to keep track of how many steps have been calculated
	point sol;
	sol.x = (double*)malloc(sizeof(double) * N);
	sol.y = (double*)malloc(sizeof(double) * N);
	*(sol.x) = xi;
	*(sol.y) = yi;
	sol.N = N;
	float a, b, f; // solving y'=f(y,x) where f is sin function
	while (1) {
		if (++i == N) { break; }
		a = *(sol.x);
		b = *(sol.y);
		f = sin(a * b);
		(sol.x)++;
		(sol.y)++;
		*(sol.x) = a + step; 
		*(sol.y) = b + step * (f + sin((a + step) * (b + step * f))) * 0.5;
	}
	sol.x -= N - 1; // Returns pointer to origin
	sol.y -= N - 1;
	return sol;
}

int main()
{
	double xi;
	double xf;
	double yi;
	double err;
	cout << "Enter starting value of t: ";
	cin >> xi;
	cout << "Enter starting value of x: ";
	cin >> yi;
	cout << "Enter final value of t: ";
	cin >> xf;
	cout << "Enter allowable error: ";
	cin >> err;
	point sol = solveqn(xi, yi, xf, err);
	ofstream myfile("sol.txt");
	int i;
	if (myfile.is_open())
	{
		for (i = 0;i < sol.N;i++) {
			myfile << setprecision(15);
			myfile << (sol.x)[i] << 'A' << (sol.y)[i] << 'B';
		}
		myfile.close();
	}
	else {
		cout << "Unable to open file.";
	};
	free(sol.x);
	free(sol.y);
	sol.x = NULL;
	sol.y = NULL;
	return 0;
}
