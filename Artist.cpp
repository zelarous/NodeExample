//Zelarous
#include "Artist.h"


using namespace std;

void ArtistIndex::writeFile(){

	Node* temp = head;
	Node*temp2;
	
	ofstream fout("Artist.txt");

	while(temp->next != tail){
		temp = temp->next;
		temp2 = temp;
		
		while(temp2->down != NULL){
			temp2 = temp->down;
		}
		
		while(temp2->up != NULL){
			fout << temp2->artist << endl;
			temp2 = temp2->up;
		}
		fout << temp->artist << " " << temp->pos << endl;
	}

	fout.close();
}//write file


void ArtistIndex::killList(){
	Node* temp = head;
	Node* temp2 = NULL;
	Node* holder;

	while(temp != NULL){
	
		temp2 = temp;

		while(temp2->down != NULL)
			temp2 = temp2->down;
		
		while(temp2->up != NULL){
			holder = temp2;
			temp2 = temp2->up;
			delete holder;
		}//while
		holder = temp;
		temp = temp->next;
		delete holder;
	}//while
	return;
}//killList

//attempt to add a artist alphabetically
void ArtistIndex::addArtist(string A, int P){
	Node* newNode = new Node(A, P);
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
		
		
		if(isEqual(A, temp->artist)){
			while(temp->down != NULL){
				temp = temp->down;
			}//while
			temp->down = newNode;
			newNode->up = temp;	
			size++;
			return;
		}//if
		

		//if A is less than the next artist, place in between temp and temp ->next
		/*
		if(A < temp->next->artist){
			
			newNode->prev = temp;
			newNode->next = temp->next->next;
			temp->next = newNode;
			temp->next->next->prev = newNode;
			cout << "temp " << temp->artist << " temp->next " << temp->next->artist << endl;
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

bool ArtistIndex::isEqual(string A, string A2){
	int count;

	if(A.length() != A2.length())
		return false;

	for(int i = 0; i < A.length() - 1; i++){
		if(tolower(A[i]) != tolower(A2[i])){
			return false;
		}
	}
	return true;
}

void ArtistIndex::debugOutput(){
	Node* temp;
	Node* temp2;
	temp = head;
	
	while(temp->next != tail){
		temp = temp->next;
		temp2 = temp;

		while(temp2->down != NULL){
			temp2 = temp2->down;
		}//while

		while(temp2->up != NULL){
			cout << temp2->artist << endl;
			temp2 = temp2->up;
		}
		cout << temp->artist << endl;
	}//while
}//debugOutput

//NOT: Origninally this function deleted ALL of the artists at once, I had to modify it because I knew no other way of making it work with title,
//year, wauntity, etc ( I tried pointer arrays but that resulted in an error), NEW NOTE: think i could make it better but I am running out of time
int ArtistIndex::delete_artist_by_artist(std::string del_artist)
{
	Node* temp = head->next;
	Node* temp2; 
	Node* holder;
	int position;

	while(temp != tail)
	{
		if(del_artist == temp->artist)
		{		
			temp2 = temp;

				while(temp2->down != NULL)
					temp2 = temp2->down;
				
				if(temp2->up != NULL)
				{
					// call binary file with pos to delete record
					holder = temp2;
					position = temp2->pos;
					temp2 = temp2->up;
					temp2->down = NULL;
					delete holder;
					size--;
					return position;
			}
			// call binary file with pos to delete record
			holder = temp;
			position = temp->pos;
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			delete holder;
			size--;
			return position;
		}
		temp = temp->next;
	}
	return false;
}

bool ArtistIndex::delete_artist_by_position(int P){
	Node* temp = head->next;
	Node*temp2 = NULL;
	Node* holder;

	while(temp != NULL){
		
		temp2 = temp;

		//if initial (top layer) is equal to position
		if(temp2->pos == P){
			//if nothing is below the node
			if(temp->down == NULL){
				holder = temp2;
				temp2->prev->next = temp2->next;
				temp2->next->prev = temp2->prev;
				delete holder;
				return true;
			}//if
			
			//if there are more nodes below this initial node
			else{
				holder = temp2;
				temp2->down->next = temp2->next;
				temp2->down->prev = temp2->prev;
				temp2->prev->next = temp->down;
				temp2->next->prev = temp2->down;
				temp2->down->up = NULL;
				delete temp2;
				return true;
			}//else
		}//if

		while(temp2->down != NULL){
			temp2 = temp2->down;

			//if node is equal to position 
			if(temp2->pos == P){
				//if node has another node below it
				if(temp2->down != NULL){
					holder = temp2;
					temp2->down->up = temp2->up;
					temp2->up->down = temp2->down;
					delete holder;
					return true;
				}//if
				//if there is no node below this node
				if(temp2->down == NULL){
					holder = temp2;
					temp2->up->down = NULL;
					delete holder;
					return true;
				}
			}//if
		}//while
		temp = temp->next;
	}//while
	return false;
}//delete_year_by_artist
