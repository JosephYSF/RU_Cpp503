#include<iostream>
#include"Shape.h"

Shape::Shape() {
	setx(0);
	sety(0);
	setz(0);
}

void Shape::setx(int X) {
	x = X;
}

void Shape::sety(int Y) {
	y = Y;
}

void Shape::setz(int Z) {
	z = Z;
}

int Shape::getx() {
	return x;
}

int Shape::gety() {
	return y;
}

int Shape::getz() {
	return z;
}