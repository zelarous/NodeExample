//Zelarous
#include "Title.h"

using namespace std;

//kills whole list of nodes
void PrimaryIndex::killList(){
	Node* temp = head;
	Node* holder;

	while(temp != NULL){
		holder = temp;
		temp = temp->next;
		delete holder;
	}
	head = tail = NULL;
	size = 0;
}

//wrties to title.txt
void PrimaryIndex::writeFile(){
	Node* temp = head->next;

	ofstream fout("PrimaryIndex.txt");
	fout << size << endl;

	while(temp != tail){
		fout << temp->title << " " << temp->pos << endl;
		temp = temp->next;
	}

	fout.close();
	
}

//reads in title.txt
void PrimaryIndex::readFile(){
	Node* temp;
	Node* holder;
	string title;
	int position;

	ifstream fin("PrimaryIndex.txt");

	fin >> size;
	temp = head;

	for(unsigned int i = 0 ; i < size; i++){

		fin >> title >> position;
		holder = new Node(title, position);
		temp->next = holder;
		holder->prev = temp;
		tail->prev = holder;
		holder->next = tail;
		temp = temp->next;
	}

	fin.close();
}

bool PrimaryIndex::isEqual(string T, string T2){
	int count;

	if(T.length() != T2.length())
		return false;

	for(int i = 0; i < T.length() - 1; i++){
		if(tolower(T[i]) != tolower(T2[i])){
			return false;
		}
	}
	return true;
}

//attempt to add a title alphabetically
void PrimaryIndex::addTitle(string T, int P){
	Node* newNode = new Node(T, P);
	Node* temp;
	temp = head;

	//add in between head and tail if head and tail are the only nodes 
	if(temp->next == tail){
		head->next = newNode;
		tail->prev = newNode;
		newNode->prev = head;
		newNode->next = tail;
		size++;
		return;
	}//if

	//while temp->next does not equal tail, continue to traveeerse the list
	while(temp->next != tail){

		if(isEqual(T, temp->title)){
			cout << "Error: that title already exists \n \n";
			return;
		}

		//if T is less than the next title, place in between temp and temp ->next
		/*
		if(T < temp->next->title){
			newNode->prev = temp;
			newNode->next = temp->next->next;
			temp->next = newNode;
			temp->next->next->prev = newNode;
			size++;
			return;
		}//if
		*/
		temp = temp->next;
	}//while
	
	//if we made it to this point, nothing is greater than it, add to end of tail

	newNode->prev = tail->prev;
	newNode->next = tail;
	tail->prev->next = newNode;
	tail->prev = newNode;
	size++;
}//addTitle

void PrimaryIndex::debugOutput(){
	Node* temp;
	temp = head;
	int i =0;

	while(temp->next != tail){
		temp = temp->next;
		cout << temp->title << endl;
	}//while
	
}//debugOutput


//deletes title based on title given
int PrimaryIndex::delete_title_by_title(string T){
	int position = 0;
	Node* temp = head->next;

	while(temp != tail){
		if(temp->title == T){
			position = temp->pos;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
			size--;
			return position;
		}
		else
			temp = temp->next;
	}//while
	return position;
}

//deletes title based on position given
void PrimaryIndex::delete_title_by_position(int P){
	
	Node* temp = head->next;

	while(temp != tail){
		if(temp->pos == P){
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
			size--;
			return;
		}
		else
			temp = temp->next;
	}//while
	return;
}

//makes sure the title exists by given title
int PrimaryIndex::find_title_by_title(string T){
	
	Node* temp = head->next;
	int position = 0;

	while(temp != NULL){
		if(temp->title == T){
			position = temp->pos;
			return position; //exists
		}
        temp = temp->next;
	}
	return position; //doesn't exist
}


void PrimaryIndex::change_title(string old_title, string new_title){
	int exists;
	
	exists = find_title_by_title(old_title);

	if(exists > 0){
		Node* temp = head->next;

		while(temp->title != old_title){
			temp = temp ->next;
		}

		temp->title = new_title;
	}
	else
		cout << "That title does not exist." << endl << endl;
}

//deletes specified title
void PrimaryIndex::delete_title(string T, int P){

	if(P > 0){
		delete_title_by_position(P);
	}

	if(T.length() > 1){
		delete_title_by_title(T);
	}
	
	return;
}
