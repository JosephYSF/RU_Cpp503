#include<iostream>
#include"Shape.h"
#include"TwoDimensionalShape.h"
using namespace::std;
TwoDimensionalShape::TwoDimensionalShape() {

}

void TwoDimensionalShape::print2D() {
	cout << "(" << getx() << "," << gety() << ")";
}