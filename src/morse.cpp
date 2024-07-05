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

#include "morse.hpp"

MorseCode::MorseCode() {

}
char MorseCode::morseToChar(const std::string morse) const {
    for (const auto& pair : morseCodeMap) {
        if( pair.second == morse) 
            return pair.first;
    }
    return '?';
}

std::string MorseCode::charToMorse(const char ic) const{
    char ch = std::toupper(ic);
    auto iter = morseCodeMap.find(ch);
    if (iter != morseCodeMap.end()) 
        return iter->second;
    else 
        return "?";
}

std::string MorseCode::encodeToMorse(const std::string str) const {
    std::string encodedString;
    for (char c : str) {
        encodedString += charToMorse(c);
        encodedString += " ";
    }
    return encodedString;
}

std::string MorseCode::decodeFromMorse(const std::string str) const {
    std::string decodedString;
    const int maxLen = 5; // max possible len of any morse code

    std::string morse;
    int j = 0;
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == ' ' || j >= maxLen) {
            decodedString.push_back( morseToChar(morse) );
            morse.clear();
            j = 0;
            if (str[i] == ' ') i++;
        }
        morse.push_back( str[i] );
        j++;
    }        
    return decodedString;
}