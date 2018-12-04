// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Nov 11, 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include "Utilities.h"

char Utilities::m_delimiter = '\0';		// important

Utilities::Utilities(){
	m_widthField = 1;
}

void Utilities::setFieldWidth(size_t width) {
	m_widthField = width;
}

size_t Utilities::getFieldWidth() const {
	return m_widthField;
}

const std::string Utilities::extractToken(const std::string & str, size_t & next_pos, bool & more) {


	std::string token = str.substr(next_pos, (str.find(m_delimiter, next_pos)-next_pos)/*-next_pos*/);
	if (token.length() == 0) {
		more = false;
		throw 66; // havent figured out what type to throw yet 
	}

	if (next_pos != std::string::npos) {		// or can use just else 
		next_pos = str.find(m_delimiter, next_pos)+1;	// pos of spot after comma 
		more = true;
	}
	else
		more = false;

	if (Utilities::m_widthField < token.length())
		Utilities::m_widthField = token.length();


	

	return token;
}

void Utilities::setDelimiter(const char del) {
	m_delimiter = del;
}

const char Utilities::getDelimiter() const {
	return m_delimiter;
}
