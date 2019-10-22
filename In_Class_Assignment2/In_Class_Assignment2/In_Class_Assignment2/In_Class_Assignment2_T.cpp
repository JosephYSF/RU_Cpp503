// Name: Sifan Yuan
// Time: 09/13/2019
// Course: 16:332:503, Programming Finance

//In Class Assignment 2_Triangular
/* 
Write a program that uses "for" structures to print the following triangular shape
. You need to ask the user how many lines he/she wants in the shape. Maximize your
use of repetition and minimizes the number of output statements.
*/

#include <iostream>
using namespace std;

//function main begins
int main()
{
	int l;//used as input
	int n, m;
	cout << "How mant lines you want in the shape?\n";
	cin >> l;
	for (n = 1;n <= l;n++) {
		for (m = 0;m < n;m++) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0; //indicate that program ended successfully

}//end function main