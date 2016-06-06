//Zelarous
//Year.cpp

#include "Year.h";

using namespace std;

void YearIndex::writeFile(){

	Node* temp = head;
	Node*temp2;
	
	ofstream fout("Year.txt");
	fout << size << endl;

	while(temp->next != tail){
		temp = temp->next;
		temp2 = temp;
		
		while(temp2->down != NULL){
			temp2 = temp->down;
		}
		
		while(temp2->up != NULL){
			fout << temp2->year << endl;
			temp2 = temp2->up;
		}
	fout << temp->year << " " << temp->pos << endl;
	}

	fout.close();
}//write file


void YearIndex::killList(){
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


//add year, in order 
void YearIndex::addYear(int Y, int P){
	Node* newNode = new Node(Y, P);
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
		
		
		if(Y == temp->year){
			while(temp->down != NULL){
				temp = temp->down;
			}//while
			temp->down = newNode;
			newNode->up = temp;	
			size++;
			return;
		}//if
		

		//if Y is less than the next year, place in between temp and temp ->next
		/*
		if(Y < temp->next->year){
			
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

void YearIndex::debugOutput(){
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
			cout << temp2->year << endl;
			temp2 = temp2->up;
		}
		cout << temp->year << endl;
	}//while
}//debugOutput

bool YearIndex::delete_year_by_year(int year)
{
	Node* temp = head->next;
	Node* temp2; 
	Node* holder;

	while(temp != tail)
	{
		if(year == temp->year)
		{
			if(temp->down != NULL)
			{
				temp2 = temp->down;
				while(temp2->down != NULL)
					temp2 = temp2->down;
				while(temp2->up != NULL)
				{
					// call binary file with pos to delete record
					holder = temp2;
					temp2 = temp2->up;
					delete holder;
				}
			}
			// call binary file with pos to delete record
			holder = temp;
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			delete holder;
			return true;
		}
		temp = temp->next;
	}
	return false;
}

bool YearIndex::delete_year_by_position(int P){
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
}//delete_year_by_year

int YearIndex::find_year_by_year(int year){
	Node* temp = head->next;
	int position = 0;

	while(temp != NULL){
		if(temp->year == year){
			position = temp->pos;
			return position; //exists
		}
        temp = temp->next;
	}
	return position; //doesn't exist
}
