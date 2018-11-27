//
//  ProdUtil.cpp

// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Oct 31 2018
//
// I confirm that the contents of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <string>
#include <fstream>
#include "ProdUtil.h"
#include "Product.h"
#include "TaxableProduct.h"

namespace w6 {
    std::ostream& operator<<(std::ostream& os, const iProduct& prod) {
        prod.display(os);
        os << std::endl;
        
        return os;          // this is probably good 
    }
    
    iProduct* readProduct(std::ifstream& ofs) {
        std::string lines;
        iProduct*item;
        getline(ofs, lines); // check here if positions are off
        if (ofs.eof())
            throw std::string("no such record! Reached the end of the file!");
        size_t pos1 = lines.find(' ');      // find first space
        std::string p_num = lines.substr(0, pos1);
        
        std::string p_price = lines.substr(pos1); //is everything after product number
        while (p_price[0] == ' ') {
            p_price = lines.substr(pos1);
            pos1++;
        }
        size_t pos2 = p_price.find(" ");  // find space between price and possibly tax
        double pprice = std::stod(p_price.substr(0, pos2));  // is the price (accidentally did int so was rounding all my numbers down)
        
        if (pos2 != std::string::npos) {    // means there is tax
            std::string p_tax = p_price.substr(pos2+1);
            if (p_tax != "H" && p_tax != "P")
                throw std::string("Unrecognizable Tax Code!");
            item = new TaxableProduct(p_num, pprice, p_tax); // remember use new for dynamic type
        }
        else {
            item = new Product(p_num, pprice); // remember use new for dynamic type 
        }
        return item;
    }
}
