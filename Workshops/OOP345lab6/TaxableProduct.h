//
//  TaxableProduct.hpp

// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Oct 31 2018
//
// I confirm that the contents of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W6_TAXABLEPRODUCT_H
#define W6_TAXABLEPRODUCT_H

#include <string>
#include "Product.h"

namespace w6 {
    class TaxableProduct : public Product {
        static float taxCode[2];
        std::string prodTax;
    public:
        TaxableProduct(std::string num, double cost, std::string tax);
        double getPrice() const;
        void display(std::ostream&) const;
    };
}

#endif 
