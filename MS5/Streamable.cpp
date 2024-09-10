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

using namespace std;

namespace seneca {

    std::ostream& operator<<(std::ostream& os, const Streamable& stream) {
        if (stream) {
            stream.write(os);
        }
        else {
            cout << "stream invalid" << endl;
        }
        return os;
    }

    std::istream& operator>>(std::istream& is, Streamable& stream) {
        return stream.read(is);
    }
}

