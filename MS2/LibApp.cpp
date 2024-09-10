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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LibApp.h"

using namespace std;

namespace seneca {

    LibApp::LibApp()
        : m_changed(false),
        m_mainMenu("Seneca Library Application"),
        m_exitMenu("Changes have been made to the data, what would you like to do?") {
        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
        load();
    }

    bool LibApp::confirm(const char* message) {
        Menu confirmMenu(message);  
        confirmMenu << "Yes";
        return confirmMenu.run() == 1;
    }

    void LibApp::load() {
        cout << "Loading Data" << endl;
    }

    void LibApp::save() {
        cout << "Saving Data" << endl;
    }

    void LibApp::search() {
        cout << "Searching for publication" << endl;
    }

    void LibApp::returnPub() {
        search();
        cout << "Returning publication" << endl;
        cout << "Publication returned" << endl;
        m_changed = true;
    }

    void LibApp::newPublication() {
        cout << "Adding new publication to library" << endl;
        if (confirm("Add this publication to library?")) {
            m_changed = true;
            cout << "Publication added" << endl;
        }
        cout << endl; 
    }

    void LibApp::removePublication() {
        cout << "Removing publication from library" << endl;
        search();
        if (confirm("Remove this publication from the library?")) {
            m_changed = true;
            cout << "Publication removed" << endl;
        }
        cout << endl;
    }

    void LibApp::checkOutPub() {
        search();
        if (confirm("Check out publication?")) {
            m_changed = true;
            cout << "Publication checked out" << endl;
        }
        cout << endl;
    }

    void LibApp::run() {
        bool done = false;
        while (!done) {
            switch (m_mainMenu.run()) {
            case 1:
                newPublication();
                break;
            case 2:
                removePublication();
                break;
            case 3:
                checkOutPub();
                break;
            case 4:
                returnPub();
                cout << endl;
                break;
            case 0:
                if (m_changed) {
                    switch (m_exitMenu.run()) {
                    case 1:
                        save();
                        done = true;
                        cout << endl;
                        break;
                    case 2:
                        cout << endl;
                        break;
                    case 0:
                        if (confirm("This will discard all the changes are you sure?")) {
                            done = true;
                        }
                        cout << endl;
                        break;
                    }
                }
                else {
                    done = true;
                    cout << endl;
                }
                break;
            }
        }
        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }

}
