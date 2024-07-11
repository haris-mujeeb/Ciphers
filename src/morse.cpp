/**
 * @file morse.cpp
 * @brief Implementation of Morse code encoding and decoding functions.
 *
 * This file contains functions to encode a string to Morse code and decode
 * a Morse code string back to its original representation. It uses an
 * unordered map to store the mappings between characters and Morse code.
 * 
 * @author Muhammad Haris Mujeeb
 * @date 07-05-2024
 */

#include <algorithm>
#include "morse.hpp"

std::string findMorseCode(std::vector<ciphers::MorseMapping> map, char key) { 
    auto lambda = [key] (const ciphers::MorseMapping& pair) { return pair.character == key; };
    auto iter = std::find_if( map.begin(), map.end(), lambda );
    if ( iter != map.end() ) {
        return iter->morseCode;
    } else {
        return "?";
    }
}

std::string ciphers::Morse::encoder( const std::string istring) {
    std::string encodedString;
    for (char ch : istring) {
        ch = std::toupper(ch);
        std::string morse = findMorseCode(morseCodeMap, ch);
        encodedString += morse;
        encodedString += " ";
    }
    return encodedString;
}


std::string ciphers::Morse::decoder( const std::string istring) {
    std::string decodedString;
    const int maxLen = 5; // max possible len of any morse code

    std::string morse;
    int j = 0;
    for (size_t i = 0; i < istring.size(); i++) {
        if (istring[i] == ' ' || j >= maxLen) {
            if (istring[i] == ' ') i++;
            // find char for morse
            bool charFound = false;
            for (const auto& pair : morseCodeMap) { 
                if ( pair.morseCode == morse ) { 
                    decodedString.push_back(pair.character);
                    charFound = true;
                }
             }
            if (!charFound) decodedString.push_back('?');
            
            morse.clear();
            j = 0;
        }
        morse.push_back( istring[i] );
        j++; 
    }       
    return decodedString;
}
