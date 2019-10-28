#include "Tetrahedron.h"
#include <iostream>
using namespace::std;

Tetrahedron::Tetrahedron()
{
	l = 0.0;
}

double Tetrahedron::getArea()
{
	return sqrt(3.0) * l * l;
}

void Tetrahedron::setEdge(double L)
{
	L < 0.0 ? 0.0 : l = L;
}

double Tetrahedron::getEdge()
{
	return l;
}

double Tetrahedron::getVolume()
{
	return sqrt(2.0) / 12.0 * l * l * l;
}

void Tetrahedron::printTetrahedron()
{
	cout << "\nThe regular tetrahedron with edge length " << getEdge() << " that is located at ";
	ThreeDimensionalShape::print3D();
	cout << " has:" << endl;
	cout << "Surface area of " << getArea() << endl;
	cout << "Volume of " << getVolume() << endl;
}
