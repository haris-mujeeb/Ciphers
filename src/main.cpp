/**
 * @file main.cpp
 * @brief Demonstrates the usage of MorseCode class for encoding and decoding.
 * 
 * This file contains the main function which demonstrates how to use the 
 * MorseCode class to encode a string to Morse code and decode it back.
 * 
 * @author Muhammad Haris Mujeeb
 * @date 07-05-2024
 */

#include <iostream>
#include "morse.hpp"

int main() {
    MorseCode myCoder;

    std::string text = "Hello My C++ project!";
    std::string encoded = myCoder.encodeToMorse(text);
    std::string decoded = myCoder.decodeFromMorse(encoded);

    std::cout << "Original text: " << text << std::endl;
    std::cout << "Encoded text: " <<  encoded << std::endl;
    std::cout << "Decoded text: " << decoded << std::endl;
    std::cout << std::endl;
    std::cout << "Note: '?' means corresponding character was not found." 
            << std::endl << " See documentation for further details";
}