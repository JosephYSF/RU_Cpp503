// Name: Sifan Yuan
// Time: 09/27/2019
// Course: 16:332:503, Programming Finance

//Homework 4
/*
Arrays and vectors can be used to hold lists.  For 
this homework assignment, you will be making a book 
list program. Write a program to support the following 
functions on a book list. You can assume that you will
not be buying more than 20 books:
*/



#include <iostream>
#include<iomanip>

using namespace std;
int p = 1;
typedef struct {
	int size;
	int* list;
} list;

int find_position(list l,int pos,int order) {
	int index = 8888;
	int i;
	if (order == 0) {
		for (i = pos; i < l.size; i++) {
			if (*(l.list+i) == 0) {
				index = i;
				break;
			}
		}
		if (i >= l.size) return -1;
		else return index;
	}
	else {
		for (i = pos - 1; i >= 0; i--) {
			if (*(l.list + i) == 0) {
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

void shiftList(list l) {
	int i = 0;
	int j = 0;
	for (i = 0; i < l.size-1&&j<l.size-1; i++) {
		if (*(l.list + i) == 0) {
			for (int k = i; k < l.size-1;k++) *(l.list + k) = *(l.list + k+1);
			i--;
		}
		j++;
	}
	return;
}
//Shift the element in the list to the front

void listCheck(list l, int element) {
	for (int i= l.size-1; i >=0; i--) {
		if (*(l.list + i) == element) {
			*(l.list + i) = 0;
			break;
		}
	}
	return;
}
//Delete the first repeated element from list l

list Createlist(int size) {
	list l_re;
	int* l_test;
	l_test = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		*(l_test+i) = 0;
	}
	l_re.size = size;
	l_re.list = l_test;
	return l_re;
}
//Create a list which size==input. Full of element 0

void insert(list l, int new_element,int index) {
	*(l.list+index) = new_element;
	return;
}
//Cover element in index with new_element;

void insert_at(list l, int index, int empty_index, int new_element) {
	int i=0;
	if (index < empty_index) {
		for (i = empty_index; i > index; i--) {
			*(l.list + i) = *(l.list + i-1);
		}
	}
	else {
		for (i = empty_index; i < index; i++) {
			*(l.list + i) = *(l.list + i+1);
		}
	}
	*(l.list + index) = new_element;
	return;
}
//Insert new_element to list l at index, push old elements to the direction of empty_index

int sortCheck(list l) {
	int result = 1;
	int det = find_position(l, 0, 0);
	for (int i = 0; i < det-1; i++) {
		if (*(l.list + i) > * (l.list + i+1)) {
			result = 0;
			break;
		}
	}
	return result;
}
//return:	 0 -unsorted;	1 -sorted

int find_linear(list l, int element) {
	int result;
	int det;
	int i = 0;
	det = find_position(l, 0, 0);
	for (i = 0; i < det; i++) {
		if (*(l.list + i) == element) {
			result = i;
			break;
		}
	}
	if (i == det) return -1;
	else if (i >= 0 && i < det) return result + 1;
	else return 8888;
}
//return:	-1 -fail to find;	0~l.size-1 -element place;	8888 -error

int find_binary(list l, int element) {
	int result;
	int det;
	int i = 0;
	det = find_position(l, 0, 0);
	int low = 0;
	int high = det - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (*(l.list + mid) == element)
			return mid+1;
		else if (*(l.list + mid) > element) high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}
//return:	-1 -fail to find;	0~l.size-1 -element place;

void delete_item_position(list l, int index) {
	if (index<0 || index>l.size - 1)cout << "out of range!" << endl;
	else {
		*(l.list + index) = 0;
		shiftList(l);
	}
	return;
}
//delete an element by position

void delete_item_isbn(list l, int element) {
	int pos = find_linear(l, element);
	if (pos != -1 && pos != 8888) delete_item_position(l, pos-1);
	else if (pos == -1)cout << "Can't find this book." << endl;
	else cout << "error" << endl;
	return;
}
//delete an element by ISBN number

void sort_list_selection(list l) {
	shiftList(l);
	int index,temp;
	int det = find_position(l, 0, 0);
	for (int i = 0; i < det; i++) {
		index = i;
		for (int j = i+1; j < det; j++) {
			if (*(l.list + index) > * (l.list + j))
			{
				index = j;
			}
		}
		temp = *(l.list + index);
		*(l.list + index) = *(l.list + i);
		*(l.list + i) = temp;
	}
	return;
}
//using select sort to sort the list

void sort_list_bubble(list l) {
	shiftList(l);
	int temp;
	int flag = 1;
	int det = find_position(l, 0, 0);
	for (int i = 0; i < det && flag; i++) {
		flag = 0;
		for (int j = i + 1; j < det; j++) {
			if (*(l.list + i) > * (l.list + j))
			{
				temp = *(l.list + i);
				*(l.list + i) = *(l.list + j);
				*(l.list + j) = temp;
				flag = 1;
			}
		}
	}
	return;
}
//using bubble sort to sort the list

void print(list l) {
	int j=l.size;
	cout << "Your list is now";
	for (int i = 0; i < l.size; i++) {
		if (*(l.list + i) != 0) {
			cout << "\n" << i + 1 << ". " << *(l.list + i);
			j--;
		}
	}
	if (j == l.size)cout << " empty.";
	cout << endl;
	return ;
}
//print the list

//function main begins   
int main()
{
	int choice, isbn, position;
	int det;
	int quit = 0;
	cout << "Welcome to the Book list program." << endl;
	list mylist = Createlist(20);
	print(mylist);
	while (p == 1) {
		cout << "==========================================================="<<endl;
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
		cout << "your choice ---" << endl;
		cin >> choice;
		if (choice < 0 || choice>9)cout << "out of range!" << endl;
		else {
			switch (choice) {
			case 1:
				det = find_position(mylist,0,0);
				if (det >= 0 && det != 8888) {
					cout << "Please type in the element:" << endl;
					cin >> isbn;
					if (isbn >= 1000000000 && isbn < 2147483647) {
						listCheck(mylist, isbn);
						insert(mylist, isbn, det);
						shiftList(mylist);
						print(mylist);
					}
					else cout << "Your ISBN is wrong." << endl;
				}
				else if (det == -1) {
					cout << "Your list is full!" << endl;
				}
				else cout << "error" << endl;
				break;
			case 2:
				det = find_position(mylist, 0,0);
				if (det >= 0 && det != 8888) {
					cout << "Please type in the element:" << endl;
					cin >> isbn;
					cout << "At what position? " << endl;
					cin >> position;
					if (position > 0 && position <= mylist.size) {
						if (isbn >= 1000000000 && isbn <= 2147483647) {
							listCheck(mylist, isbn);
							shiftList(mylist);
							det = find_position(mylist, position - 1,0);
							if (det == position - 1)mylist.list[det] = isbn;
							else if (det > position - 1 && det != 8888) insert_at(mylist, position - 1, det, isbn);
							else if (det == -1) {
								det = find_position(mylist, position - 1, 1);
								if (det < position - 1 && det >= 0) insert_at(mylist, position - 1, det, isbn);
								else if(det == -1)cout << "Your list is full!" << endl;
								else cout << "error" << endl;
							}
							shiftList(mylist);
							print(mylist);
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
				shiftList(mylist);
				print(mylist);
				cout << "Which element do you want to search? Please input a ISBN number." << endl;
				cin >> isbn;
				if (isbn >= 1000000000 && isbn <= 2147483647) {
					position = find_linear(mylist, isbn);
					if (position > 0)cout << "This book's position is " << position << "." << endl;
					else cout << "Can't find your book." << endl;
				}
				else cout << "Your ISBN is wrong." << endl;
				break;
			case 4:
				shiftList(mylist);
				print(mylist);
				det = sortCheck(mylist);
				if (det == 1) {
					cout << "Which element do you want to search? Please input a ISBN number." << endl;
					cin >> isbn;
					if (isbn >= 1000000000 && isbn <= 2147483647) {
						position = find_binary(mylist, isbn);
						if (position > 0)cout << "This book's position is " << position << "." << endl;
						else cout << "Can't find your book." << endl;
					}
					else cout << "Your ISBN is wrong." << endl;
				}
				else cout << "Your book list is unsorted, Please sort it before you use binary search" << endl;
				break;
			case 5:
				shiftList(mylist);
				print(mylist);
				cout << "Which book do you want to delete? Please input the position of this book" << endl;
				cin >> position;
				delete_item_position(mylist, position-1);
				print(mylist);
				break;
			case 6:
				shiftList(mylist);
				print(mylist);
				cout << "Which book do you want to delete? Please input the ISBN of this book" << endl;
				cin >> isbn;
				delete_item_isbn(mylist, isbn);
				print(mylist);
				break;
			case 7:
				sort_list_selection(mylist);
				print(mylist);
				break;
			case 8:
				sort_list_bubble(mylist);
				print(mylist);
				break;
			case 9:
				print(mylist);
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
