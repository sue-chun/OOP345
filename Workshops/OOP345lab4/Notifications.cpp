// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: 
//
// I confirm that the contents of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
//#include <fstream>
#include "Notifications.h"
#include "Message.h"

using namespace std;

namespace w4 {
    Notifications::Notifications() {
        count = 0;
        this->msg = new Message[max];
    }
    
    Notifications::Notifications(const Notifications& src) {    // copy constructor
        *this = src;
    }
    
    Notifications& Notifications::operator = (const Notifications& src) {     // copy assignment
        if (this != &src) {
            delete[]this->msg;
            this->count = src.count;
            this->msg = new Message[max];
            for (int i = 0; i < count; ++i)
                this->msg[i] = src.msg[i];
        }
        return *this;
    }
    
    Notifications::Notifications(Notifications&& src) {     // move constructor
        *this = move(src);
    }
    
    Notifications& Notifications::operator=(Notifications&& src) {  // move assignment
        if (this != &src) {
            this->count = src.count;
            src.count = 0;
            delete [] this->msg;
            this->msg = src.msg;
            src.msg = nullptr;
        }
        return *this;
    }
    
    Notifications::~Notifications() {
        delete[]this->msg;
    }

    void Notifications::operator+=(const Message& src) {
//        cout << "called +=" << endl;
        if (count < max) {
            msg[count] = src;
            count++;
        }
    }
    
    void Notifications::display(ostream& os) const {
        for (int i = 0; i < count; ++i)
            msg[i].display(os);
    }
}
