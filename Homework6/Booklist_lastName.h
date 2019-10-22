#pragma once
typedef struct {
	int size;
	int* list;
} list;

class Booklist_lastName {
public:
	Booklist_lastName();
	int find_position(int, int);
	void shiftList();
	void listCheck(int);
	void insert(int, int);
	void insert_at(int, int, int);
	int sortCheck();
	int find_linear(int);
	int find_binary(int);
	void delete_item_position(int);
	void delete_item_isbn(int);
	void sort_list_selection();
	void sort_list_bubble();
	void print();
	void printTable();
private:
	list mylist;
};