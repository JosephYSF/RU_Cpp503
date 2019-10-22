// Homework2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

//function main begins
int main()
{
	int num;
	double x,y,pi;
	double n  = 0;
	cout << "How many plot do you want to have?\n";
	cin >> num;
	ofstream file;
	//opens the file myfile.txt
	file.open("myfile.txt");
	//for loop to write the values to the file
	srand(time(0));
	for (int i = 0;i < num;i++) {
		x = static_cast<double>(rand()) / RAND_MAX;
		y = static_cast<double>(rand()) / RAND_MAX;
		file << x << "       " << y << "\n";
		if ((x * x + y * y) < 1) n += 1;
	}
	pi = 4* n / num;
	cout << "PI is "<<pi<<"\nPrinted numbers to file myfile.txt\n";
	return 0; //indicate that program ended successfully
} //end function main

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
