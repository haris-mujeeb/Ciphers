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


#ifndef MORSE_H
#define MORSE_H

#include <string>
#include <unordered_map>
#include <cctype>
#include "cipher_class.hpp"

/**
 * @struct MorseMapping
 * @brief A struct to store character and its Morse code.
 */
namespace ciphers {
    struct MorseMapping {
    char character;
    std::string morseCode;
};


/**
 * @class Morse
 * @brief Add methods for encoding and decoding Morse code.
 */
class Morse : public Cipher {
    /**
     * @brief Encodes a given string to Morse code.
     * @param str The string to encode.
     * @return The encoded Morse code string. or '?' if the Morse code is not found.
     */
  private:
    // use ordered maps
    const std::unordered_map<char, std::string> morseCodeMap = {
        {'A', ".-"},    {'B', "-..."},  {'C', "-.-."},  {'D', "-.."},   {'E', "."}, 
        {'F', "..-."},  {'G', "--."},   {'H', "...."},  {'I', ".."},    {'J', ".---"}, 
        {'K', "-.-"},   {'L', ".-.."},  {'M', "--"},    {'N', "-."},    {'O', "---"}, 
        {'P', ".--."},  {'Q', "--.-"},  {'R', ".-."},   {'S', "..."},   {'T', "-"}, 
        {'U', "..-"},   {'V', "...-"},  {'W', ".--"},   {'X', "-..-"},  {'Y', "-.--"}, 
        {'Z', "--.."},  {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, 
        {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."}, 
        {'0', "-----"}, {' ', " "}
    };
  public:  
    std::string encoder( const std::string& istring) {
        std::string encodedString;
        for (char ch : istring) {
            ch = std::toupper(ch);
            auto iter = morseCodeMap.find(ch);
            std::string morse;
            if (iter != morseCodeMap.end()) 
                morse = iter->second;
            else 
                morse = "?";
            encodedString += morse;
            encodedString += " ";
        }
        return encodedString;
    }       
    
    /**
     * @brief Decodes a given Morse code string to text.
     * @param str The Morse code string to decode.
     * @return The decoded string. or '?' if the Morse code is not found.
     */
    std::string decoder(const std::string& istring) {  ///< Map of characters to Morse code.
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
                    if ( pair.second == morse ) { 
                        decodedString.push_back(pair.first);
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
};
}
#endif // MORSE_H