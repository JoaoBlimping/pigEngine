#include "StreamReader.hh"

#include <danylib/danylib.hh>

#include <stdio.h>
#include <cstdlib>
#include <ctype.h>


#define TOKEN_BUFFER_SIZE 128


StreamReader::StreamReader(char const * filename)
{
	inputFile = fopen(filename,"r");
}


StreamReader::~StreamReader()
{
	fclose(inputFile);
}


char * StreamReader::readToken()
{
	bool started = false;
	int charIndex = 0;
	char c;
	char token[TOKEN_BUFFER_SIZE];

	while ((c = fgetc(inputFile)) != EOF)
	{
		//if it is in the actual string
		if (started)
		{
			//if the new character is whitespace
			if (isspace(c)) break;

			//if it's a normal character
			token[charIndex] = c;
			charIndex++;
		}

		//if the token has not yet begun
		else if (!isspace(c))
		{
			started = true;
			token[charIndex] = c;
			charIndex++;
		}
	}
	token[charIndex] = '\0';
	return danylib_fit(token);
}


int StreamReader::readInt()
{
	char * token = readToken();
	int value = atoi(token);
	delete token;
	return value;
}


float StreamReader::readFloat()
{
	char * token = readToken();
	float value = atof(token);
	delete token;
	return value;
}
