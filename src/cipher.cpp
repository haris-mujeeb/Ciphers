/**
 * @file morse_encoder_decoder.cpp
 * @brief Implementation of Morse code encoding and decoding functions.
 * 
 * This file contains the main function that processes command-line arguments to encode
 * or decode text using selected cipher. The program reads input from a file,
 * processes it, and writes the result to an output file.
 * 
 * @version 1.0
 * @date 07-07-2024
 * 
 * @license MIT License
 * 
 * @author Muhammad Haris Mujeeb
 */

#include <iostream>
#include <chrono>
#include "ciphers.hpp"

/**
 * @brief Processes Morse code encoding or decoding based on the action provided.
 * 
 * @param action The action to perform: "encode" or "decode".
 * @param inputfileName The name of the input file containing the text to process.
 * @param outputFileName The name of the output file to save the processed text.
 * @throws std::runtime_error if the action is not recognized.
 */
void processMorseCipher(const std::string& action, const std::string& inputfileName, const std::string& outputFileName);


/**
 * @brief Processes Caesar cipher encoding or decoding based on the action provided.
 * 
 * @param action The action to perform: "encode" or "decode".
 * @param shift The number of positions to shift for encoding/decoding.
 * @param inputfileName The name of the input file containing the text to process.
 * @param outputFileName The name of the output file to save the processed text.
 * @throws std::runtime_error if the action is not recognized.
 */
void processCaeserCipher(const std::string& action, const std::string& shiftBy, 
                            const std::string& inputfileName, const std::string& outputFileName);


int main(int argc, char* argv[]) {
    auto start = std::chrono::high_resolution_clock::now();
    try {
        if (argc < 3) {
            std::cerr << "Usage: " << argv[0] << " <cipher> <action> [shift] <inputfile> <outputfile> " << std::endl;
            return 1;
        }
        else {
            std::string cipherType = argv[1];
            if ( cipherType == "morse") {
                if (argc == 4 ) {
                    std::string defaultName = "output.txt";
                    std::cout << "Warning: No output file name give. Using default output file name as 'output.txt'" << std::endl;
                    processMorseCipher ( argv[2], argv[3], defaultName );
                } else if (argc == 5) processMorseCipher ( argv[2], argv[3], argv[4] );
                else throw std::runtime_error("Error: too many arguments");
            }
            else if ( cipherType == "caeser" ) {
                if ( argc == 5 ) {
                    std::string defaultName = "output.txt";
                    std::cout << "Warning: No output file name give. Using default output file name as 'output.txt'" << std::endl;
                    processCaeserCipher ( argv[2], argv[3], argv[4], defaultName );
                } else if ( argc == 6) processCaeserCipher ( argv[2], argv[3], argv[4], argv[5] );
                else throw std::runtime_error("Error: too many arguments");
            } 
            else {
                std::cerr << "Error: Unknown cipher type '" << cipherType << "'." << std::endl;
                throw std::runtime_error("Invalid action for caesar cipher");
            }
        }
    } catch (const std::runtime_error& error) {
        std::cerr << error.what() << std::endl; 
        return 1;
    } 

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Elapsed time: " << elapsed_seconds.count() << " seconds\n";
    return 0;
}


void processMorseCipher(const std::string& action, const std::string& inputfileName, const std::string& outputFileName) {    
    ciphers::Morse myCipherEngine;              
    if (action == "encode") {
        std::string text = myCipherEngine.readFromFile(inputfileName);
        std::string encoded = myCipherEngine.encoder(text);
        myCipherEngine.writeToFile(encoded, outputFileName);
    } else if (action == "decode") {
        std::string text = myCipherEngine.readFromFile(inputfileName);
        std::string decoded = myCipherEngine.decoder(text);
        myCipherEngine.writeToFile(decoded, outputFileName);
    } else {
        std::cerr << "Error: Unknown action '" << action << "' for morse cipher." << std::endl;
        throw std::runtime_error("Invalid action for morse cipher");
    }
    std::cout << "'" << inputfileName << "' " << action << "d to '" << outputFileName <<"' using morse cipher" << std::endl;
}


void processCaeserCipher(const std::string& action, const std::string& shift, const std::string& inputfileName, const std::string& outputFileName) {    
    int shiftBy;
    try {
        shiftBy = std::stoi(shift);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: Invalid shift value." << std::endl;
        throw std::runtime_error("Invalid shift value for caesar cipher");
    }
    
    ciphers::Caeser myCipherEngine;
    if (action == "encode") {
        std::string text = myCipherEngine.readFromFile(inputfileName);
        std::string encoded = myCipherEngine.encoder(text, shiftBy);
        myCipherEngine.writeToFile(encoded, outputFileName);
    } else if (action == "decode") {
        std::string text = myCipherEngine.readFromFile(inputfileName);
        std::string decoded = myCipherEngine.decoder(text, shiftBy);
        myCipherEngine.writeToFile(decoded, outputFileName);
    } else {
        std::cerr << "Error: Unknown action '" << action << "' for caeser cipher." << std::endl;
        throw std::runtime_error("Invalid action for caesar cipher");
    }
    std::cout << "'" << inputfileName << "' " << action << "d to '" << outputFileName <<"' using morse cipher" << std::endl;
}
