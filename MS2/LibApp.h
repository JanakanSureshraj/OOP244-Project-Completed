// Final Project Milestone 1 
// Date 22nd of July 2024
// File	LibApp.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Janakan Sureshraj  4th of July 2024     Completed the Date module
// 
// I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////

#ifndef LIBAPP_H
#define LIBAPP_H

#include "Menu.h"

namespace seneca {

    class LibApp {
    private:
        bool m_changed;
        Menu m_mainMenu;
        Menu m_exitMenu;

        bool confirm(const char* message);
        void load();
        void save();
        void search();
        void returnPub();

        void newPublication();
        void removePublication();
        void checkOutPub();
    public:
        LibApp();
        void run();
    };

}

#endif // LIBAPP_H

