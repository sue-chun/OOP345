// Name: Sue Ming Chun
// Seneca Student ID: 032343154
// Seneca email: smchun@myseneca.ca
// Date of completion: Oct 8 2018
//
// I confirm that the contents of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SICT_LETTER_H
#define SICT_LETTER_H

#include <iostream>

namespace sict {
    enum class Letter {Ap, A, Bp, B, Cp, C, Dp, D, F};
    template<typename T>
    const char* grds (const T& gr) {
        const char* letter;
        switch(gr) {
            case Letter::Ap:
                letter = "A+";
                break;
            case Letter::A:
                letter = "A";
                break;
            case Letter::Bp:
                letter = "B+";
                break;
            case Letter::B:
                letter = "B";
                break;
            case Letter::Cp:
                letter = "C+";
                break;
            case Letter::C:
                letter = "C";
                break;
            case Letter::Dp:
                letter = "D+";
                break;
            case Letter::D:
                letter = "D";
                break;
            case Letter::F:
                letter = "F";
                break;
            default:
                letter = "None";
        }
        return letter;
    }
}
#endif
