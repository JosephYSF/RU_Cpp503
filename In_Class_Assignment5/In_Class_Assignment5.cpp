// Name: Sifan Yuan
// Time: 10/19/2019
// Course: 16:332:503, Programming Finance

//In Class Assignment 5
/*
Create class IntegerSet for which each object can hold integers in 
the range 0 through 100. A set is represented internally as an array
of ones and zeros. Array element a[ i ] is 1 if integer i is in the 
set. Array element a[ j ] is 0 if integer j is not in the set. The 
default constructor initializes a set to the so-called “empty-set,”
i.e., a set whose array representation contains all zeros.
*/

#include <iostream>
#include <iomanip>
#include"INTEGER_SET_H.h"
using namespace std;

// Driver program for class IntegerSet.
int main()
{
	IntegerSet a;
	IntegerSet b;
	IntegerSet c;
	IntegerSet d;

	cout << "Enter set A:\n";
	a.inputSet();
	cout << "\nSet A is : \n";
	a.printSet();

	cout << "\nEnter set B:\n";
	b.inputSet();
	cout << "\nSet B is : \n";
	b.printSet();

	c.unionOfSets(a, b);

	cout << "\nUnion of A and B is:\n";
	c.printSet();

	d.intersectionOfSets(a, b);

	cout << "\nIntersection of A and B is:\n";
	d.printSet();


	return 0;

} //end of main function
