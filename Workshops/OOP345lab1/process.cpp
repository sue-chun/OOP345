// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Sept 12 2018
//
// I confirm that the contents of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <cstring>
#include "CString.h"
#include "process.h"

using namespace std;

void process(const char * str, std::ostream & os) {
	w1::CString cObj(str);
	os << cObj << endl;
}
