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
 * @author Muhammad Haris Mujeeb
 * @date 07-05-2024
 */

#ifndef MORSE_H
#define MORSE_H

#include <string>
#include <unordered_map>
#include <cctype>
#include "cipher_class.hpp"


namespace ciphers {
/**
 * @class Morse
 * @brief Add methods for encoding and decoding Morse code.
 */
class Morse : public Cipher {
  public:

    /**
     * @brief Encodes a given string to Morse code.
     * @param str The string to encode.
     * @return The encoded Morse code string. or '?' if the Morse code is not found.
     */
    std::string encoder( const std::string& ) ;
    
    /**
     * @brief Decodes a given Morse code string to text.
     * @param str The Morse code string to decode.
     * @return The decoded string. or '?' if the Morse code is not found.
     */
    std::string decoder(const std::string& ) ;  ///< Map of characters to Morse code.

  private:
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
};
}
#endif // MORSE_H
