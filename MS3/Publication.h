// Final Project Milestone 1 
// Publication Module
// File	Publication.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Janakan Sureshraj  4th of July 2024     Completed the Publication module
// 
// I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
#ifndef SENECA_PUBLICATION_H
#define SENECA_PUBLICATION_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Date.h"
#include "Streamable.h"
#include "Lib.h"

namespace seneca {

    class Publication : public Streamable {
        char* m_title;
        char m_shelfId[SENECA_SHELF_ID_LEN + 1];
        int m_membership;
        int m_libRef;
        Date m_date;

    public:
        Publication();
        Publication(const Publication& other);
        Publication& operator=(const Publication& other);
        ~Publication();

        void set(int member_id);
        void setRef(int value);
        void resetDate();

        char type() const;
        bool onLoan() const;
        Date checkoutDate() const;
        bool operator==(const char* title) const;
        operator const char* () const;
        int getRef() const;

        bool conIO(std::ios& io) const override;
        std::ostream& write(std::ostream& os) const override;
        std::istream& read(std::istream& istr) override;
        operator bool() const override;

    private:
        void setTitle(const char* title);
        void copyFrom(const Publication& other);
    };

}

#endif // SENECA_PUBLICATION_H
