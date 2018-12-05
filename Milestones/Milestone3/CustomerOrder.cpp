// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Nov 21, 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#include <iostream>
#include <string>
#include <iomanip>

#include "CustomerOrder.h"
#include "Utilities.h"
#include "Item.h"

size_t CustomerOrder::m_widthField = 0;		// important

CustomerOrder::CustomerOrder() {
	m_name = "";
	m_product = "";
	m_cntItem = 0;
	m_lstItem = nullptr;
}

CustomerOrder::CustomerOrder(std::string& line) : CustomerOrder() {
	Utilities obj;
	size_t pos = 0;
	bool more = true;

	try {
		m_name = obj.extractToken(line, pos, more);

		if (more) 
			m_product= obj.extractToken(line, pos, more);
		
		size_t temp = pos;	// keep the position before getting size of dynamic array 

		do {	// to get size of the dynamic allocated array 
			std::string attempt = obj.extractToken(line, pos, more);
			m_cntItem++;
		} while (pos != 0);
		more = true;
		pos = temp;
		m_lstItem = new ItemInfo*[m_cntItem];	// dynamic allocated array of m_cntItem size 

		for (size_t i = 0; i < m_cntItem; ++i) {	// get value of each element in m_lstItem
			m_lstItem[i] = new ItemInfo(obj.extractToken(line, pos, more)); // constructor of ItemInfo receives string - so call the extractToken to get it 
		}

		if (obj.getFieldWidth() > CustomerOrder::m_widthField)
			CustomerOrder::m_widthField = obj.getFieldWidth();
	}
	catch (int) { CustomerOrder(); };
}

CustomerOrder::CustomerOrder(const CustomerOrder& src) {
	throw 66;
}

CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept : CustomerOrder() {
	*this = std::move(src);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) {
	if (this != &src) {
		for (size_t i = 0; i < m_cntItem; ++i) { // must delete each row first
			delete m_lstItem[i];
		}
		delete[] m_lstItem;

		m_cntItem = src.m_cntItem;
		m_lstItem = src.m_lstItem;
		m_product = src.m_product;
		m_name = src.m_name;

		//src = CustomerOrder();

		src.m_name = "";
		src.m_product = "";
		src.m_cntItem = 0;
		src.m_lstItem = nullptr;
	}
	return *this;
}

CustomerOrder::~CustomerOrder() {
	if (m_lstItem) {
		for (size_t i = 0; i < m_cntItem; ++i) { // must delete each row first
			delete m_lstItem[i];
		}
	}
	delete[] m_lstItem;
	m_lstItem = nullptr;
}

bool CustomerOrder::getItemFillState(std::string it) const {
	for (size_t i = 0; i < m_cntItem; ++i) {
		if (it == m_lstItem[i]->m_itemName)
			return m_lstItem[i]->m_fillState;
	}
	return true;
}

bool CustomerOrder::getOrderFillState() const {
	for (size_t i = 0; i < m_cntItem; ++i) {
		if (!m_lstItem[i]->m_fillState)
			return false;	
	}
	return true;
}

void CustomerOrder::fillItem(Item& it, std::ostream& os) {
	//std::cout << "item is: " << it.getName() << std::endl;
	for (size_t i = 0; i < m_cntItem; ++i) {
		//std::cout << "mlistItem[i]: " << m_lstItem[i]->m_itemName << std::endl;
		if (it.getName() == m_lstItem[i]->m_itemName) {
			//std::cout << "inside 1st if" << std::endl;
			if (it.getQuantity() >= 1) {
				//std::cout << "inside 2nd if" << std::endl;
				it.updateQuantity();
				m_lstItem[i]->m_serialNumber = it.getSerialNumber();
				m_lstItem[i]->m_fillState = true;
				os << "Filled " << m_name << ", "
					<< m_product << "[" << m_lstItem[i]->m_itemName 
					<< "]" << std::endl;
			}
			else {
				os << "Unable to fill " << m_name << ", "
					<< m_product << "[" << m_lstItem[i]->m_itemName
					<< "]" << std::endl;
			}
		}
	}
}

void CustomerOrder::display(std::ostream & os) const {
	os << m_name << " - " << m_product << std::endl;
	for (size_t i = 0; i < m_cntItem; ++i) {
		os << "[" << std::setfill('0') << std::setw(6) << std::right << m_lstItem[i]->m_serialNumber 
			<< std::setfill(' ') << "] " << std::left << std::setw(CustomerOrder::m_widthField) << m_lstItem[i]->m_itemName
			<< " - " << ((m_lstItem[i]->m_fillState) ? "FILLED" : "MISSING");
		os << std::endl;
	}
}





