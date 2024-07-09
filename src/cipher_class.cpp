#include "cipher_class.hpp"

std::string ciphers::Cipher::readFromFile( const std::string& fileName) {
    std::string fileContent;
    std::ifstream file(fileName);
    if (file.is_open()) {
        std::getline(file, fileContent);
        file.close();
        return fileContent;
    } else {
        throw std::runtime_error ("Error: Could not open file '" + fileName + "'." );
    }
}

void ciphers::Cipher::writeToFile( const std::string& fileContent, const std::string& fileName) {
    std::ofstream outputFile(fileName);
    if (outputFile.is_open()) {
        outputFile << fileContent << std::endl;
        outputFile.close();
    } else {
        throw std::runtime_error ( "Error: Could not create output file '" + fileName + "'." );
    }
}