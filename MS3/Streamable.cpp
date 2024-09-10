// Final Project Milestone 1 
// Streamable Interface Module
// File	Streamable.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Janakan Sureshraj  7th of Aug 2024     Completed the Streamable Interface
// 
// I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "Streamable.h"

namespace seneca {

    std::ostream& operator<<(std::ostream& os, const Streamable& obj) {
        if (obj) {
            obj.write(os);
        }
        return os;
    }

    std::istream& operator>>(std::istream& is, Streamable& obj) {
        return obj.read(is);
    }

}

