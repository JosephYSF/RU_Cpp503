#pragma once

//Point used to save a two dimentional point value x and y
class Point {
public:
	Point();
	Point(int, int);
	void setx(int);
	void sety(int);
	int getx();
	int gety();
private:
	int x;
	int y;
};