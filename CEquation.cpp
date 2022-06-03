

#include "CEquation.h"
#include<math.h>

CEquation::CEquation(double left, double right) {
	this->a = left;
	this->b = right;
	this->c = 0.0;
	this->dbg = false;
}

CEquation::~CEquation() {
	if(dbg){
		cout << "Constructor of CEquation called" << endl;
	}
}

void CEquation::solve(double (*f)(double)){
	if(f(a) * f(b) > 0 ){
		throw CEquationException("Wrong interval!!!");
		return;
	}
	double EPSILON = 1e-9;
	int i = 0;
	do{
		i++;
		c = (a + b) / 2;
		if(f(a) * f(c) < 0){
			b = c;
		} else {
			a = c;
		}
		if(dbg){
			cout << c << endl;
		}
	} while(fabs(b-a) > EPSILON);
	cout << "Number of iterations: " << i <<endl ;
}
//Variable Chord method
void CEquation::solve2(double (*f)(double)) {
	if (f(a) * f(b) > 0) {
		throw CEquationException("Wrong interval!!!");
		return;
	}
	double EPSILON = 1e-9;
	int i = 0;
	do {
		i++;
		c = ((b - a) * (-f(a))) / (f(b) - f(a)) + a;
			b = a;
			a = c;
		if (dbg) {
			cout << c << endl;
		}
	} while (fabs(b - a) > EPSILON);
	cout << "Number of iterations: " << i << endl;
}
