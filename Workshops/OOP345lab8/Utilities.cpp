// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Nov 12 2018
//
// I confirm that the contents of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace w8
{
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
        for (size_t i = 0; i < desc.size(); ++i) {
            for (size_t j = 0; j < desc.size(); ++j) {
                if (desc[i].code == price[j].code) {    // to compare all possible combinations for common product code 
                    Product* rpList = new Product(desc[i].desc, price[j].price);
                    rpList->validate();
                    priceList += rpList;    // already takes in * and returns * on other side
                    delete rpList;
                }
            }
        }
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
        for (size_t i = 0; i < desc.size(); ++i) {
            for (size_t j = 0; j < desc.size(); ++j) {
                if (desc[i].code == price[j].code) {
                    std::unique_ptr<Product> spList(new Product(desc[i].desc, price[j].price));
                    spList->validate();
                    priceList += move(spList);  // needed to use move()
                }
            }
        }
		return priceList;
	}
}
