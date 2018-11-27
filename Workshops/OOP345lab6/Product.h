//
//  Product.hpp

// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Oct 31 2018
//
// I confirm that the contents of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W6_PRODUCT_H
#define W6_PRODUCT_H

#include <iostream>
#include<string>

#include "iProduct.h"

namespace w6 {
    class Product : public iProduct {
        std::string prodNum; // dont need to make into int
        double prodCost; // double instead of float because functions are returning doubles 
    public:
        Product(std::string num, double cost);
        double getPrice() const;
        void display(std::ostream&) const;
    };
}

#endif 
