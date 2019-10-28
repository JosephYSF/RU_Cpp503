#pragma once
#include"Shape.h"
#include"ThreeDimensionalShape.h"
class Sphere :public ThreeDimensionalShape {
public:
	Sphere();
	double getArea();
	double getVolume();
	void setRadius(double);
	double getRadius();
	void printSphere();
private:
	double r;
};