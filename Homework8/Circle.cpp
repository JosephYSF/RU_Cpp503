#include<iostream>
#include"Circle.h"
#include"Shape.h"
#include"TwoDimensionalShape.h"
using namespace::std;
Circle::Circle() {
	setRadius(0.0);
}

void Circle::setRadius(double R) {
	R < 0.0 ? 0.0 : r = R;
}

double Circle::getRadius() {
	return r;
}

double Circle::getArea() {
	return 3.14159 * r * r;
}

void Circle::printCircle() {
	cout << "\nThe circle with radius " << getRadius() << " that is located at ";
	TwoDimensionalShape::print2D();
	cout << " has:" << endl;
	cout << "An area of " << getArea() << endl;
}