// Name: Sifan Yuan
// Time: 09/13/2019
// Course: 16:332:503, Programming Finance

//In Class Assignment 2_Diamond
/*write another program to print out a hollow diamond shape. 
You need to ask the user to input a maximum number of spaces
in each line. In the diamond shape, the input maximum number 
should be odd. If the user doesn't enter an odd number, tell
him/her to enter an odd number. 
*/

#include <iostream>
using namespace std;

//function main begins
int main()
{
	int spc;//used as input
	int n, m, l;
	for(int temp=0;;){
		cout<<"Please input the maximum number of spaces in each line(must be odd):\n";
		cin>>spc;
		if(spc%2==0) cout<<"Please enter an odd number!\n\n";
		else break;
	}//program only continue when the input number is odd!
	/*cout << "Please input the maximum number of spaces in each line(must be odd):\n";
	cin >> spc;
	if (spc % 2 == 0) {
		cout << "Please enter an odd number!";
		return 0;
	}
	*/
	for (n = 0;n < (spc + 1) / 2;n++) {
		cout << " ";
	}
	cout << "*\n";//the first "*"
	l = 0;
	for (m = 1;m <= spc;m += 2) {
		for (n = 1;n < (spc + 1) / 2 - l;n++) {
			cout << " ";
		}
		l++;
		cout << "*";
		for (n = 0;n < m;n++) {
			cout << " ";
		}
		cout << "*\n";
	}//increase of spaces;
	l = (spc + 1) / 2 - 1;
	for (m = spc - 2;m > 0;m -= 2) {
		for (n = 0;n < (spc + 1) / 2 - l;n++) {
			cout << " ";
		}
		l--;
		cout << "*";
		for (n = 0;n < m;n++) {
			cout << " ";
		}
		cout << "*\n";
	}//decrease of spaces;
	for (n = 0;n < (spc + 1) / 2;n++) {
		cout << " ";
	}
	cout << "*\n";//the last "*"
	return 0; //indicate that program ended successfully

}//end function main