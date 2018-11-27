// iProduct.h

// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Oct 31 2018
//
// I confirm that the contents of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W6_IPRODUCT_H
#define W6_IPRODUCT_H
#include <fstream>

namespace w6
{
    class iProduct
    {
    public:
        virtual double getPrice() const = 0;
        virtual void display(std::ostream&) const = 0;
    };
}
#endif
