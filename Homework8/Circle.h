#pragma once
#include"Shape.h"
#include"TwoDimensionalShape.h"
class Circle :public TwoDimensionalShape {
public:
	Circle();
	double getArea();
	void setRadius(double);
	double getRadius();
	void printCircle();
private:
	double r;
};