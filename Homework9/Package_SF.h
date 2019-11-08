#pragma once
#include <string>
class Package {
public:
	Package(char*,char*, char*, char*, char*, char*, char*, char*, double = 0.0, double = 0.0);
	Package();
	virtual double calculateCost();
	void print();
	virtual void print_cost();

	double getWeight();
	void setWeight(double);

	double getCostpo();
	void setCostpo(double);

	char* getName1();
	void setName1(char*);

	char* getAddress1();
	void setAddress1(char*);

	char* getCity1();
	void setCity1(char*);

	char* getZip1();
	void setZip1(char*);

	char* getName2();
	void setName2(char*);

	char* getAddress2();
	void setAddress2(char*);

	char* getCity2();
	void setCity2(char*);

	char* getZip2();
	void setZip2(char*);
private:
	char* name1;
	char* address1;
	char* city1;
	char* zip1;
	char* name2;
	char* address2;
	char* city2;
	char* zip2;
	double weight;
	double costpo;
};