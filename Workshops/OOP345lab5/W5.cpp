// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Oct 8 2018
//
// I confirm that the contents of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {
    
    std::cout << "Command Line: ";
    for (int i = 0; i < argc; i++)
        std::cout << argv[i] << ' ';
    std::cout << std::endl;
    
    if (argc == 1) {
        std::cerr << "\n*** Insufficient number of arguments ***\n";
        std::cerr << "Usage: " << argv[0] << " fileName \n";
        return 1;
    }
    else if (argc != 2) {
        std::cerr << "\n*** Too many arguments ***\n";
        std::cerr << "Usage: " << argv[0] << " fileName \n";
        return 2;
    }
    auto letter = [](float gr) -> Letter {
        if (gr >= 90)
            return Letter::Ap;
        else if (gr >= 80 && gr <= 89)
            return Letter::A;
        else if (gr >= 75 && gr <= 79)
            return Letter::Bp;
        else if (gr >= 70 && gr <= 74)
            return Letter::B;
        else if (gr >= 65 && gr <= 69)
            return Letter::Cp;
        else if (gr >= 60 && gr <= 64)
            return Letter::C;
        else if (gr >= 55 && gr <= 59)
            return Letter::Dp;
        else if (gr >= 50 && gr <= 54)
            return Letter::D;
        else
            return Letter::F;
    };
    try {
        Grades grades(argv[1]);
        grades.displayGrades(std::cout, letter); // using ostream and lambda expression as paramters 
    }
    catch (const char * msg) {
        std::cout << msg << std::endl;
    }
    return 0;
}
