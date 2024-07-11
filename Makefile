CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:=
EXECUTABLE	:= cipher


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

testMorseEncode: $(BIN)/cipher
	$(BIN)/cipher morse encode testData.txt encodedData.txt

testMorseDecode: $(BIN)/cipher
	$(BIN)/cipher morse decode encodedData.txt decodedData.txt
	
testCaeserEncode: $(BIN)/cipher
	$(BIN)/cipher caeser encode 5 testData.txt encodedData.txt


testCaeserDecode: $(BIN)/cipher
	$(BIN)/cipher caeser decode 5 encodedData.txt decodedData.txt


clean:
	-rm $(BIN)/*
