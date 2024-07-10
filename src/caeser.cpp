/**
 * @file morse.cpp
 * @brief Implementation of Morse code encoding and decoding functions.
 *
 * This file contains functions to encode a string to Morse code and decode
 * a Morse code string back to its original representation. It uses an
 * unordered map to store the mappings between characters and Morse code.
 * 
 * @author Syed Haider Rizvi
 * @date 07-05-2024
 */

#include "caeser.hpp"

std::string ciphers::Caeser::encoder( const std::string istring, int shiftBy) {
    std::string ostring;
    for (char ch : istring) {
        if (ch != ' ') {
            ch = std::toupper(ch); // Convert to uppercase
            ch = char(int(ch) + shiftBy);  
        }
        ostring.push_back(ch);
    }
    return ostring;
}


std::string ciphers::Caeser::decoder( const std::string istring, int shiftBy) {     
    return ciphers::Caeser::encoder(istring, -shiftBy) ;
}
