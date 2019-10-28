#pragma once
#include <iostream>
class Shape {
public:
	Shape();
	int getx();
	int gety();
	int getz();
	void setx(int);
	void sety(int);
	void setz(int);
private:
	int x, y, z;
};