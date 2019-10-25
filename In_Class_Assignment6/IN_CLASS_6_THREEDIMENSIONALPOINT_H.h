#pragma once
#include "IN_CLASS_6_POINT_H.h"

//add one more dimension (z) to Point
class ThreeDimensionalPoint : public Point {
public:
	ThreeDimensionalPoint();
	ThreeDimensionalPoint(int, int, int);
	ThreeDimensionalPoint operator+(ThreeDimensionalPoint&);
	void setz(int);
	int getz();
private:
	int z;
};