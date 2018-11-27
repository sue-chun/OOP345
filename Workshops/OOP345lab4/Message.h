// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion:
//
// I confirm that the contents of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W4_MESSAGE_H
#define W4_MESSAGE_H

#include <iostream>
#include <string>
#include <fstream>

namespace w4 {
    class Message {
        std::string myMsg;
        std::string myUser;
        std::string tweet;
        std::string reply;
        std::string tweet2;
        size_t pos1;
        size_t pos2;
    public:
        Message();
        Message(std::ifstream& in, char c);
        bool empty() const;
        void display(std::ostream& os) const;
    };
}
#endif 
