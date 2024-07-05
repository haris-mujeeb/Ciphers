# Morse Code Encoder Decoder
A MorseCode class, which provides methods to encode text to Morse code and decode a Morse code string back to text.
Read documentation inside the header files for further explaination.

**Example code:**
```C++
#include <iostream>
#include <string>
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
```

**Output:**
```
Original text: Hello My C++ project!
Encoded text: .... . .-.. .-.. ---   -- -.--   -.-. ? ?   .--. .-. --- .--- . -.-. - ?
Decoded text: HELLO MY C?? PROJECT?

Note: '?' means corresponding character was not found.
See documentation for further details
```
