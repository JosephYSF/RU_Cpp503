
// Name: Sifan Yuan
// Time: 10/12/2019
// Course: 16:332:503, Programming Finance

//Homework 6
/*
 Please implement the booklist assignment using classes.
 You can modify and reuse much of the code you wrote for 
 Homework 4, but make sure to implement the functions as 
 members of the class Booklist.
 The main function should create a new instance of the 
 Booklist class.
*/

#include <iostream>
#include<iomanip>
#include"Booklist_lastName.h"

using namespace std;
int ccc = 1;
int main()
{
	int choice, isbn, position;
	int det;
	int quit = 0;
	Booklist_lastName booklist;
	booklist.print();
	while (ccc==1) {
		booklist.printTable();
		cout << "your choice ---" << endl;
		cin >> choice;
		if (choice < 0 || choice>9)cout << "out of range!" << endl;
		else {
			switch (choice) {
			case 1:
				det = booklist.find_position(0, 0);
				if (det >= 0 && det != 8888) {
					cout << "Please type in the element:" << endl;
					cin >> isbn;
					if (isbn >= 1000000000 && isbn < 2147483647) {
						booklist.listCheck(isbn);
						booklist.insert(isbn, det);
						booklist.shiftList();
						booklist.print();
					}
					else cout << "Your ISBN is wrong." << endl;
				}
				else if (det == -1) {
					cout << "Your list is full!" << endl;
				}
				else cout << "error" << endl;
				break;
			case 2:
				det = booklist.find_position(0, 0);
				if (det >= 0 && det != 8888) {
					cout << "Please type in the element:" << endl;
					cin >> isbn;
					cout << "At what position? " << endl;
					cin >> position;
					if (position > 0 && position <= 20) {
						if (isbn >= 1000000000 && isbn <= 2147483647) {
							booklist.listCheck(isbn);
							booklist.shiftList();
							det = booklist.find_position(position - 1, 0);
							if (det == position - 1)booklist.insert(isbn, det);
							else if (det > position - 1 && det != 8888) booklist.insert_at(position - 1, det, isbn);
							else if (det == -1) {
								det = booklist.find_position(position - 1, 1);
								if (det < position - 1 && det >= 0) booklist.insert_at(position - 1, det, isbn);
								else if (det == -1)cout << "Your list is full!" << endl;
								else cout << "error" << endl;
							}
							booklist.shiftList();
							booklist.print();
						}
						else cout << "Your ISBN is wrong." << endl;
					}
					else cout << "Your position is out of range." << endl;
				}
				else if (det == -1) {
					cout << "Your list is full!" << endl;
				}
				else cout << "error" << endl;
				break;
			case 3:
				booklist.shiftList();
				booklist.print();
				cout << "Which element do you want to search? Please input a ISBN number." << endl;
				cin >> isbn;
				if (isbn >= 1000000000 && isbn <= 2147483647) {
					position = booklist.find_linear(isbn);
					if (position > 0)cout << "This book's position is " << position << "." << endl;
					else cout << "Can't find your book." << endl;
				}
				else cout << "Your ISBN is wrong." << endl;
				break;
			case 4:
				booklist.shiftList();
				booklist.print();
				det = booklist.sortCheck();
				if (det == 1) {
					cout << "Which element do you want to search? Please input a ISBN number." << endl;
					cin >> isbn;
					if (isbn >= 1000000000 && isbn <= 2147483647) {
						position = booklist.find_binary(isbn);
						if (position > 0)cout << "This book's position is " << position << "." << endl;
						else cout << "Can't find your book." << endl;
					}
					else cout << "Your ISBN is wrong." << endl;
				}
				else cout << "Your book list is unsorted, Please sort it before you use binary search" << endl;
				break;
			case 5:
				booklist.shiftList();
				booklist.print();
				cout << "Which book do you want to delete? Please input the position of this book" << endl;
				cin >> position;
				booklist.delete_item_position(position - 1);
				booklist.print();
				break;
			case 6:
				booklist.shiftList();
				booklist.print();
				cout << "Which book do you want to delete? Please input the ISBN of this book" << endl;
				cin >> isbn;
				booklist.delete_item_isbn(isbn);
				booklist.print();
				break;
			case 7:
				booklist.sort_list_selection();
				booklist.print();
				break;
			case 8:
				booklist.sort_list_bubble();
				booklist.print();
				break;
			case 9:
				booklist.print();
				break;
			case 0:
				quit = 1;
				break;
			default:
				break;
			}
			if (quit == 1)break;
		}
	}
	cout << "Thank you for using Book list program" << endl;
	return 0;
}
//end function main