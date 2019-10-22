// Name: Sifan Yuan
// Time: 10/5/2019
// Course: 16:332:503, Programming Finance

//Homework 5_1
/*
	Write a	recursive function that takes a positive integer parameter n, and prints
the	squares	of the integers from 1 to n, separated by commas. It should print the
squares	of the odd integers	in descending order first and then following with the
squares of the even integers in ascending order. It does not print a newline
character.
*/


#include <iostream>
#include<vector>

using namespace std;

void squaresArray(int*res, int l, int r, int temp) {
	if (l <= r && temp > 0) {
		if (temp % 2 == 1) {
			res[l] = temp * temp;
			temp--;
			squaresArray(res, ++l, r, temp);			//put odd^2 at left of the array
		}
		else {
			res[r] = temp * temp;
			temp--;
			squaresArray(res, l, --r, temp);			//put even^2 at left of the array
		}
	}
	else return;
	
}


int main()
{
	int n;
	cout<<"Please input a integer(from 1 to n):"<<endl;
	cin >>n;
	int temp = n;
	int* res ;//use a vector to save the value
	res = (int*)malloc(n * sizeof(int));
	int l = 0;
	int r = n - 1;			
	squaresArray(res, l, r, temp);
	cout << "The answer is:" << endl;
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}						//print out the result
	return 0;
}


