// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Sept 17 2018 
//
// I confirm that the contents of this file is created by me,
// with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "Text.h"

using namespace std;

namespace w2 {
	Text::Text() {
		this->mycnt = 0;
		this->mystr = nullptr;
	}

	Text::Text(const string& str) {
		string lines;

		if (str != "") {
			ifstream fin(str);
			//			fin.open(mystr.c_str());

			if (fin.is_open()) {
				while (!fin.eof()) {
					getline(fin, lines);
					mycnt++;
				}
			}
			mystr = new string[mycnt];
		}
		else
			Text();
	}

	Text::Text(const Text& other) : mycnt(other.mycnt) { // copy constructor
		this->mystr = new string[mycnt];
		for (unsigned i = 0; i < mycnt; ++i) {
			this->mystr[i] = other.mystr[i];
		}
	}

	Text::Text(Text&& other) { // move constructor
//		*this = move(other);	// apparently this works too 
		this->mycnt = other.mycnt;
		this->mystr = other.mystr;
		other.mycnt = 0;
		other.mystr = nullptr;
		
	}

	size_t Text::size() const {
		return mycnt;
	}

	Text& Text::operator=(const Text& other) { // copy assignment
		if (this != &other) {
			delete[]this->mystr;
			this->mycnt = other.mycnt;
			this->mystr = new string[mycnt];
			for (unsigned i = 0; i < mycnt; ++i)
				this->mystr[i] = other.mystr[i];
		}
		return *this;
	}

	Text& Text::operator=(Text&& other) { // move assignment 
		if (this != &other) {
			this->mycnt = other.mycnt;
			other.mycnt = 0;
			delete[]this->mystr;   // need this or else memory leak (assuming it had memory assigned, but cant guarantee it didn't have memory assigned) 
			this->mystr = other.mystr;
			other.mystr = nullptr;
		}
		return *this;
	}

	Text::~Text() {
		delete[]this->mystr;
	}
}