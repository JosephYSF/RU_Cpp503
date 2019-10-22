// Name: Sifan Yuan
// Time: 10/5/2019
// Course: 16:332:503, Programming Finance

//In Class Assignment 4
/*
Write a recursive method countBinStr that takes one integer 
parameter n as input, and returns the number of binary 
strings of length n that do not have two consecutive 0's.
*/

#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <vector>


using namespace std;
int countBinStr(int num) {
	int ans;
	if (num == 1)return 2;
	if (num == 2)return 3;
	else return ans = countBinStr(num - 1) + countBinStr(num - 2);
	//countBinStr(num-1) suggest to the number of strings when the first number is 1
	//countBinStr(num-1) suggest to the number of strings when the first number is 0
	//so the total number is the addition of the above 2 :)
}

//function main begins   
int main()
{
	int len = 0;
	while (len < 1) {
		cout << "Please input the length of binary string:" << endl;
		cin >> len;
		if (len < 1)cout << "The length must larger than 0!" << endl;
	}
	cout << "the number of binary strings of length n that do not\nhave two consecutive 0's is " << countBinStr(len) << endl;
	return 0;
}	//end function main
