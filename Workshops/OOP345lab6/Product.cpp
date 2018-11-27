//
//  Product.cpp

// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Oct 31 2018
//
// I confirm that the contents of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include<iostream>
#include<iomanip>
#include<string>
#include "Product.h"

namespace w6 {
    Product::Product(std::string num, double cost) {
        prodNum = num;
        prodCost = cost;
    }
    
    double Product::getPrice() const {
        return prodCost;
    }
    
    void Product::display(std::ostream& os) const {
        static int i = 0;
        os << std::setw(16) << prodNum
        << std::setw(16) << prodCost;
        i++;
    }
}
