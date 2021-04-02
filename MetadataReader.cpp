/*
The purpose of this program is to read the meta data on a WAVE file.
*/
#include "MetadataReader.hpp"


int main () {
	// Opens a WAVE file in the local folder called "test.wav" and gets the length
	std::fstream input_stream;
	input_stream.open("test.wav", std::fstream::in);
	input_stream.seekg(0, input_stream.end);
	int length = input_stream.tellg();
	input_stream.seekg(0, input_stream.beg);

	// Read data into pointer buffer
	char * buf = new char [length];
	input_stream.read(buf, length);

	// Print out read data, and buffer length
	std::cout << "Length: " << length << std::endl << buf << std::endl;

	return 0;
}