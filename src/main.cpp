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

    try {
        if (argc < 2) {
            std::cerr << "Error: Please provide an executable file argument." << std::endl;
        return 1;
        }
        else {
        
            // std::string  text = "Hello Easy C++ project!";
            // std::string  encoded = myCipherEngine.encoder(text);
            // std::string  decoded = myCipherEngine.decoder(encoded); 
            // std::cout << text << std::endl;
            // std::cout << encoded << std::endl;
            // std::cout << decoded << std::endl;

            // std::string inputfileName = "testData.txt";
            // std::string outputFileName = "encodedData.txt";
            std::string inputfileName;
            std::string outputFileName;
                    
            if (argv[1] == "morse") {
                ciphers::Morse myCipherEngine;
                inputfileName = argv[3];
                outputFileName = argv[4];                
                if (argv[2] == "encode") {
                    std::string text = myCipherEngine.readFromFile(inputfileName);
                    std::string encoded = myCipherEngine.encoder(text);
                    myCipherEngine.writeToFile(encoded, outputFileName);
                } else if (argv[2] == "decode") {
                    std::string text = myCipherEngine.readFromFile(inputfileName);
                    std::string decoded = myCipherEngine.decoder(text);
                    myCipherEngine.writeToFile(decoded, outputFileName);
                }
            } else if (argv[1] == "caeser") {
                ciphers::Caeser myCipherEngine;
                inputfileName = argv[4];
                outputFileName = argv[5];
                int shiftBy = std::stoi(argv[2]);
                if (argv[2] == "encode") {
                    std::string text = myCipherEngine.readFromFile(inputfileName);
                    std::string encoded = myCipherEngine.encoder(text, shiftBy);
                    myCipherEngine.writeToFile(encoded, outputFileName);
                } else if (argv[2] == "decode") {
                    std::string text = myCipherEngine.readFromFile(inputfileName);
                    std::string decoded = myCipherEngine.decoder(text, 5);
                    myCipherEngine.writeToFile(decoded, outputFileName);
                }
            }


        //     std::string text = myCipherEngine.readFromFile(inputfileName);
        //     // std::string encoded = myCipherEngine.encoder(text);
        //     std::string encoded = myCipherEngine.encoder(text, 5);
        //     myCipherEngine.writeToFile(encoded, outputFileName);

        //     std::string encodedText = myCipherEngine.readFromFile(outputFileName);
        //     // std::string  decodedText = myCipherEngine.decoder(encodedText); 
        //     std::string  decodedText = myCipherEngine.decoder(encodedText, 5); 
        //     myCipherEngine.writeToFile(decodedText, "decodedData.txt");
        }
    } catch (const std::runtime_error& error) {
        std::cerr << error.what() << std::endl; 
    }
}