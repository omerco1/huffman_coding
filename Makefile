CC=g++
CPPFLAGS=-g -std=c++11

TARGETS = frequencies huffman encode decode

.PHONY: all

all:
	$(CC) $(CPPFLAGS) huffman.cpp -o huffman
	$(CC) $(CPPFLAGS) encode.cpp -o encode
	$(CC) $(CPPFLAGS) decode.cpp -o decode
	$(CC) $(CPPFLAGS) frequencies.cpp -o frequencies

clean:
	rm -f $(TARGETS)
	rm -f *.o
