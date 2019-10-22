// Name: Sifan Yuan
// Time: 10/5/2019
// Course: 16:332:503, Programming Finance

//Homework 5_2
/*
Consider a puzzle Jump that consists of a row of positive integers, except the
rightmost number, which is always a zero. A peg is placed on the leftmost
number. At each step, you may move the peg either left or right a distance
equal to the number under the peg, but not off either end of the row of numbers.
The goal is to move to the rightmost number.
*/

#include <iostream>
#include<vector>
using namespace std;

bool p_Junmp(vector<int>nums, int start) {
	int det=0;
	if (start == 0) return true;// start at 0 means reach the first number. So return True 
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == -10000);// if nums[i] has been used skip it and do nothing
		else {
			if (i < start) {
				if (nums[i] == start - i) {
					nums[i] = -10000;
					det=p_Junmp(nums, i);//if can jump from start to nums[i], start from i and mark it as used
					if (det == 1) return true;//if last cycle can solve problem return true
				}
			}
			else {
				if (nums[i] == i - start) {
					nums[i] = -10000;//if can jump from start to nums[i], start from i and mark it as used
					det=p_Junmp(nums, i);//if last cycle can solve problem return true
					if (det == 1) return true;
				}
			}
		}
	}
}

//function main start
int main()
{
	int n;
	int det = 1;
	vector<int>arr;
	cout << "Please input an array, each number should be positive and this array should end with 0" << endl;
	while (det) {
		cin >> n;
		if (n < 0)cout << "The number should >= 0" << endl;
		if (n >= 0)arr.push_back(n);
		if (n == 0)det = 0;
	}// Input the array
	if (p_Junmp(arr, arr.size() - 1)) cout << "Puzzle is solvable" << endl;
	else cout << "Puzzle is not solvable" << endl;
}
//function main end
