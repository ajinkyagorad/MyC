#include <iostream>
#include <math.h>

using namespace std;

const  double psi_=0.01,psi1_=0,psi2_=0 ;	// initial values for vairables
double dx = 0.0001;			// dx for each step
double k(double x);			// k as a function of x 
double psi1(double x,double lastPsi1,double delta);
double psi(double x, double lastPsi,double delta);
double psi2(double x)
int main(void)
{
		cout<<"Hello myself";
}
double psi(double x, double lastPsi, double delta)
{
		double psi_x = lastPsi+psi1(x,lastPsi1,delta)*delta;
		return psi_x;
}
double psi1(double x,double lastPsi1 = psi1_,double delta= dx)
{
				return lastPsi1 + psi2(x)*dx;
}
double psi2(double x)
{
		double  kx=k(x);
		return  -1*kx*kx*psi(x);
}
