// Final Project Milestone 1 
// Book Module
// File	Book.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Janakan Sureshraj  5th of August 2024     Completed the Book module
// Janakan Sureshraj  7th of August 2024     Minor Update for MS5
// I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
// 
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include "Publication.h"

namespace seneca {
    class Book : public Publication {
    private:
        char* m_author;

    public:
        Book();
        // Rule of 3
        Book(const Book& object);
        Book& operator=(const Book& object);
        ~Book();

        char type() const;
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& is);
        void set(int membershipNum);
        operator bool() const;
    };
}  
#endif  
