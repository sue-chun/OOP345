// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Sept 12 2018
//
// I confirm that the contents of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W1_CSTRING_H
#define W1_CSTRING_H

#include <iostream>
#include <cstring>

namespace w1 {
	class CString {
		const int max_chars; // probably 3? 
		char mystr[4];

	public:
		CString();
		CString(const char * str); // probably initialize the parameter to mystr
		void display(std::ostream&) const;
	};

	std::ostream& operator<<(std::ostream& os, const CString& cstr);
}

#endif