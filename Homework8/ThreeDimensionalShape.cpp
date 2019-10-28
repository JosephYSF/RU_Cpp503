#include<iostream>
#include"Shape.h"
#include"ThreeDimensionalShape.h"
using namespace::std;
ThreeDimensionalShape::ThreeDimensionalShape()
{
	setx(0);
	sety(0);
	setz(0);
}

void ThreeDimensionalShape::print3D()
{
	cout << "(" << getx() << "," << gety() << "," << getz() << ")";
}
