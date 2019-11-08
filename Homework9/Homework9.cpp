// Name: Sifan Yuan
// Time: 11/1/2019
// Course: 16:332:503, Programming Finance

//Homework 9
/*
Create an inheritance hierarchy to represent the various types of packages. Use
Package as the base class of the hierarchy and then include classesTwoDayPackage 
and OvernightPackage that derive from Package. Base class Package should include 
data members representing the name, address, city, state and ZIP code for both 
the sender and the recipient of the package, in addition to data members that 
store the weight (in ounces) and cost per ounce to ship the package. Package's 
constructor should initialize these data members.
*/

#include <iostream>
#include<vector>
#include <string>
#include"TwoDayPackage_SF.h"
#include"OvernightPackage_SF.h"
#include"Package_SF.h"
using namespace std;

double VirtualViaPointer(Package*Ptr, int i)
{
	cout << "\nPackage " << i + 1 << " :" << endl;
	Ptr->print();
	Ptr->print_cost();
	return Ptr->calculateCost();
}

int main() {

	double total = 0.0;
	char n1[20] = "John Smith";
	char a10[20] = "1 Davidson Road";
	char a11[20] = "Piscataway";
	char a12[20] = "NJ 08854";
	char n2[20] = "Tom Smith";
	char a20[20] = "2 Davidson Road";
	char a21[20] = "Piscataway";
	char a22[20] = "NJ 08854";
	Package package(n1,a10,a11,a12,n2,a20,a21,a22,10.0,0.5);
	char nt1[20] = "Mary Smith";
	char at10[20] = "3 Davidson Road";
	char at11[20] = "Piscataway";
	char at12[20] = "NJ 08854";
	char nt2[20] = "Jennifer Smith";
	char at20[20] = "4 Davidson Road";
	char at21[20] = "Piscataway";
	char at22[20] = "NJ 08854";
	TwoDayPackage twoDayPackage(nt1,at10,at11,at12,nt2,at20,at21,at22,5.0, 0.5, 2.0);
	char no1[20] = "Mary Smith";
	char ao10[20] = "3 Davidson Road";
	char ao11[20] = "Piscataway";
	char ao12[20] = "NJ 08854";
	char no2[20] = "Jennifer Smith";
	char ao20[20] = "4 Davidson Road";
	char ao21[20] = "Piscataway";
	char ao22[20] = "NJ 08854";
	OvernightPackage overnightPackage(no1, ao10, ao11, ao12, no2, ao20, ao21, ao22, 2.0, 0.5, 5.0);

	vector < Package* > packptr;

	packptr.push_back(&package);
	packptr.push_back(&twoDayPackage);
	packptr.push_back(&overnightPackage);

	cout << "Cost per ounce for a package: $" << package.getCostpo() << "/ounce" << endl;
	cout << "Additional cost for two-day delivery: $" << twoDayPackage.getFlatpo1() << "/ounce" << endl;
	cout << "Additional cost for overnight delivery: $" << overnightPackage.getFlatpo2() << "/ounce" << endl;

	for (int i = 0; i < packptr.size(); i++)
	{
		total += VirtualViaPointer(packptr[i], i);
	}

	cout << "\nTotal cost of all the packages : $" << total << endl;

	return 0;
}