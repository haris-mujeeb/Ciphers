/**
 * @file morse.cpp
 * @brief Implementation of Morse code encoding and decoding functions.
 *
 * This file contains functions to encode a string to Caeser code and decode
 * a Caeser code string back to its original representation. * 
 * 
 * @author Syed Muhammad Haider Rizvi
 * @date 11-07-2024
 */

#include "caeser_new.hpp"

std::string ciphers::Caeser::encoder( const std::string& istring, int shiftBy) {
    std::string ostring;
    for (char ch : istring) {
        if (std::isalpha(ch)) {
            char base = std::islower(ch) ? 'a' : 'A';
            ch = ( ch - base + shiftBy + 26 ) % 26 + base;  
        }
        ostring.push_back(ch);
    }
    return ostring;
}


std::string ciphers::Caeser::decoder( const std::string& istring, int shiftBy) {     
    return ciphers::Caeser::encoder(istring, -shiftBy) ;
}
