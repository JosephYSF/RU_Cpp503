#include "OvernightPackage_SF.h"
#include <iostream>
using namespace::std;

OvernightPackage::OvernightPackage(char* n1, char* a1, char* c1, char* z1, char* n2, char* a2, char* c2, char* z2, double w, double cost, double f)
	: Package(n1, a1, c1, z1, n2, a2, c2, z2, w, cost)
{
	setFlatpo2(f);
}

double OvernightPackage::getFlatpo2()
{
	return flatpo2;
}

void OvernightPackage::setFlatpo2(double f2)
{
	this->flatpo2 = f2 >= 0.0 ? f2 : 0.0;
}

double OvernightPackage::calculateCost()
{
	return Package::calculateCost() + getWeight() * getFlatpo2();
}

void OvernightPackage::print_cost()
{
	cout << "\nWeight of package : " << getWeight() << " ounces" << endl;
	cout << "Type of delivery : Overnight Delivery" << endl;
	cout << "Cost of Package : $" << calculateCost() << endl;
}
