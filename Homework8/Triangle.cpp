#include "Triangle.h"
#include <iostream>
#include <cmath>
using namespace::std;

Triangle::Triangle()
{
	l = 0.0;
}

double Triangle::getArea()
{
	return sqrt(3.0) / 4.0 * l * l;
}

void Triangle::setEdge(double L)
{
	l = L;
}

double Triangle::getEdge()
{
	return l;
}

void Triangle::printTriangle()
{
	cout << "\nThe triangle with edge length " << getEdge() << " that is located at ";
	TwoDimensionalShape::print2D();
	cout << " has:" << endl;
	cout << "An area of " << getArea() << endl;
}
