// Final Project Milestone 1 
// Date 22nd of July 2024
// File	LibApp.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include "LibApp.h"
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include "Menu.h"
#include "PublicationSelector.h"

using namespace std;
namespace seneca {
    LibApp::LibApp(const char* filename) {
        // MS5
        m_numOfLoadedPubs = 0;
        m_lastLibRefNum = 0;
        m_pubTypeMenu = new Menu("Choose the type of publication:");
        *m_pubTypeMenu << "Book"
            << "Publication";
        strcpy(m_filename, filename);
        // Original
        m_changed = false;
        m_mainMenu = new Menu("Seneca Library Application");
        *m_mainMenu << "Add New Publication"
            << "Remove Publication"
            << "Checkout publication from library"
            << "Return publication to library";
        m_exitMenu = new Menu("Changes have been made to the data, what would you like to do?");
        *m_exitMenu << "Save changes and exit"
            << "Cancel and go back to the main menu";
        load();
    }

    LibApp::~LibApp() {
        delete m_mainMenu;
        delete m_exitMenu;
        delete m_pubTypeMenu;
        for (int i = 0; i < m_numOfLoadedPubs; i++) {
            delete m_publications[i];
        }
    }

    bool LibApp::confirm(const char* message) {
        Menu* confirmMenu = new Menu(message);
        *confirmMenu << "Yes";
        if (confirmMenu->run() == 1) {
            delete confirmMenu;
            return true;
        }
        delete confirmMenu;
        return false;
    }

    // MS5 Modification
    void LibApp::load() {
        cout << "Loading Data" << endl;
        ifstream ifile(m_filename);
        char type;
        while (ifile) {
            ifile >> type;
            if (type == 'P') {
                m_publications[m_numOfLoadedPubs] = new Publication();
                m_publications[m_numOfLoadedPubs]->read(ifile);
                m_lastLibRefNum = m_publications[m_numOfLoadedPubs]->getRef();
                m_numOfLoadedPubs++;
            }
            else if (type == 'B') {
                m_publications[m_numOfLoadedPubs] = new Book();
                m_publications[m_numOfLoadedPubs]->read(ifile);
                m_lastLibRefNum = m_publications[m_numOfLoadedPubs]->getRef();
                m_numOfLoadedPubs++;
            }
            type = '\0';
        }
    }

    // MS5 Modification
    void LibApp::save() {
        cout << "Saving Data" << endl;
        ofstream ifile(m_filename);
        for (int i = 0; i < m_numOfLoadedPubs; i++) {
            if (m_publications[i]->getRef() != 0) {
                ifile << *m_publications[i];
            }
        }
    }

    void LibApp::search() {
        cout << "Searching for publication" << endl;
    }

    // MS5 Modification
    int LibApp::search(int searchMode) {
        // cout << "Searching for publication" << endl;
        int selection = m_pubTypeMenu->run();
        if (selection == 0) {
            cout << "Aborted!" << endl;
            return selection;
        }
        char pubType = (selection == 1) ? 'B' : 'P';
        cout << "Publication Title: ";
        char title[256];
        cin.getline(title, 255, '\n');
        PublicationSelector pubSelector("Select one of the following found matches:");
        bool matchesFound = false;
        for (int i = 0; i < m_numOfLoadedPubs; i++) {
            if (pubType == m_publications[i]->type()) {
                if (searchMode == 1) {  // Search all publications
                    if (*m_publications[i] == title) {
                        pubSelector << *m_publications[i];
                        matchesFound = true;
                    }
                }
                else if (searchMode == 2) {  // Search checked out publications
                    if (m_publications[i]->onLoan() &&
                        *m_publications[i] == title) {
                        pubSelector << *m_publications[i];
                        matchesFound = true;
                    }
                }
                else if (searchMode == 3) {  // Search available publications
                    if (!m_publications[i]->onLoan() &&
                        *m_publications[i] == title) {
                        pubSelector << *m_publications[i];
                        matchesFound = true;
                    }
                }
            }
        }
        if (matchesFound) {
            pubSelector.sort();
            selection = pubSelector.run();
            if (selection == 0) {
                cout << "Aborted!" << endl;
            }
        }
        else {
            cout << "No matches found!" << endl
                << endl;
            return -1;
        }
        return selection;
    }

    // MS5 Modification
    Publication* LibApp::getPub(int libRef) {
        return m_publications[libRef];
    }

