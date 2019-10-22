// Name: Sifan Yuan
// Time: 09/08/2019
// Course: 16:332:503, Programming Finance

//Homework 1
/*Write a program that does the followings:
1. Ask the user to enter five numbers.
2. Find the maximum and minimum of those numbers.
3. Display the maximum and minimum as results.

Please notice the following :
1. For the comparisons, use 'if' statements.*/

/*
#include<iostream>
using namespace std;

//function main begins
int main()
{
	double max,min; //number to be output
	double temp;
	int n;//number to be used as count
	double number[5];//number to be input
	for (n = 0;n <= 4;n++) {
		cin >> number[n];
	}
	for (n = 0;n < 4;n++) {
		if (number[n] > number[n + 1]) {
			temp = number[n];
			number[n] = number[n + 1];
			number[n + 1] = temp;//compare 2 numbers each round
		}
	}
	max = number[4];
	for (n = 0;n <= 4;n++) {
		if (number[n] < number[n + 1]) {
			temp = number[n];
			number[n] = number[n + 1];
			number[n + 1] = temp;//compare 2 numbers each round
		}
	}
	min = number[4];
	cout << "The maximum is " << max << " and the minimum is " << min;
	return 0; //indicate that program ended successfully
} //end function main
*/
///*
#include<iostream>
using namespace std;

//function main begins
int main()
{
	char arr[20]; 
	int i; for (i = 0; i & lt; 10; i++) *(arr + i) = 'A' + i;
	*(arr + i) = '\0'; cout << arr; 
	return 0;//indicate that program ended successfully
} //end function main
//*/