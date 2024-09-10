// Final Project Milestone 1 
// Streamable Interface Module
// File	Streamable.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Janakan Sureshraj  4th of July 2024     Completed the Streamable Interface
// 
// I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
#ifndef SENECA_STREAMABLE_H
#define SENECA_STREAMABLE_H

#include <iostream>

namespace seneca {

    class Streamable {
    public: 
        virtual ~Streamable() = default;
        virtual std::ostream& write(std::ostream& os) const = 0;
        virtual std::istream& read(std::istream& istr) = 0;
        virtual bool conIO(std::ios& io) const = 0;
        virtual operator bool() const = 0;
    };

    std::ostream& operator<<(std::ostream& os, const Streamable& obj);
    std::istream& operator>>(std::istream& is, Streamable& obj);

}

#endif // SENECA_STREAMABLE_H
