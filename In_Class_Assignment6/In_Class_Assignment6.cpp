// Name: Sifan Yuan
// Time: 10/25/2019
// Course: 16:332:503, Programming Finance

//In Class Assignment 6
/*

*/

#include <iostream>
using namespace::std;
#include"IN_CLASS_6_POINT_H.h"
#include"IN_CLASS_6_THREEDIMENSIONALPOINT_H.h"

//main function start
int main()
{
	ThreeDimensionalPoint point1(1, 2, 3);
	ThreeDimensionalPoint point2(4, 5, 6);
	point1 = point1 + point2; //already overload "+" in "IN_CLASS_6_THREEDIMENSIONALPOINT_H.h"
	cout << "\nThe value of the x value is: " << point1.getx();
	cout << "\nThe value of the y value is: " << point1.gety();
	cout << "\nThe value of the z value is: " << point1.getz();
	cout << endl;
}
