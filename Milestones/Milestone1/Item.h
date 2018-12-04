// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Nov 11, 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Utilities;

class Item {
	std::string m_name;
	std::string m_description;
	unsigned m_serialNumber;
	unsigned m_quantity;
	static size_t m_widthField;	
public:
	Item();
	Item(const std::string& line);
	const std::string& getName() const;
	const unsigned getSerialNumber();
	const unsigned getQuantity();
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
};

#endif 
