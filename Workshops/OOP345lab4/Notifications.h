// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: 
//
// I confirm that the contents of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W4_NOTIFICATIONS_H
#define W4_NOTIFICATIONS_H

#include <iostream>

namespace w4 {
    
    class Message;
    const int max = 10;
    
    class Notifications {
        Message * msg = nullptr; // a pointer
        int count;
    public:
        Notifications();
        
        Notifications(const Notifications& src);        // copy constructor
        Notifications& operator=(const Notifications& src); // copy assignment
        
        Notifications(Notifications&& src);             // move constructor
        Notifications& operator=(Notifications&& src); // move assignment
        
        ~Notifications();
        
        void operator+=(const Message& msg);
        void display(std::ostream& os) const;
    };
}
#endif
