#include "Sphere.h"
#include <iostream>
using namespace::std;
Sphere::Sphere()
{
	r = 0.0;
}

double Sphere::getArea()
{
	return 4.0 * 3.14159 * r * r;
}

double Sphere::getVolume()
{
	return 4.0 / 3.0 * 3.14159 * r * r * r;
}

void Sphere::setRadius(double R)
{
	R < 0.0 ? 0.0 : r = R;
}

double Sphere::getRadius()
{
	return r;
}

void Sphere::printSphere()
{
	cout << "\nThe sphere with radius " << getRadius() << " that is located at ";
	ThreeDimensionalShape::print3D();
	cout << " has:" << endl;
	cout << "Surface area of " << getArea() << endl;
	cout << "Volume of " << getVolume() << endl;
}
