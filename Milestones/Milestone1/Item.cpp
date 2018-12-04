// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Nov 11, 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include <iostream>
#include <string>
#include <iomanip>

#include "Item.h"
#include "Utilities.h"

size_t Item::m_widthField = 0;		// important

Item::Item() {
	m_name = "";
	m_description = "";
	m_serialNumber = 0;
	m_quantity = 0;
}

Item::Item(const std::string & line) : Item() {
	Utilities obj;
	size_t pos = 0;
	bool more;
	try {
		m_name = obj.extractToken(line, pos, more);
		Item::m_widthField = obj.getFieldWidth();

		if (more)
			m_serialNumber = stoi(obj.extractToken(line, pos, more));
		if (more) 
			m_quantity = stoi(obj.extractToken(line, pos, more));
		if (more)
			m_description = obj.extractToken(line, pos, more);
	}
	catch (int) { Item(); };
}

const std::string & Item::getName() const {
	return m_name;
}

const unsigned Item::getSerialNumber() {
	return m_serialNumber++;
}

const unsigned Item::getQuantity() {
	return m_quantity;
}

void Item::updateQuantity() {
	if (m_quantity >= 1)
		m_quantity--;
	else
		m_quantity = 0;
}

void Item::display(std::ostream & os, bool full) const {
	os << std::left << std::setw(Item::m_widthField) << m_name
		<< " [" << std::right << std::setfill('0') << std::setw(6) << m_serialNumber << std::setfill(' ') << "]";
	if (full) {
		os << " Quantity: " << std::left << std::setw(Item::m_widthField) << m_quantity << "Description: " << m_description;
	}
	os << std::endl;
}
