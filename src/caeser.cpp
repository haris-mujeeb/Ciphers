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

#ifndef CAESER_H
#define CAESER_H

#include <string>
#include <unordered_map>
#include <cctype>
#include "cipher_class.hpp"

namespace ciphers {
/**
 * @class Caeser
 * @brief Add methods for encoding and decoding Morse code.
 */
class Caeser : public Cipher {
  public:

    /**
     * @brief Encodes a given string to Morse code.
     * @param str The string to encode.
     * @return The encoded Morse code string. or '?' if the Morse code is not found.
     */
    std::string encoder(const std::string& istring, int shiftBy) {
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
    
    /**
     * @brief Decodes a given Morse code string to text.
     * @param str The Morse code string to decode.
     * @return The decoded string. or '?' if the Morse code is not found.
     */
    std::string decoder(const std::string& istring, int shiftBy) {  ///< Map of characters to Morse code.
        return Caeser::encoder(istring, -shiftBy) ;
    };
};
}
#endif // CAESER_H