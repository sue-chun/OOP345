//
//  TaxableProduct.cpp

// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Oct 31 2018
//
// I confirm that the contents of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <string>
#include "TaxableProduct.h"

namespace w6 {
    
    float TaxableProduct::taxCode[2] = {1.13, 1.08};
    // realized was doing 0.13 and 0.08 so total not adding up properly
    // did cout in main to check the total at each += looping to find the issue 
    
    TaxableProduct::TaxableProduct(std::string num, double cost, std::string tax) : Product::Product(num, cost) {
        prodTax = tax;
    }
    
    double TaxableProduct::getPrice() const {
        double noTaxPrice = Product::getPrice();
        return prodTax == "H" ? noTaxPrice * taxCode[0] : noTaxPrice * taxCode[1];
    }
    
    void TaxableProduct::display(std::ostream& os) const {
        Product::display(os); // call base class display to access the data members
        os << " " << (prodTax == "H" ? "HST" : "PST");
    }
}
