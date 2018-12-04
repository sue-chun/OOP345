// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Nov 21, 2018
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

#include <iostream>
#include <string>

class Utilities;
class Item;

struct ItemInfo {
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder {
	std::string m_name;
	std::string m_product;
	unsigned m_cntItem;
	ItemInfo** m_lstItem;
	static size_t m_widthField;
public:
	CustomerOrder();
	CustomerOrder(std::string& line);
	CustomerOrder(const CustomerOrder& src);
	CustomerOrder& operator=(const CustomerOrder& src) = delete;
	CustomerOrder(CustomerOrder&& src) noexcept; 
	CustomerOrder& operator=(CustomerOrder&& src);
	~CustomerOrder();

	bool getItemFillState(std::string it) const;
	bool getOrderFillState() const;
	void fillItem(Item& it, std::ostream& os);
	void display(std::ostream& os) const;
};

#endif