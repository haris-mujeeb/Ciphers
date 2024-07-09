/**
 * @file morse.hpp
 * @brief Header file for Morse code encoding and decoding.
 * 
 * This file contains the declaration of the MorseCode class, which provides
 * methods to encode text to Morse code and decode a Morse code string 
 * back to text.
 * 
 * @see morse.cpp for implementation details.
 *
 * @author Syed Haider Rizvi
 * @date 09-07-2024
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
    std::string encoder(const std::string, int) ;
    
    /**
     * @brief Decodes a given Morse code string to text.
     * @param str The Morse code string to decode.
     * @return The decoded string. or '?' if the Morse code is not found.
     */
    std::string decoder(const std::string, int) ;  ///< Map of characters to Morse code.
};
}
#endif // CAESER_H