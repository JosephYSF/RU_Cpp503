#pragma once
#include "Package_SF.h"
class OvernightPackage : public Package {
public:
	OvernightPackage(char*, char*, char*, char*, char*, char*, char*, char*, double = 0.0, double = 0.0, double = 0.0);

	double getFlatpo2();
	void setFlatpo2(double);

	virtual double calculateCost() ;
	virtual void print_cost() ;

private:
	double flatpo2;

};
