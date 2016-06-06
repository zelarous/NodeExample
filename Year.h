//Seth Maize
//Year.h

#ifndef MY_SECONDARY_INDEXY_H
#define MY_SECONDARY_INDEXY_H
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>


using namespace std;

class YearIndex{
private:
	class Node{
	public:

		int year;
		int pos;
		Node* next;
		Node* prev;
		Node* up;
		Node* down;

		Node(): year(-1), pos(-1), next(NULL), prev(NULL), up(NULL), down(NULL){}
		Node(int Y, int P): year(Y), pos(P) {next = prev = up = down = NULL;}
	};

	Node* head;
	Node* tail;
	unsigned int size;

	void writeFile();
	void readFile();
	void killList();
	void delete_artist_by_artist();

public:
	YearIndex(){
		head = new Node(-100, -1);
		tail = new Node (-99, -1);
		head->next = tail;
		tail->prev = head;
		size = 0;
	}

	YearIndex(unsigned int InSize):size(InSize){
		head = new Node(-100, -1);
		tail = new Node (-99, -1);
		head->next = tail;
		tail->prev = head;
		readFile();
	}

	~YearIndex() { writeFile(); killList();}

	bool set_year_pos(int Y, int P);
	bool find_year(int Y, int& P);
	void change_year(int oldArtist, int newArtist);
	void delete_year(int Y, int P);
	bool delete_year_by_year(int Y);
	bool delete_year_by_position(int P);
	int find_year_by_year(int Y);
	void addYear(int Y, int position);
	bool isEqual(int T, int T2);
	void debugOutput();
};

#endif
