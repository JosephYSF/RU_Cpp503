// Name: Sifan Yuan
// Time: 09/20/2019
// Course: 16:332:503, Programming Finance

//In Class Assignment 3
/*
The Rutgers Student Council (RSC) is conducting a poll of who should be
the next apprentice. There are 5 candidates to choose from. The RSC has 
polled 20 students on campus. You need to write a program that tallies 
up the number of votes each candidate received and pronounces a winner.
*/

#include <iostream>

using namespace std;
//function main begins
	int main()
	{
		int c[5] = { 0 };// Array c to count the votes of each candidate.
		int v[20];// Array v to record each student's choice.
		int i, temp, temp_value;
		int j = 0;
		int vote;
		char x;//Variable used to make sure the student vote for the right one.
		for (int n = 0;n < 20;n++) {
			while (j == 0) {
				cout << "\nPlease vote for your candidate, Student No." << n + 1 << ":\n(Input number 1 to 5)\n";
				cin >> vote;
				if (vote > 5 || vote < 1) {
					cout << "The input must be number 1 to 5!\nPlease input again!";
					continue;
				}
				cout << "\nAre you sure to vote for candidate " << vote << "?\nPlease input y to end your proccess:\n(Any other input will restart your vote!)\n";
				cin >> x;
				if (x == 'y')break;
				else cout << "You can make your choice again!";
			}//Get the student's choice.
			v[n] = vote;
			c[vote - 1] += 1;//Give the one who be choosed 1 more vote.
		}
		temp_value = c[0];
		temp = 0;
		for (i = 0;i < 4;i++) {
			if (temp_value < c[i + 1]) {
				temp = i + 1;
				temp_value = c[i + 1];
			}
		}//Find out the candidate who recive the most of the votes and the number of the votes he recive.
		for (i = 0;i < 5;i++) {
			if (c[i] == temp_value) j++;
			if (j >= 2) {
				cout << "There are more than 1 people who have the same highest vote counts. No winner!";
				return 0;
			}
		}//Make sure there are no more than 1 people get the same highest vote counts.
		cout << "\nThe winner is candidate " << temp + 1 << ".\n" << temp_value << " people vote for this candidate.";
		return 0;
	}
	/*while(j==0){
		cout<<"Anyone want to change his/her choice?\nPlease input your number to change your choice or input q to end this process.\n";
		cin>>x;
		if(x=='q')break;
		else{
			int X=(int)x;
			if(X<1||X>20)cout<<"\nOut of range!\n";
			else{
				temp=v[X-1];
				c[temp-1]-=1;
				cout<<"Your last choice is candidate "<<temp<<".\nWhich one do you want to choose now?\n";
				cin>>vote;
				c[vote-1]+=1;
			}
		}*/ //indicate that program ended successfully
//end function main
