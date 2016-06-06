//Zelarous
// C++ 
// Binary.cpp


#include "binary.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

//setters
void MyClass::set_title(std::string my_title){
	std::string strTitle(my_title);
	
	//set all characters to null in the title array
	for(int i = 0; i < 35; i++){
		title[i] = '\0';	
	}

	//fill title array with the strings' characters
	for(int i = 0; i < strTitle.length(); i++){
		title[i] = strTitle[i];
	}
}

void MyClass::set_artist(std::string my_artist){
	std::string strArtist(my_artist);
	
	//set all characters to null in the artist array
	for(int i = 0; i < 25; i++){
		artist[i] = '\0';	
	}

	//fill artist array with the strings' characters
	for(int i = 0; i < strArtist.length(); i++){
		artist[i] = strArtist[i];
	}

	
}

void MyClass::set_type(std::string my_type){
	std::string strType(my_type);

	//set all characters to null in the type array
	for(int i = 0; i < 12; i++){
		type[i] = '\0';	
	}

	//fill type array with the strings' characters
	for(int i = 0; i < strType.length(); i++){
		type[i] = strType[i];
	}
}

void MyClass::writeIt(std::fstream& out, long position)const{

	// set the write pointer to the correct position
	out.seekp(position * sizeof(MyClass));

	//writes data to binary file
	out.write((char*) this, sizeof(MyClass));

}

void MyClass::readIt(std::fstream& in, long position)const{
	
	//sets get pointer to the correct position
	in.seekg(position * sizeof(MyClass));
	//reads information from position in binary file
	in.read((char*) this, sizeof(MyClass));
}

void MyClass::set_year(int my_year){
	year = my_year;
}

void MyClass::set_price(int my_price){
	price = my_price;
}
 
void MyClass::set_count(int my_count){
	count = my_count;
}

void MyClass::set_flag(){
	dead_flag = true;
}

void MyClass::unset_flag(){
	dead_flag = false;
}


//getters

std::string MyClass::get_title(){
	std::string strTitle(title);

	return strTitle;
}

std::string MyClass::get_artist(){
	std::string strArtist(artist);

	return strArtist;
}

std::string MyClass::get_type(){
	std::string strType(type);
	
	return strType;
}

int MyClass::get_year() const{
	return year;
}

int MyClass::get_price() const{
	return price;
}

int MyClass::get_count() const{
	return count;
}

bool MyClass::get_flag() const{
	return dead_flag;
}

ostream& operator << (std::ostream& out, const MyClass& me){

	out << "Title: " << me.title << endl;
	out << "Artist: " << me.artist << endl;
	out << "Price: " << me.price << endl;
	out << "Year: " << me.year << endl;
	out << "Count: " << me.count << endl << endl;

	return out;
}
