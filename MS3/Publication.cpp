// Final Project Milestone 1 
// Publication Module
// File	Publication.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Janakan Sureshraj  4th of July 2024     Completed the Publication module
// 
// I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////#ifndef SENECA_PUBLICATION_H
#define _CRT_SECURE_NO_WARNINGS
#include "Publication.h"
#include <string>

namespace seneca {

    Publication::Publication() : m_title(nullptr), m_membership(0), m_libRef(-1), m_date() {
        m_shelfId[0] = '\0';
    }

    Publication::Publication(const Publication& other) : Publication() {
        copyFrom(other);
    }

    Publication& Publication::operator=(const Publication& other) {
        if (this != &other) {
            delete[] m_title;
            copyFrom(other);
        }
        return *this;
    }

    Publication::~Publication() {
        delete[] m_title;
    }

    void Publication::set(int member_id) {
        m_membership = member_id >= 10000 && member_id <= 99999 ? member_id : 0;
    }

    void Publication::setRef(int value) {
        m_libRef = value;
    }

    void Publication::resetDate() {
        m_date.setToToday();
    }

    char Publication::type() const {
        return 'P';
    }

    bool Publication::onLoan() const {
        return m_membership != 0;
    }

    Date Publication::checkoutDate() const {
        return m_date;
    }

    bool Publication::operator==(const char* title) const {
        return m_title && strstr(m_title, title) != nullptr;
    }

    Publication::operator const char* () const {
        return m_title;
    }

    int Publication::getRef() const {
        return m_libRef;
    }

    bool Publication::conIO(std::ios& io) const {
        return &io == &std::cin || &io == &std::cout;
    }

    std::ostream& Publication::write(std::ostream& os) const {
        if (conIO(os)) {
            os << "| " << m_shelfId << " | "
                << std::left << std::setw(SENECA_TITLE_WIDTH) << std::setfill('.') << m_title << " | "
                << (onLoan() ? std::to_string(m_membership) : " N/A ") << " | "
                << m_date << " |";
        }
        else {
            os << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t"
                << m_membership << "\t" << m_date;
        }
        return os;
    }

    std::istream& Publication::read(std::istream& istr) {
        // Clear the current attributes
        delete[] m_title;
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;

        // Temporary variables for input
        char title[256] = {};
        char shelfId[SENECA_SHELF_ID_LEN + 1] = {};
        int membership = 0;
        int libRef = -1;
        Date date;

        // Check if the input stream is a console IO object
        if (conIO(istr)) {
            std::cout << "Shelf No: ";
            istr.getline(shelfId, SENECA_SHELF_ID_LEN + 1);
            if (strlen(shelfId) != SENECA_SHELF_ID_LEN) {
                // If shelf ID length is not valid, set the stream to a fail state
                istr.setstate(std::ios::failbit);
            }


            std::cout << "Title: "; 
            istr.getline(title, 256);

   
            std::cout << "Date: ";
            istr >> date;

        }
        else {
            istr >> libRef;
            istr.ignore();
            istr.getline(shelfId, SENECA_SHELF_ID_LEN + 1, '\t');
            istr.getline(title, 256, '\t');
            istr >> membership;
            istr.ignore();
            istr >> date;
        }

        // Check if the date is valid
        if (!date) {
            istr.setstate(std::ios::failbit);
        }

        // If all inputs are valid, set the attributes
        if (istr) {
            setTitle(title);
            strcpy(m_shelfId, shelfId);
            m_membership = membership;
            m_libRef = libRef;
            m_date = date;
        }

        return istr;
    }


    Publication::operator bool() const {
        return m_title && m_shelfId[0] != '\0';
    }

    void Publication::setTitle(const char* title) {
        if (title) {
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
        }
        else {
            m_title = nullptr;
        }
    }

    void Publication::copyFrom(const Publication& other) {
        setTitle(other.m_title);
        strcpy(m_shelfId, other.m_shelfId);
        m_membership = other.m_membership;
        m_libRef = other.m_libRef;
        m_date = other.m_date;
    }

}
