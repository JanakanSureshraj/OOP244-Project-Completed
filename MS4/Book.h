// Final Project Milestone 1 
// Book Module
// File	Book.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Janakan Sureshraj  5th of August 2024     Completed the Book module
// 
// I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
// 
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include "Publication.h"

namespace seneca {

    class Book : public Publication {
        char* m_author;

    public:
        Book();
        Book(const Book& other);
        Book& operator=(const Book& other);
        ~Book();

        void set(int member_id) override;
        char type() const override;
        std::ostream& write(std::ostream& os) const override;
        std::istream& read(std::istream& istr) override;
        operator bool() const override;

    private:
        void setAuthor(const char* author);
        void copyFrom(const Book& other);
    };

}

#endif // SENECA_BOOK_H
