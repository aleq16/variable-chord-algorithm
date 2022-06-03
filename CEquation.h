

#ifndef CEQUATION_H_
#define CEQUATION_H_

#include<iostream>

using namespace std;

class CEquationException : public runtime_error
{
    public:
	CEquationException(const string &msg) : runtime_error(msg){}
};

class CEquation {
public:
	CEquation(double, double);
	~CEquation();

	void solve(double (*pf)(double));
	void solve2(double (*pf)(double));

	bool isDbg() const { return dbg; }
	void setDbg(bool dbg = false) { this->dbg = dbg; }

	double getRoot() const { return c; }

private:
	double a, b, c;

	bool dbg;
};

#endif /* CEQUATION_H_ */
