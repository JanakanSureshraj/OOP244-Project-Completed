// Final Project Milestone 1 
// Date 22nd of July 2024
// File	LibApp.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Janakan Sureshraj  4th of July 2024     Completed the LinApp module
// Janakan Sureshraj  9th of Aug 2024      Updated the LinApp module for MS5
// 
// I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Book.h"
#include "Menu.h"
#include "Publication.h"
#include "Lib.h"

namespace seneca {
    class LibApp {
    private:
        // MS5
        char m_filename[256];
        Publication* m_publications[SENECA_LIBRARY_CAPACITY] = {};
        int m_numOfLoadedPubs;
        int m_lastLibRefNum;
        Menu* m_pubTypeMenu;
        // Original
        bool m_changed;
        Menu* m_mainMenu;
        Menu* m_exitMenu;
        bool confirm(const char* message);
        LibApp(const LibApp&) = delete;
        LibApp& operator=(const LibApp&) = delete;

    public:
        // MS5 additional methods
        Publication* getPub(int libRef);

        LibApp(const char* filename);
        ~LibApp();
        void load();
        void save();
        void search();
        int search(int searchMode);
        void returnPub();
        void newPublication();
        void removePublication();
        void checkOutPub();
        void run();
    };
}  
#endif  
