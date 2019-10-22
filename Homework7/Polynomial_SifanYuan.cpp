#include <iostream>
#include "Polynomial_SifanYuan.h"
using namespace std;
int i = 1;

Polynomial::Polynomial()
{
	for (int i=0; i < 13; i++)coef[i] = 0;
}

// overload "<<" as output
ostream& operator<<(ostream& output, const Polynomial& Poly) {
	int j = 0;
	if (Poly.coef[0] != 0) {
		output << Poly.coef[0];
		j++;
	}
	if (Poly.coef[1] != 0) {
		if (j != 0)output << " + ";
		if (Poly.coef[1] != 1)output << Poly.coef[1] << "x";
		else output << "x";
		j++;
	}
	for (int i = 2; i < 13; i++) {
		if (Poly.coef[i] != 0) {
			if (j != 0)output << " + ";
			if (Poly.coef[i] != 1)output << Poly.coef[i] << "x^" << i;
			else output << "x^" << i;
			j++;
		}
	}
	cout << endl;
	return output;
}

// overload ">>" as input
istream& operator>>(istream& input, Polynomial& Poly) {
	int terms, exponent, coefficient;
	cout << "Enter the number of polynomial terms:";
	cin >> terms;
	for (int j = 0; j < terms; j++) {
		while (i) {
			cout << "Enter coefficient and exponent :";
			input >> coefficient;
			input >> exponent;
			if (exponent < 0 || exponent>6) {
				cout << "Invalid degree input. The greatest degree is 6." << endl;
			}
			else break;
		}
		Poly.coef[exponent] += coefficient;
	}
	return input;
}


// overload "+"
Polynomial Polynomial::operator+(const Polynomial& Polyb) {
	Polynomial Poly;
	for (int i = 0; i < 13; i++) {
		Poly.coef[i] = this->coef[i] + Polyb.coef[i];
	}
	return Poly;
}

// overload "-"
Polynomial Polynomial::operator-(const Polynomial& Polyb) {
	Polynomial Poly;
	for (int i = 0; i < 13; i++) {
		Poly.coef[i] = this->coef[i] - Polyb.coef[i];
	}
	return Poly;
}

Polynomial Polynomial::operator*(const Polynomial& Polyb) {
	Polynomial Poly;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			Poly.coef[i+j] += this->coef[i]*Polyb.coef[j];
		}
	}
	return Poly;
}

void Polynomial::operator=(const Polynomial& Poly) {
	for (int i = 0; i < 13; i++) {
		this->coef[i] = Poly.coef[i];
	}
}

void Polynomial::operator+=(const Polynomial& Poly) {
	for (int i = 0; i < 13; i++) {
		this->coef[i] += Poly.coef[i];
	}
}

void Polynomial::operator-=(const Polynomial& Poly) {
	for (int i = 0; i < 13; i++) {
		this->coef[i] -= Poly.coef[i];
	}
}

Polynomial Polynomial::operator*=(const Polynomial& Polyb) {
	Polynomial Poly;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			Poly.coef[i + j] += this->coef[i] * Polyb.coef[j];
		}
	}
	*this = Poly;
	return *this;
}