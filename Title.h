//Seth Maize

#ifndef TITLE_H
#define TITLE_H
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cctype>

using namespace std;

class PrimaryIndex{
	
private:	
	class Node{
	public:
		string title;
		int pos;
		Node* next;
		Node* prev;
		Node():title("no"), pos(-1), next(NULL), prev(NULL) {}
		Node(string T, int P): title(T), pos(P), next(NULL), prev(NULL) {}
	};

	Node* head;
	Node* tail;
	unsigned int size;

	void writeFile();
	void readFile();
	void killList();

public:
	PrimaryIndex(){
		head = new Node(" ", -1);
		tail = new Node ("~", -1);
		head->next = tail;
		tail->prev = head;
		size = 0;
	}

	PrimaryIndex (unsigned int InSize):size(InSize){
		head = new Node(" ", -1);
		tail = new Node ("~", -1);
		head->next = tail;
		tail->prev = head;
		readFile();
	}

	~PrimaryIndex() {writeFile(); killList();}

	bool set_title_pos(string T, int P);
	bool find_title(string T, int& P);
	void change_title(string oldPrimaryIndex, string newPrimaryIndex);
	void delete_title(string T, int P);
	int find_title_by_title(string T);
	void addTitle(string T, int P);
	void debugOutput();
	bool isEqual(string T, string T2);
	bool isLessThan(string T, string T2);
	int delete_title_by_title(string T);
	void delete_title_by_position(int P);
};

#endif
