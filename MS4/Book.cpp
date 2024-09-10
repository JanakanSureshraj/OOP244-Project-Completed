// Final Project Milestone 1 
// Book Module
// File	Book.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include <cstring>
#include <iomanip>

namespace seneca {

    Book::Book() : Publication(), m_author(nullptr) {}

    Book::Book(const Book& other) : Publication(other) {
        copyFrom(other);
    }

    Book& Book::operator=(const Book& other) {
        if (this != &other) {
            Publication::operator=(other);
            delete[] m_author;
            copyFrom(other);
        }
        return *this;
    }

    Book::~Book() {
        delete[] m_author;
    }

    void Book::set(int member_id) {
        Publication::set(member_id);
        resetDate();
    }

    char Book::type() const {
        return 'B';
    }

    std::ostream& Book::write(std::ostream& os) const {
        Publication::write(os);

        if (conIO(os)) {
            os << ' ';
            std::string author = m_author ? m_author : "";
            if (author.length() > SENECA_AUTHOR_WIDTH) {
                author = author.substr(0, SENECA_AUTHOR_WIDTH);
            }
            os << std::left << std::setw(SENECA_AUTHOR_WIDTH) << std::setfill(' ') << author << " |";
        }
        else {
            os << '\t' << (m_author ? m_author : "");
        }
        return os;
    }

    std::istream& Book::read(std::istream& is) {
        char temp[256]{};

        Publication::read(is);

        if (m_author) {
            delete[] m_author;
        }
        m_author = nullptr;

        if (conIO(is)) {
            is.ignore();
            std::cout << "Author: ";
            is.getline(temp, 256);
        }
        else {
            is.ignore();
            is.get(temp, 256);
        }

        if (is) {
            m_author = new char[strlen(temp) + 1];
            strcpy(m_author, temp);
        }
        return is;
    }

    Book::operator bool() const {
        if (m_author != nullptr && Publication::operator bool()) {
            return true;
        }
        else return false;
    }

    void Book::setAuthor(const char* author) {
        if (author) {
            m_author = new char[strlen(author) + 1];
            strcpy(m_author, author);
        }
        else {
            m_author = nullptr;
        }
    }

    void Book::copyFrom(const Book& other) {
        setAuthor(other.m_author);
    }

}
