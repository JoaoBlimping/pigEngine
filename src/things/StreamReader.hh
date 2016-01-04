#ifndef STREAM_READER_H
#define STREAM_READER_H


#include <stdio.h>


/** reads tokens from a stream, and can read them in different ways for you ;) */
class StreamReader
{
public:
	/** create the stream reader to read a file */
	StreamReader(char const * filename);

	/** closes the file it's reading from */
	~StreamReader();

	/** read a string of characters */
	char * readToken();

	/** read an integer */
	int readInt();

private:
	/** the file it reads from */
	FILE * inputFile;
};


#endif
