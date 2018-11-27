// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Oct 8 2018
//
// I confirm that the contents of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SICT_GRADES_H
#define SICT_GRADES_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

namespace sict {
    enum class Letter;
    template<typename T>
    const char * grds (const T& gr);
    
    class Grades {
        std::string * student;
        size_t mycnt;
        float * sgrades;
    public:
        Grades();
        Grades(char * srcf);
        
        template<typename F>
        void displayGrades(std::ostream& ostr, F func) const;
        
        Grades(const Grades& src) = delete; // copy constructor
        Grades& operator=(const Grades& src) = delete; // copy assignment
        Grades(Grades&& src) = delete; // move constructor
        Grades& operator=(Grades&& src) = delete; // move assignment
        ~Grades();
    };
    
    template<typename F>
    void Grades::displayGrades(std::ostream& ostr, F func) const {
        for (unsigned i = 0; i < mycnt; ++i) {
            ostr << std::right << std::setw(10) << student[i] << " "
            << std::left << std::setw(5) << std::setprecision(2) << std::fixed << sgrades[i] << " "
            << std::left << std::setw(4) << grds(func(std::round(sgrades[i]))) << std::endl;
        //    std::cout << grds(func(sgrades[i]));
        }
    }
}

#endif
