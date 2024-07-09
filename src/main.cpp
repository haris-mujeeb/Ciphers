/**
 * @file morse_encoder_decoder.cpp
 * @brief Implementation of Morse code encoding and decoding functions.
 * see the complete version on 'https://github.com/haris-mujeeb/MorseCode/'
 * @author Muhammad Haris Mujeeb
 * @date 07-07-2024
 */
#include <iostream>
#include "ciphers.hpp"

int main(int argc, char* argv[]) {
    // ciphers::Morse myCipherEngine; 
    ciphers::Caeser myCipherEngine; 
    try {
        // if (argc < 2) {
        //     std::cerr << "Error: Please provide an executable file argument." << std::endl;
        // return 1;
        // }
        // else {
        
            // std::string  text = "Hello Easy C++ project!";
            // std::string  encoded = myCipherEngine.encoder(text);
            // std::string  decoded = myCipherEngine.decoder(encoded); 
            // std::cout << text << std::endl;
            // std::cout << encoded << std::endl;
            // std::cout << decoded << std::endl;

            std::string inputfileName = "testData.txt";
            std::string outputFileName = "encodedData.txt";
            // std::string inputfileName = argv[1];
            // std::string outputFileName = argv[2];

            std::string text = myCipherEngine.readFromFile(inputfileName);
            // std::string encoded = myCipherEngine.encoder(text);
            std::string encoded = myCipherEngine.encoder(text, 5);
            myCipherEngine.writeToFile(encoded, outputFileName);

            std::string encodedText = myCipherEngine.readFromFile(outputFileName);
            // std::string  decodedText = myCipherEngine.decoder(encodedText); 
            std::string  decodedText = myCipherEngine.decoder(encodedText, 5); 
            myCipherEngine.writeToFile(decodedText, "decodedData.txt");
        // }
    } catch (const std::runtime_error& error) {
        std::cerr << error.what() << std::endl; 
    }
}