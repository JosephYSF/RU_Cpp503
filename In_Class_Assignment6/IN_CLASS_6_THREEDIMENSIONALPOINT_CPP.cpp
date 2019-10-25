#include<iostream>
#include"IN_CLASS_6_POINT_H.h"
#include"IN_CLASS_6_THREEDIMENSIONALPOINT_H.h"

ThreeDimensionalPoint::ThreeDimensionalPoint() {
	setx(0);
	sety(0);
	setz(0);
}

ThreeDimensionalPoint::ThreeDimensionalPoint(int X, int Y, int Z) {
	setx(X);
	sety(Y);
	setz(Z);
}

int ThreeDimensionalPoint::getz() {
	return z;
}

void ThreeDimensionalPoint::setz(int Z) {
	z = Z;
}

//overload "+"
ThreeDimensionalPoint ThreeDimensionalPoint::operator+(ThreeDimensionalPoint& exPoint) {
	(*this).setx((this->getx()) + exPoint.getx());
	(*this).sety((this->gety()) + exPoint.gety());
	(*this).setz((this->getz()) + exPoint.getz());
	//we can't visit x,y in this program so we use .getx, .gety to get the value of x,y
	return *this;
}