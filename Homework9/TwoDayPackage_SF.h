#pragma once
#include "Package_SF.h"

class TwoDayPackage : public Package {
public:
	TwoDayPackage(char*, char*, char*, char*, char*, char*, char*, char*, double = 0.0, double = 0.0, double = 0.0);

	double getFlatpo1();
	void setFlatpo1(double);
	virtual double calculateCost() ;
	virtual void print_cost();

private:
	double flatpo1;
};