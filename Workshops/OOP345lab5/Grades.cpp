// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Oct 8 2018
//
// I confirm that the contents of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <cmath>

#include "Grades.h"
#include "Letter.h"

namespace sict {
    Grades::Grades() : mycnt{0}{
        this->student = nullptr;
        this->sgrades = nullptr;
    }
    
    Grades::Grades(char * srcf) : Grades(){
        std::string lines;

        if (srcf != nullptr) {
            std::ifstream fin(srcf);

            if (fin.is_open()) {
                while (!fin.eof() && getline(fin, lines)) {
                    mycnt++;
                }
            }
            else {
                Grades();
                throw "No file";
            }
    //        fin.close();
        }
        this->student = new std::string[mycnt];
        this->sgrades = new float[mycnt];
        
        //
        if (srcf != nullptr) {
            std::ifstream fin2(srcf);
            if (fin2.is_open()) {
                //while (!fin2.eof()) {
                    for (unsigned i = 0; i < mycnt; i++) {
                        getline(fin2, lines);
                        student[i] = lines.substr(0, lines.find(" "));
                        sgrades[i] = std::stof(lines.substr(lines.find(" ")+1));
                  //      sgrades[i] = strtof((lines.substr(lines.find(" ")+1)).c_str(), NULL);
                        // this is for if have cstring instead of string 

                    }
               // }
            }
            //
        else {
            Grades();
            throw "No file";
        }
    }
        //
}
    
    Grades::~Grades() {
        delete [] student;
        student = nullptr;
        delete [] sgrades;
        sgrades = nullptr; 
    }
}
