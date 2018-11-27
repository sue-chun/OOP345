// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: 
//
// I confirm that the contents of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
//#include <fstream>
#include "Message.h"

using namespace std;

namespace w4 {
    Message::Message() {
        myMsg = "";
        myUser = "";
        tweet = "";
        reply = "";
        tweet2 = "";
        pos1 = 0;
        pos2 = 0;
    }
    
    Message::Message(ifstream& in, char c) {
        getline(in, myMsg, c);
        pos1 = myMsg.find(" ");
        myUser = myMsg.substr(0,pos1);      // found first space
        if (pos1 != string::npos)
            tweet = myMsg.substr(pos1);     // substring starting from end of username
        else
            tweet = '\0';
        
        pos2 = tweet.substr(1).find(" ");   // skip the @ and find next space
        if (tweet.substr(1,1) == "@" && pos2 != string::npos) {
            reply = myMsg.substr(pos1+2, pos2-1);
            tweet = myMsg.substr(pos1+pos2+2);
        }
        else
            reply = '\0';
     }
    
    bool Message::empty() const {
        if (myMsg == "")
            return true;
        else
            return false;
    }
    
    void Message::display(ostream& os) const {
        string pick1 = myMsg.substr(pos1+1,1);
    
        if (pick1 == "@" && pos1 != string::npos) {
            os << "Message" << endl;
            os << " User  : " << myUser << endl;
            os << " Reply : " << reply << endl;
            os << " Tweet : " << tweet << endl << endl;
        }
        else if (pos1 != string::npos){
            os << "Message" << endl;
            os << " User  : " << myUser << endl;
            os << " Tweet :" << tweet << endl << endl;
        }
    }
}
