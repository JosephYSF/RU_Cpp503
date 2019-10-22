#pragma once
#include <iostream>
using namespace std;
class Polynomial
{
public:
	Polynomial();
	friend ostream& operator<<(ostream& , const Polynomial&);
	friend istream& operator>>(istream& , Polynomial&);
	Polynomial operator+(const Polynomial&);
	Polynomial operator-(const Polynomial&);
	Polynomial operator*(const Polynomial&);
	void operator=(const Polynomial&);
	void operator+=(const Polynomial&);
	void operator-=(const Polynomial&);
	Polynomial operator*=(const Polynomial&);

private:
	double coef[13];
};
