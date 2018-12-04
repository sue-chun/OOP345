// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Nov 11, 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <string>

class Utilities {
	size_t m_widthField;
	static char m_delimiter;
public: 
	Utilities();
	void setFieldWidth(size_t width); 
	size_t getFieldWidth() const;
	const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(const char del);
	const char getDelimiter() const;
};

#endif 