    // MS5 Modification
    void LibApp::returnPub() {
        cout << "Return publication to the library" << endl;
        int selection = search(2);
        if (selection == 0) {
            cout << endl;
            return;
        }
        Publication* pub = nullptr;
        for (int i = 0; i < m_numOfLoadedPubs; i++) {
            if (m_publications[i]->getRef() == selection) {
                pub = m_publications[i];
                cout << *pub << endl;
            }
        }
        if (confirm("Return Publication?")) {
            Date currentDate = Date();
            int daysLoaned = currentDate - pub->checkoutDate();
            if (daysLoaned > 15) {
                double lateFee = (double)(daysLoaned - 15) * 0.50;
                cout << "Please pay $";
                cout << fixed << setprecision(2) << lateFee;
                cout << " penalty for being ";
                cout << daysLoaned - 15 << " days late!" << endl;
            }
            pub->set(0);
            m_changed = true;
            cout << "Publication returned" << endl;
        }
        cout << endl;
    }

    // MS5 Modification
    void LibApp::newPublication() {
        if (m_numOfLoadedPubs == SENECA_LIBRARY_CAPACITY) {
            cout << "Library is at its maximum capacity!" << endl << endl;
            return;
        }
        cout << "Adding new publication to the library" << endl;
        int selection = m_pubTypeMenu->run();
        if (selection == 0) {
            cout << "Aborted!" << endl << endl;
            return;
        }
        Publication* addition{};
        if (selection == 1) {
            addition = new Book();
            addition->read(cin);
        }
        else if (selection == 2) {
            addition = new Publication();
            addition->read(cin);
        }
        if (!cin.good() || cin.fail()) {
            cout << "Aborted!" << endl;
            return;
        }
        else {
            if (confirm("Add this publication to the library?")) {
                if (bool(addition)) {
                    m_lastLibRefNum++;
                    addition->setRef(m_lastLibRefNum);
                    m_publications[m_numOfLoadedPubs] = addition;
                    m_numOfLoadedPubs++;
                    m_changed = true;
                    cout << "Publication added" << endl;
                }
                else {
                    cout << "Failed to add publication!";
                    delete addition;
                }
            }
            else {
                cout << "Aborted!" << endl;
                return;
            }
        }
        if (selection == 0) {
            cout << "Aborted!" << endl;
        }
        cout << endl;
    }

    // MS5 Modification
    void LibApp::removePublication() {
        cout << "Removing publication from the library" << endl;
        int selection = search(1);
        if (selection == 0) {
            cout << endl;
            return;
        }
        Publication* pub = nullptr;
        for (int i = 0; i < m_numOfLoadedPubs; i++) {
            if (m_publications[i]->getRef() == selection) {
                cout << *m_publications[i] << endl;
                pub = m_publications[i];
            }
        }
        if (confirm("Remove this publication from the library?")) {
            m_changed = true;
            pub->setRef(0);
            cout << "Publication removed" << endl;
        }
        cout << endl;
    }

    // MS5 Modification
    void LibApp::checkOutPub() {
        cout << "Checkout publication from the library" << endl;
        int selection = search(3);
        if (selection == -1) return;
        Publication* pub = nullptr;
        for (int i = 0; i < m_numOfLoadedPubs; i++) {
            if (m_publications[i]->getRef() == selection) {
                pub = m_publications[i];
                cout << *pub << endl;
            }
        }
        if (confirm("Check out publication?")) {
            int membershipNum = -1;
            cout << "Enter Membership number: ";
            do {
                cin >> membershipNum;
                if (cin.fail()) {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (membershipNum < 9999 || membershipNum > 99999) {
                    cout << "Invalid membership number, try again: ";
                }
            } while (membershipNum < 9999 || membershipNum > 99999);
            pub->set(membershipNum);
            m_changed = true;
            cout << "Publication checked out" << endl;
        }
        cout << endl;
    }

    // MS5 Modification
    void LibApp::run() {
        bool done = false;
        unsigned int selection = 1;
        while (!done) {
            m_mainMenu->displayTitle();
            m_mainMenu->displayMenu();
            cout << "> ";
            cin.clear();
            cin >> selection;
            if (selection == 1) {
                newPublication();
            }
            if (selection == 2) {
                removePublication();
            }
            if (selection == 3) {
                checkOutPub();
            }
            if (selection == 4) {
                returnPub();
            }
            if (selection == 0) {
                if (m_changed == true) {
                    selection = m_exitMenu->run();
                    if (selection == 1) {
                        save();
                        done = true;
                    }
                    else if (selection == 0) {
                        if (confirm("This will discard all the changes are you sure?")) {
                            done = true;
                        }
                    }
                    else {
                        cout << endl;
                    }
                }
                else {
                    done = true;
                }
            }
        }
        cout << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }
}  // namespace sdds
