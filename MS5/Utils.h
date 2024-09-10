// Final Project Milestone 1 
// Date Utils
// File	Utils.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Janakan Sureshraj  4th of July 2024     Completed the Date module
// Janakan Sureshraj  7th of Aug  2024     Minor Update for MS5 to not use Utils module- included in the specific module itself

// I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
#ifndef UTILS_H
#define UTILS_H

namespace Utils {
    unsigned int getFoolproofInt(const std::string& prompt, const std::string& errorMsg, unsigned int min, unsigned int max);
}

#endif // UTILS_H
