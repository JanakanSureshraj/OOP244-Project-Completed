// Final Project Milestone 1 
// Date Utils
// File	Utils.cpp
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
#include <limits>

namespace Utils {
    unsigned int getFoolproofInt(const std::string& prompt, const std::string& errorMsg, unsigned int min, unsigned int max) {
        unsigned int selection;
        bool valid = false;
        while (!valid) {
            std::cout << prompt;
            std::cin >> selection;
            if (std::cin.fail() || selection < min || selection > max) {
                std::cin.clear(); // clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
                std::cout << errorMsg;
            }
            else {
                valid = true;
            }
        }
        return selection;
    }
}
