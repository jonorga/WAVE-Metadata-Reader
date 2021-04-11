/*
The purpose of this program is to read the meta data on a WAVE file.
*/
#include "MetadataReader.hpp"


int main () {
	uint32_t fileSize, mdata_size;
	uint16_t digital_fmt, num_of_channels;
	uint32_t sample_rate, bps; // bps = Bytes/Second
	uint16_t bytes_p_sample, bytes_p_channel;
	uint32_t chunk_2_size;

	// Opens a WAVE file in the local folder called "test.wav" and gets the length
	std::fstream input_stream;
	input_stream.open("test.wav", std::fstream::in);
	input_stream.seekg(0, input_stream.end);
	int length = input_stream.tellg();
	input_stream.seekg(0, input_stream.beg);

	// Read data into pointer buffer
	char * file_buf = new char [4];
	char * size_buf = new char [4];
	char * file_type_buf = new char [4];
	char * chunk_mrkr_1_buf = new char [4];
	char * mdata_size_buf = new char [4];
	char * digital_fmt_buf = new char [2];
	char * num_of_channels_buf = new char [2];
	char * sample_rate_buf = new char [4];
	char * bps_buf = new char [4];
	char * bytes_p_sample_buf = new char [2];
	char * bytes_p_channel_buf = new char [2];
	char * chunk_mrkr_2_buf = new char [4];
	char * chunk_2_size_buf = new char [4];

	input_stream.read(file_buf, 4);
	input_stream.read(size_buf, 4);
	input_stream.read(file_type_buf, 4);
	input_stream.read(chunk_mrkr_1_buf, 4);
	input_stream.read(mdata_size_buf, 4);
	input_stream.read(digital_fmt_buf, 2);
	input_stream.read(num_of_channels_buf, 2);
	input_stream.read(sample_rate_buf, 4);
	input_stream.read(bps_buf, 4);
	input_stream.read(bytes_p_sample_buf, 2);
	input_stream.read(bytes_p_channel_buf, 2);
	input_stream.read(chunk_mrkr_2_buf, 4);
	input_stream.read(chunk_2_size_buf, 4);

	// Transfer pointer into 32 bit number
	memcpy(&fileSize, size_buf, 4);
	memcpy(&mdata_size, mdata_size_buf, 4);
	memcpy(&digital_fmt, digital_fmt_buf, 2);
	memcpy(&num_of_channels, num_of_channels_buf, 2);
	memcpy(&sample_rate, sample_rate_buf, 4);
	memcpy(&bps, bps_buf, 4);
	memcpy(&bytes_p_sample, bytes_p_sample_buf, 2);
	memcpy(&bytes_p_channel, bytes_p_channel_buf, 2);
	memcpy(&chunk_2_size, chunk_2_size_buf, 4);

	// Print out read data, and buffer length
	std::cout << "Length: " << length << std::endl;
	std::cout << "File Format: " << file_buf << std::endl;
	std::cout << "File size: " << fileSize << std::endl;
	std::cout << "File type: " << file_type_buf << std::endl;
	std::cout << "Chunk marker: " << chunk_mrkr_1_buf << std::endl;
	std::cout << "Metadata size: " << mdata_size << std::endl;
	std::cout << "Encoding format: " << digital_fmt << std::endl;
	std::cout << "Number of channels: " << num_of_channels << std::endl;
	std::cout << "Sample rate: " << sample_rate << std::endl;
	std::cout << "Bytes/second: " << bps << std::endl;
	std::cout << "Bytes/sample: " << bytes_p_sample << std::endl;
	std::cout << "Bits/channel: " << bytes_p_channel << std::endl;
	std::cout << "Chunk 2 marker: " << chunk_mrkr_2_buf << std::endl;
	std::cout << "Chunk 2 size: " << chunk_2_size << std::endl; // Size reads out in bytes


	return 0;
}