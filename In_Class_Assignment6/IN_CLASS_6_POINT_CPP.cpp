#include<iostream>
#include"IN_CLASS_6_POINT_H.h"

Point::Point(){
	setx(0);
	sety(0);
}

Point::Point(int X, int Y) {
	setx(X);
	sety(Y);
}

int Point::getx() {
	return x;
}

int Point::gety() {
	return y;
}

void Point::setx(int X) {
	x = X;
}

void Point::sety(int Y) {
	y = Y;
}