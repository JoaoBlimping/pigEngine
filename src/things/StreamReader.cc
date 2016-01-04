#include "StreamReader.hh"

#include <stdio.h>


#define TOKEN_BUFFER_SIZE 64


StreamReader(char const * filename)
{
	inputFile = fopen(filename);
}


~StreamReader()
{
	fclose(inputFile);
}


char * readToken()
{
	bool started = false;
	int charIndex = 0;
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

	

}


int readInt()
{

}
