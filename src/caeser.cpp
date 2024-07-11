/**
 * @file caeser.cpp
 * @brief Implementation of Caeser code encoding and decoding functions.
 *
 * This file contains functions to encode a string to Caeser code and decode
 * a Caeser code string back to its original representation.
 * 
 * @author Syed Muhammad Haider Rizvi 
 * @date 07-07-2024
 */

#include "caeser.hpp"

std::string ciphers::Caeser::encoder( const std::string input_message, int shiftBy) {
    std::string encoded_message;
    unsigned char eholder;
    std::string Fencoded;
    for (unsigned char ch : input_message) {
        if(int(ch) <= 32 && int(ch) >= 126)
            throw std::runtime_error( "Restricted character used in text!");
        if (ch != ' ') {
            eholder = std::toupper(ch); // Convert to uppercase
            eholder = char(int(eholder) + shiftBy);
        } else  {eholder = ' ';}
        encoded_message.push_back(eholder);
    }
     for(unsigned char ch : encoded_message){
        if (ch != ' ') {
            eholder= std::toupper(ch);
            Fencoded.push_back(eholder);
        }
    }
    return encoded_message;
}


std::string ciphers::Caeser::decoder( const std::string istring, int shiftBy) {     
        std::string decoded;
        char dholder;
        std::string Fdecoded;
        for (unsigned char ch : istring) {
            if(int(ch) <= 32 && int(ch) >= 126)
                throw std::runtime_error( "Restricted character used in text!");
            if (ch != ' ') {
                dholder = char(int(ch) - shiftBy);
            } else {dholder = ' ';}
            decoded.push_back(dholder);
        }
        for(char ch : decoded){
             if (ch != ' ') {
            dholder = std::toupper(ch);
            } else {dholder = ' ';}
            Fdecoded.push_back(dholder);
        }
        return Fdecoded;
}
