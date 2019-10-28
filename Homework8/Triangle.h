#pragma once
#include"Shape.h"
#include"TwoDimensionalShape.h"

class Triangle :public TwoDimensionalShape {
public:
	Triangle();
	double getArea();
	void setEdge(double);
	double getEdge();
	void printTriangle();
private:
	double l;
};