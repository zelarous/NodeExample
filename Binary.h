//Zelarous
//Binary.h

#ifndef CLASS_H
#define CLASS_H
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

class MyClass{
	private:
		//previous were too small, and I recieved an error, had to change values for char size, seems to compile correctly
		char title[40], artist[40], type[40];
		int year, price, count, position;
		bool dead_flag;

	public:
		MyClass() : year(0), price(0), count(0), dead_flag(false)
		{
			strcpy_s(title, "0"); //remove "_s" for all non-VS compilers
			strcpy_s(artist, "0");
			strcpy_s(type, "0");
		}
		
		MyClass(std::string my_title, std::string my_artist, std::string my_type,
		int my_year, int my_price, int my_count, int my_position): year(my_year),
		price(my_price), count(my_count), position(my_position)
		{

			strcpy_s(title, my_title.c_str());
			strcpy_s(artist, my_artist.c_str());
			strcpy_s(type, my_type.c_str());
			
		}

		std::string get_title();
		std::string get_artist();
		std::string get_type();
		int get_year() const;
		int get_price() const;
		int get_count() const;
		bool get_flag() const;
		int get_value(std::fstream& inout); // for getting the value from zero record

		void set_title(std::string my_title);
		void set_artist(std::string my_artist);
		void set_type(std::string my_type);
		void set_year(int my_year);
		void set_price(int my_price);
		void set_count(int my_count);
		void set_value(std::fstream& inout, int value); //for setting zero record
		void set_flag();
		void unset_flag();

		//the next two methods write the object out to a file or fill it from a read activity. 
		//position and rread or position and write could be combined

		void writeIt(std::fstream& out, long position) const;
		void readIt(std::fstream& input, long position) const;
		void writeRecord();

		friend std:: ostream& operator<<(std::ostream& out, const MyClass& me);

};

#endif

