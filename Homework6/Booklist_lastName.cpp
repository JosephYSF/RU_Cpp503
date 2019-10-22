#include <iostream>
#include<iomanip>
#include"Booklist_lastName.h"
using namespace std;
int p = 1;

list Createlist(int size) {
	list l_re;
	int* l_test;
	l_test = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		*(l_test + i) = 0;
	}
	l_re.size = size;
	l_re.list = l_test;
	return l_re;
}
//Create a list which size==input. Full of element 0

Booklist_lastName::Booklist_lastName(){
	cout << "Welcome to the Book list program." << endl;
	mylist = Createlist(20);
}

int Booklist_lastName::find_position(int pos, int order) {
	int index = 8888;
	int i;
	if (order == 0) {
		for (i = pos; i < mylist.size; i++) {
			if (*(mylist.list + i) == 0) {
				index = i;
				break;
			}
		}
		if (i >= mylist.size) return -1;
		else return index;
	}
	else {
		for (i = pos - 1; i >= 0; i--) {
			if (*(mylist.list + i) == 0) {
				index = i;
				break;
			}
		}
		if (i < 0) return -1;
		else return index;
	}
}
//return;	8888 -error;	0~l.size -empty index;	-1 -fail to find an empty space
//order:	0 -pos to last;	1 -pos to first 

void Booklist_lastName::shiftList() {
	int i = 0;
	int j = 0;
	for (i = 0; i < mylist.size - 1 && j < mylist.size - 1; i++) {
		if (*(mylist.list + i) == 0) {
			for (int k = i; k < mylist.size - 1; k++) *(mylist.list + k) = *(mylist.list + k + 1);
			i--;
		}
		j++;
	}
	return;
}
//Shift the element in the list to the front

void Booklist_lastName::listCheck(int element) {
	for (int i = mylist.size - 1; i >= 0; i--) {
		if (*(mylist.list + i) == element) {
			*(mylist.list + i) = 0;
			break;
		}
	}
	return;
}
//Delete the first repeated element from mylist

void Booklist_lastName::insert(int new_element, int index) {
	*(mylist.list + index) = new_element;
	return;
}
//Cover element in index with new_element;

void Booklist_lastName::insert_at(int index, int empty_index, int new_element) {
	int i = 0;
	if (index < empty_index) {
		for (i = empty_index; i > index; i--) {
			*(mylist.list + i) = *(mylist.list + i - 1);
		}
	}
	else {
		for (i = empty_index; i < index; i++) {
			*(mylist.list + i) = *(mylist.list + i + 1);
		}
	}
	*(mylist.list + index) = new_element;
	return;
}
//Insert new_element to list l at index, push old elements to the direction of empty_index

int Booklist_lastName::sortCheck() {
	int result = 1;
	int det = find_position(0, 0);
	for (int i = 0; i < det - 1; i++) {
		if (*(mylist.list + i) > * (mylist.list + i + 1)) {
			result = 0;
			break;
		}
	}
	return result;
}
//return:	 0 -unsorted;	1 -sorted

int Booklist_lastName::find_linear(int element) {
	int result;
	int det;
	int i = 0;
	det = find_position(0, 0);
	for (i = 0; i < det; i++) {
		if (*(mylist.list + i) == element) {
			result = i;
			break;
		}
	}
	if (i == det) return -1;
	else if (i >= 0 && i < det) return result + 1;
	else return 8888;
}
//return:	-1 -fail to find;	0~l.size-1 -element place;	8888 -error

int Booklist_lastName::find_binary(int element) {
	int result;
	int det;
	int i = 0;
	det = find_position(0, 0);
	int low = 0;
	int high = det - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (*(mylist.list + mid) == element)
			return mid + 1;
		else if (*(mylist.list + mid) > element) high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}
//return:	-1 -fail to find;	0~l.size-1 -element place;

void Booklist_lastName::delete_item_position(int index) {
	if (index<0 || index>mylist.size - 1)cout << "out of range!" << endl;
	else {
		*(mylist.list + index) = 0;
		shiftList();
	}
	return;
}
//delete an element by position

void Booklist_lastName::delete_item_isbn(int element) {
	int pos = find_linear(element);
	if (pos != -1 && pos != 8888) delete_item_position(pos - 1);
	else if (pos == -1)cout << "Can't find this book." << endl;
	else cout << "error" << endl;
	return;
}
//delete an element by ISBN number

void Booklist_lastName::sort_list_selection() {
	shiftList();
	int index, temp;
	int det = find_position(0, 0);
	for (int i = 0; i < det; i++) {
		index = i;
		for (int j = i + 1; j < det; j++) {
			if (*(mylist.list + index) > * (mylist.list + j))
			{
				index = j;
			}
		}
		temp = *(mylist.list + index);
		*(mylist.list + index) = *(mylist.list + i);
		*(mylist.list + i) = temp;
	}
	return;
}
//using select sort to sort the list

void Booklist_lastName::sort_list_bubble() {
	shiftList();
	int temp;
	int flag = 1;
	int det = find_position(0, 0);
	for (int i = 0; i < det && flag; i++) {
		flag = 0;
		for (int j = i + 1; j < det; j++) {
			if (*(mylist.list + i) > * (mylist.list + j))
			{
				temp = *(mylist.list + i);
				*(mylist.list + i) = *(mylist.list + j);
				*(mylist.list + j) = temp;
				flag = 1;
			}
		}
	}
	return;
}
//using bubble sort to sort the list

void Booklist_lastName::print() {
	int j = mylist.size;
	cout << "Your list is now";
	for (int i = 0; i < mylist.size; i++) {
		if (*(mylist.list + i) != 0) {
			cout << "\n" << i + 1 << ". " << *(mylist.list + i);
			j--;
		}
	}
	if (j == mylist.size)cout << " empty.";
	cout << endl;
	return;
}
//print the list

void Booklist_lastName::printTable() {
	cout << "===========================================================" << endl;
	cout << "What would you like to do?" << endl;
	cout << "	" << "1. add an element to end of list" << endl;
	cout << "	" << "2. add an element at a location" << endl;
	cout << "	" << "3. find an element by ISBN number (linear search)" << endl;
	cout << "	" << "4. find an element by ISBN number (binary search)" << endl;
	cout << "	" << "5. delete an element at position" << endl;
	cout << "	" << "6. delete an element by ISBN number" << endl;
	cout << "	" << "7. sort the list (using selection sort)" << endl;
	cout << "	" << "8. sort the list (using bubble sort)" << endl;
	cout << "	" << "9. print the list" << endl;
	cout << "	" << "0. exit" << endl;
	cout << "===========================================================" << endl;
}
//print the table