//Zelarous
//Artist.h

#ifndef MY_SECONDARY_INDEX_H
#define MY_SECONDARY_INDEX_H
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

class ArtistIndex{
private:
	class Node{
	public:

		string artist;
		int pos;
		Node* next;
		Node* prev;
		Node* up;
		Node* down;

		Node(): artist("N"), pos(-1), next(NULL), prev(NULL), up(NULL), down(NULL){}
		Node(string A, int P): artist(A), pos(P) {next = prev = up = down = NULL;}
	};

	Node* head;
	Node* tail;
	unsigned int size;

	void writeFile();
	void readFile();
	void killList();
	void delete_artist_by_artist();

public:
	ArtistIndex(){
		head = new Node(" ", -1);
		tail = new Node ("~", -1);
		head->next = tail;
		tail->prev = head;
		size = 0;
	}

	ArtistIndex(unsigned int InSize):size(InSize){
		head = new Node(" ", -1);
		tail = new Node ("~", -1);
		head->next = tail;
		tail->prev = head;
		readFile();
	}

	~ArtistIndex() { writeFile(); killList();}

	bool set_artist_pos(string A, int P);
	bool find_artist(string A, int& P);
	void change_artist(string oldArtist, string newArtist);
	void delete_artist(string A, int P);
	int delete_artist_by_artist(string A);
	bool delete_artist_by_position(int P);
	int find_artist_by_artist(string A);
	void addArtist(string A, int position);
	bool isEqual(string T, string T2);
	void debugOutput();
	void printByPosition(int position);
};

#endif
