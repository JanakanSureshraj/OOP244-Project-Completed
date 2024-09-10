/* Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Menu.h"

using namespace std;

namespace seneca {

    MenuItem::MenuItem(const char* item) : content(nullptr) {
        if (item && item[0] != '\0') {
            content = new char[strlen(item) + 1];
            strcpy(content, item);
        }
    }

    MenuItem::~MenuItem() {
        delete[] content;
    }

    MenuItem::operator bool() const {
        return content != nullptr && content[0] != '\0';
    }

    MenuItem::operator const char* () const {
        return content;
    }

    std::ostream& MenuItem::display(std::ostream& os) const {
        if (*this) {
            os << content;
        }
        return os;
    }

    ostream& operator<<(ostream& os, const MenuItem& item) {
        return item.display(os);
    }

    Menu::Menu(const char* menuTitle) : title(nullptr), numItems(0) {
        if (menuTitle && menuTitle[0] != '\0') {
            title = new MenuItem(menuTitle);
        }
        for (unsigned int i = 0; i < MAX_MENU_ITEMS; ++i) {
            items[i] = nullptr;
        }
    }

    Menu::~Menu() {
        delete title;
        for (unsigned int i = 0; i < numItems; ++i) {
            delete items[i];
        }
    }

    void Menu::displayTitle(ostream& os) const {
        if (title) {
            title->display(os);
        }
    }

    void Menu::display(ostream& os) const {
        if (title) {
            title->display(os);
            os << ":\n";
        }
        for (unsigned int i = 0; i < numItems; ++i) {
            os << setw(2) << right << (i + 1) << "- ";
            items[i]->display(os);
            os << "\n";
        }
        os << " 0- Exit\n> ";
    }

    unsigned int Menu::run() const {
        display(cout);
        return Utils::getFoolproofInt("", "Invalid Selection, try again: ", 0, numItems);
    }

    unsigned int Menu::operator~() const {
        return run();
    }

    Menu& Menu::operator<<(const char* menuItemContent) {
        if (numItems < 20) {
            items[numItems++] = new MenuItem(menuItemContent);
        }
        return *this;
    }

    Menu::operator bool() const {
        return numItems > 0;
    }

    Menu::operator unsigned int() const {
        return numItems;
    }

    const char* Menu::operator[](unsigned int index) const {
        if (numItems == 0) return nullptr;
        return *items[index % numItems];
    }

    ostream& operator<<(ostream& os, const Menu& menu) {
        menu.displayTitle(os);
        return os;
    }
}

