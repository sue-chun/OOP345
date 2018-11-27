// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Sept 17 2018
//
// I confirm that the contents of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W3_TEXT_H
#define W3_TEXT_H

#include <iostream>
#include <cstring>
#include <string>

namespace w2 {
	class Text {
		std::string * mystr;
		size_t mycnt;
	public:
		Text(); // default constructor
		Text(const std::string& str);
		Text(const Text& other); // copy constructor 
		Text(Text&& other); // move constructor 
		size_t size() const; // returns number of records of text data 
		Text& operator=(const Text& other); // copy assignment 
		Text& operator=(Text&& other); // move assignment 
		~Text();
	};
}
#endif