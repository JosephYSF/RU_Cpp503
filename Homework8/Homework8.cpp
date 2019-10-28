// Name: Sifan Yuan
// Time: 10/25/2019
// Course: 16:332:503, Programming Finance

//Homework 8
/*
As shown in the attachment, please implement a base class 'Shape' and two derived classes 'TwoDimensionalShape' and 'ThreeDimensionalShape'.
The class 'TwoDimensionalShape' should have two derived classes 'Circle' and 'Triangle' and the class 'ThreeDimensionalShape' should have two
derived classes 'Sphere' and 'Tetrahedron'.
*/

#include <iostream>
#include "Circle.h"
#include "Triangle.h"
#include"Sphere.h"
#include"Tetrahedron.h"
using namespace::std;

void ShowMenu()
{
	cout << "\nMenu" << endl;
	cout << "Please choose a shape or 0 to exit:" << endl;
	cout << " Choice 1: Circle" << endl;
	cout << " Choice 2: Triangle" << endl;
	cout << " Choice 3: Sphere" << endl;
	cout << " Choice 4: Regular Tetrahedron" << endl;
	cout << " Choice 0: Exit" << endl;
	cout << " Choice : ";
}

//main function begin
int main()
{
	Circle circle;
	Triangle triangle;
	Sphere sphere;
	Tetrahedron tetrahedron;
	int x = 0;
	int y = 0;
	int z = 0;
	int choice = 0;
	ShowMenu();
	cin >> choice;

	while (choice) {
		double radius = 0.0;
		double edge = 0.0;
		switch (choice)
		{
		case 1:
			cout << "You have chosen the circle." << endl;
			cout << "\nPlease enter the center of the circle (x-coordinate and then y-coordinate):" << endl;
			cin >> x >> y;
			circle.setx(x);
			circle.sety(y);
			cout << "\nPlease enter the radius of the circle:" << endl;
			cin >> radius;
			circle.setRadius(radius);
			circle.printCircle();
			break;

		case 2:
			cout << "You have chosen the triangle." << endl;
			cout << "\nPlease enter the center of the triangle (x-coordinate and then y-coordinate):" << endl;
			cin >> x >> y;
			triangle.setx(x);
			triangle.sety(y);
			cout << "\nPlease enter the edge length of the triangle:" << endl;
			cin >> edge;
			triangle.setEdge(edge);
			triangle.printTriangle();
			break;

		case 3:
			cout << "You have chosen the sphere." << endl;
			cout << "\nPlease enter the center of the sphere (x-coordinate, y-coordinate, then z-coordinate):" << endl;
			cin >> x >> y >> z;
			sphere.setx(x);
			sphere.sety(y);
			sphere.setz(z);
			cout << "\nPlease enter the radius of the sphere:" << endl;
			cin >> radius;
			sphere.setRadius(radius);
			sphere.printSphere();
			break;

		case 4:
			cout << "You have chosen the regular tetrahedron." << endl;
			cout << "\nPlease enter the center of the tetrahedron (x-coordinate, y-coordinate, then z-coordinate):" << endl;
			cin >> x >> y >> z;
			tetrahedron.setx(x);
			tetrahedron.sety(y);
			tetrahedron.setz(z);
			cout << "\nPlease enter the edge length of the tetrahedron:" << endl;
			cin >> edge;
			tetrahedron.setEdge(edge);
			tetrahedron.printTetrahedron();
			break;

		default:
			cout << "Wrong Input." << endl;
		}
		ShowMenu();
		cin >> choice;
	}
	cout << "\nThank you for using this program!"<<endl;
}