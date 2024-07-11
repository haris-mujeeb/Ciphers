/**
 * @brief Abstract base class for encoding and decoding cyphers.
 */

#ifndef CYPHER_CLASS_H
#define CYPHER_CLASS_H

#include <string>
#include <fstream>
#include <stdexcept>

namespace ciphers {
class Cipher {
    public:
      virtual std::string encoder( const std::string& is) {return is;}; 
      virtual std::string encoder( const std::string& is, int ){return is;}; 
      virtual std::string decoder( const std::string& is) {return is;}; 
      virtual std::string decoder( const std::string& is, int ) {return is;}; 
      std::string readFromFile( const std::string& );
      void writeToFile( const std::string&, const std::string& );
  };
}
#endif // CYPHER_CLASS_H