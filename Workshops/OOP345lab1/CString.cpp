// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Sept 12 2018
//
// I confirm that the contents of this file is created by me,
// with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "CString.h"

using namespace std;

int stored = 3;

namespace w1 {
	CString::CString() : max_chars{ 0 }, mystr{ '\0' } {
	}

	CString::CString(const char * str) : max_chars{ stored } {
		if (str != nullptr) {
			strncpy(mystr, str, max_chars);
			mystr[max_chars] = '\0';
//			cout << mystr;
		}
		else
			mystr[0] = '\0';
	}


	void CString::display(std::ostream& os) const {
		os << mystr;
	}

	std::ostream& operator<<(std::ostream& os, const CString& cstr) {
		static int count = 0;
		os << count++ << ": ";
		cstr.display(os);
		return os;
	}
}




