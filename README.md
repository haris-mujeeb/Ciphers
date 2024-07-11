# Synopsis
run the 'chiper.exe' (found inside build folder) using following command syntax:
``` shell
chiper <cipherType> <action> [shiftBy] <inputfile> [outputfile]
```
Where, the command line arguments are:
* **cipherType**: Type of cipher to be used (e.g. ```morse```, ```caeser```, etc.)
* **action**: The action to perform encoding using ```encode``` or decoding using ```decode```
* **shift** (only for caeser): The number of positions to shift for encoding/decoding using caeser cipher.
* **inputfile**: The name of the input file containing the text to process.
* **outputfile** (optional): The name of the output file to save the processed text (default name is ```'output.txt'```).
  
# MakeFile
- use ```make``` command for compiling the project.
- use ```make clean``` command for deleteing all generated binary files.
- Some commands for testing are also included in the makefile:
  - For example, use ```make testMorseEncode``` for running following tasks:
  ```shell
  cipher morse encode testData.txt encodedData.txt
  ```
  - For example, use ```make testMorseEncode``` for running following tasks:
  ```shell
  cipher morse decode encodedData.txt decodedData.txt
  ```
  - For example, use ```make testCaeserEncode``` for running following tasks:
  ```shell
  cipher caeser encode 5 testData.txt encodedData.txt
  ```
  - For example, use ```make testCaeserDecode``` for running following tasks:
  ```shell
  cipher caeser decode 5 encodedData.txt decodedData.txt
  ```

# Description
This program performs encoding and decoding of text using different cipher techniques. It reads input text from a file, processes it based on the specified action (encode or decode), and writes the result to an output file.
## Example code:
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
- Syed Muhammad Haider Rizvi (https://github.com/haider-rizvi-github)
