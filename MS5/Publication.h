// Final Project Milestone 1 
// Publication Module
// File	Publication.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Janakan Sureshraj  4th of August 2024     Completed the Publication module
// 
// I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
#ifndef SENECA_PUBLICATION_H
#define SENECA_PUBLICATION_H
#include "Date.h"
#include "Lib.h"
#include "Streamable.h"
namespace seneca {
    class Publication : public Streamable {
    private:
        char* m_title;
        char m_shelfID[SENECA_SHELF_ID_LEN + 1];
        int m_membership;
        int m_libRef;
        Date m_date;

    public:
        void setDefault();
        Publication();
        virtual void set(int member_id);
        void setRef(int value);
        void resetDate();
        virtual char type() const;
        bool onLoan() const;
        Date checkoutDate() const;
        bool operator==(const char* title) const;
        operator const char* () const;
        int getRef() const;
        bool conIO(std::ios& io) const;
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& istr);
        operator bool() const;

        // Rule of 3
        Publication(const Publication& object);
        Publication& operator=(const Publication& object);
        ~Publication();
    };
}  
#endif