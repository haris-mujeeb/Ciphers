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

/**
 * @class MorseCode
 * @brief Provides methods for encoding and decoding Morse code.
 */
class MorseCode {
  public:
    /**
     * @brief Constructs a MorseCode object and initializes the Morse code map.
     */
    MorseCode();
    
    /**
     * @brief Encodes a given string to Morse code.
     * @param str The string to encode.
     * @return The encoded Morse code string. or '?' if the Morse code is not found.
     */
    std::string encodeToMorse(const std::string str) const;
    
    /**
     * @brief Decodes a given Morse code string to text.
     * @param str The Morse code string to decode.
     * @return The decoded string. or '?' if the Morse code is not found.
     */
    std::string decodeFromMorse(const std::string str) const;  ///< Map of characters to Morse code.


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
    
    /**
     * @brief Converts a character to its corresponding Morse code string.
     * @param ch The character.
     * @return The corresponding Morse code string. or '?' if the Morse code is not found.
     */
    std::string charToMorse(const char ch) const;
    
    /**
     * @brief Converts a Morse code string to its corresponding character.
     * @param morse The Morse code string.
     * @return The corresponding character. or '?' if the Morse code is not found.
     */
    char morseToChar(const std::string morse) const;

};
#endif // MORSE_H