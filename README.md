# Synopsis
```
chiper <cipherType> <action> [shiftBy] <inputfile> [outputfile]
```

# Description
This program performs encoding and decoding of text using different cipher techniques. It reads input text from a file, processes it based on the specified action (encode or decode), and writes the result to an output file.

**Example code:**
encode a text file using morse cipher (name for output file is optional): 
```
cipher morse encode testData.txt outputData.txt 
```
decode a text file using morse cipher:
```
cipher morse decode outputData.txt 
```

encode a text file using caeser cipher and exporting it to a specified outputfile:
```
cipher caeser 5 encode testData.txt encodedData.txt
```
decode a text file using caeser cipher: 
```
cipher caeser 5 decode encodedData.txt decodedData.txt 
```

**Output for Morse:**
```
Original text: Hello My C++ project!
Encoded text: .... . .-.. .-.. ---   -- -.--   -.-. ? ?   .--. .-. --- .--- . -.-. - ?
Decoded text: HELLO MY C?? PROJECT?

Note: '?' means corresponding character was not found.
See documentation for further details
```

**Output for Caeser:**
```
Original text: Hello My CPP project
Encoded text: ROVVY Wc M Z\YTOM^
Decoded text: HELLO MY CPP PROJECT
```

# Authors
- Muhammad Haris Mujeeb (https://github.com/haris-mujeeb)
- Syed Muhammad Haider Rizvi
