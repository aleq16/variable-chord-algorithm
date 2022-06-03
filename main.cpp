#include<iostream>
#include<conio.h>
#include "CEquation.h"

double f4(double x)
{
	return log(x) - exp(-x);
}
double f3(double x)
{
	return sin(x) - log(x);
}
double f1(double x){
	return log(x) + x;
}
int testEquation1(){
	cout << "Test CEquation class" << endl;

	CEquation * pEq = new CEquation(0.05, 3);
	pEq->setDbg(false);
	try{
		pEq->solve(f1);
		cout << "Root is: " << pEq->getRoot() << endl;
	} catch(CEquationException &cee){
		cout << cee.what() << endl;
	}
	delete pEq;
	return 0;
}
int testEquation2()
{
	CEquation* pEq = new CEquation(1, 4 * atan(1));
	pEq->setDbg(false);
	try {
		pEq->solve(f3);
		cout << "Root is: " << pEq->getRoot() << endl;
	}
	catch (CEquationException& cee) {
		cout << cee.what() << endl;
	}
	delete pEq;
	return 0;
}
int testEquation3()
{
	CEquation* pEq = new CEquation(1, 4);
	pEq->setDbg(false);
	try {
		pEq->solve(f4);
		cout << "Root is: " << pEq->getRoot() << endl;
	}
	catch (CEquationException& cee) {
		cout << cee.what() << endl;
	}

	delete pEq;
	return 0;
}
int testEquation4() {
	cout << "Test CEquation class" << endl;

	CEquation* pEq = new CEquation(0.05, 3);
	pEq->setDbg(false);
	try {
		pEq->solve2(f1);
		cout << "Root is: " << pEq->getRoot() << endl;
	}
	catch (CEquationException& cee) {
		cout << cee.what() << endl;
	}
	delete pEq;
	return 0;
}
int testEquation5()
{
	CEquation* pEq = new CEquation(1, 4 * atan(1));
	pEq->setDbg(false);
	try {
		pEq->solve2(f3);
		cout << "Root is: " << pEq->getRoot() << endl;
	}
	catch (CEquationException& cee) {
		cout << cee.what() << endl;
	}
	delete pEq;
	return 0;
}
int testEquation6()
{
	CEquation* pEq = new CEquation(1, 4);
	pEq->setDbg(false);
	try {
		pEq->solve2(f4);
		cout << "Root is: " << pEq->getRoot() << endl;
	}
	catch (CEquationException& cee) {
		cout << cee.what() << endl;
	}

	delete pEq;
	return 0;
}

int main(){
	int code;
	code = testEquation1();
	code = testEquation2();
	code = testEquation3();
	//----------Using the variable chord method
	code = testEquation4();
	code = testEquation5();
	code = testEquation6();

	_getch();
	return code;
}