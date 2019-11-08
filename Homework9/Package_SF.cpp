#include "Package_SF.h"
#include <iostream>
#include <string>
using namespace::std;

Package::Package(char* n1, char* a1, char* c1, char* z1, char* n2, char* a2, char* c2, char* z2, double w, double cost)
	: name1(n1), address1(a1), city1(c1), zip1(z1), name2(n2), address2(a2), city2(c2), zip2(z2), weight(w), costpo(cost)
{

}

Package::Package() : name1(0), address1(0), city1(0), zip1(0), name2(0), address2(0), city2(0), zip2(0), weight(0), costpo(0)
{
}

double Package::calculateCost()
{
	return getWeight() * getCostpo();
}

//print addr info for package
void Package::print()
{
	cout << "\nSender : " << endl;
	cout << getName1() << endl;
	cout << getAddress1() << endl;
	cout << getCity1() << " , " << getZip1() << endl;

	cout << "\nRecipient : " << endl;
	cout << getName2() << endl;
	cout << getAddress2() << endl;
	cout << getCity2() << " , " << getZip2() << endl;
}

//print cost info for package
void Package::print_cost()
{
	cout << "\nWeight of package : " << getWeight() << " ounces" << endl;
	cout << "Type of delivery : Regular Delivery" << endl;
	cout << "Cost of Package : $" << calculateCost() << endl;
}

double Package::getWeight()
{
	return weight;
}

void Package::setWeight(double w)
{
	this->weight = w >= 0.0 ? w : 0.0;
}

double Package::getCostpo()
{
	return costpo;
}

void Package::setCostpo(double c)
{
	this->costpo = c >= 0.0 ? c : 0.0;
}

char* Package::getName1()
{
	return name1;
}

void Package::setName1(char* n1)
{
	name1 = n1;
}

char* Package::getAddress1()
{
	return address1;
}

void Package::setAddress1(char*a1)
{
	address1 = a1;
}

char* Package::getCity1()
{
	return city1;
}

void Package::setCity1(char*c1)
{
	city1 = c1;
}

char* Package::getZip1()
{
	return zip1;
}

void Package::setZip1(char*z1)
{
	zip1 = z1;
}

char* Package::getName2()
{
	return name2;
}

void Package::setName2(char* n2)
{
	name2 = n2;
}

char* Package::getAddress2()
{
	return address2;
}

void Package::setAddress2(char* a2)
{
	address2 = a2;
}

char* Package::getCity2()
{
	return city2;
}

void Package::setCity2(char* c2)
{
	city2 = c2;
}

char* Package::getZip2()
{
	return zip2;
}

void Package::setZip2(char* z2)
{
	zip2 = z2;
}