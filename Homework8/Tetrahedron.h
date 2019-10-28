#pragma once
#include"Shape.h"
#include"ThreeDimensionalShape.h"
class Tetrahedron :public ThreeDimensionalShape {
public:
	Tetrahedron();
	double getArea();
	void setEdge(double);
	double getEdge();
	double getVolume();
	void printTetrahedron();
private:
	double l;
};