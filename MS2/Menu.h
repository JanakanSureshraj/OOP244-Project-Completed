/* Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.0
Author	Janakan Sureshraj
Revision History
-----------------------------------------------------------
Date      Reason
2024/4/7  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SENECA_MENU_H__
#define SENECA_MENU_H__

#include <iostream>
#include "Utils.h"

namespace seneca {

    const unsigned int MAX_MENU_ITEMS = 20;

    class Menu;  // Forward declaration of the Menu class

    class MenuItem {

        friend class Menu;

        char* content;  // Dynamically allocated content of the menu item
        MenuItem(const char* item = nullptr);  // Private constructor
        MenuItem(const MenuItem& other) = delete;  // Deleted copy constructor
        MenuItem& operator=(const MenuItem& other) = delete;  // Deleted copy assignment operator
        ~MenuItem();  // Destructor

        operator bool() const;  // Bool type conversion
        operator const char* () const;  // const char* type conversion
    public:std::ostream& display(std::ostream& os) const;  // Display method
    };

    class Menu {
        MenuItem* title;  // Optional title of the menu
        MenuItem* items[MAX_MENU_ITEMS];  // Array of MenuItem pointers
        unsigned int numItems;  // Number of menu items

    public:
        Menu(const char* title = nullptr);  // Constructor
        Menu(const Menu& other) = delete;  // Deleted copy constructor
        Menu& operator=(const Menu& other) = delete;  // Deleted copy assignment operator
        ~Menu();  // Destructor

        void displayTitle(std::ostream& os) const;  // Display the title
        void display(std::ostream& os) const;  // Display the entire menu
        unsigned int run() const;  // Display the menu and get user selection

        Menu& operator<<(const char* menuItemContent);  // Add a menu item
        operator bool() const;  // Bool type conversion
        operator unsigned int() const;  // Unsigned int type conversion
        const char* operator[](unsigned int index) const;  // Indexing operator
        unsigned int operator~() const;

        friend std::ostream& operator<<(std::ostream& os, const Menu& menu);  // Insertion operator
    };

    std::ostream& operator<<(std::ostream& os, const MenuItem& item);  // Overloaded operator<<
    std::ostream& operator<<(std::ostream& os, const Menu& menu);  // Overloaded operator<<
}

#endif