// Name: Sifan Yuan
// Time: 10/18/2019
// Course: 16:332:503, Programming Finance

//Homework 7
/*
Please develop class "Polynomial". The internal representation 
of a polynomial is an array of terms. Each term contains a 
coefficient and an exponent.
*/

#include <iostream>
#include "Polynomial_SifanYuan.h";

using namespace std;
int main()
{
	Polynomial P1;
	Polynomial P2;
	Polynomial P3;
	Polynomial P4;
	Polynomial P5;
	Polynomial P6;
	cin >> P1;
	cout << endl;
	cin >> P2;
	cout << endl;
	cout << "The first polynomial is:";
	cout << P1<<endl;
	cout << "The second polynomial is:";
	cout << P2<<endl;
	
	cout << "Adding polynomial yields : ";
	P3 = P1 + P2;
	cout << P3<<endl;
	
	cout << "+= the polynomial yields : ";
	P4 = P1;
	P4 += P2;
	cout << P4 << endl;
	
	cout << "Subtracting the polynomial yield : ";
	P3 = P1 - P2;
	cout << P3 << endl;
	
	cout << "-= the polynomial yields : ";
	P4 = P1;
	P4 -= P2;
	cout << P4 << endl;
	
	cout << "Multiplying the polynomials yields : ";
	P3 = P1 * P2;
	cout << P3 << endl;
	
	cout << "*= the polynomial yields : ";
	P4 = P1;
	P4 *= P2;
	cout << P4 << endl;
	
	return 0;
}//end of main function
