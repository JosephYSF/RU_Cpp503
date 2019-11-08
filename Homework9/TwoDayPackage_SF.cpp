#include "TwoDayPackage_SF.h"
#include <iostream>
using namespace::std;


TwoDayPackage::TwoDayPackage(char* n1, char* a1, char* c1, char* z1, char* n2, char* a2, char* c2, char* z2, double w, double cost, double f)
	: Package(n1, a1, c1, z1, n2, a2, c2, z2, w, cost)
{
	setFlatpo1(f);
}


double TwoDayPackage::getFlatpo1()
{
	return flatpo1;
}

void TwoDayPackage::setFlatpo1(double f)
{
	this->flatpo1 = f >= 0.0 ? f : 0.0;
}

// calculate the two day deliver cost of the package
double TwoDayPackage::calculateCost()
{
	return Package::calculateCost() + getWeight() * getFlatpo1();
}

//print cost info for package
void TwoDayPackage::print_cost()
{
	cout << "\nWeight of package : " << getWeight() << " ounces" << endl;
	cout << "Type of delivery : Two Day Delivery" << endl;
	cout << "Cost of Package : $" << calculateCost() << endl;
}
