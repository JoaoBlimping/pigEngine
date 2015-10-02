#include "Utils.hh"


char * Utils::concatenate(char const * a,char const * b)
{
  //get the length of the strings
  int aLength;
  int bLength;
  for (aLength = 0;a[aLength] != '\0';aLength++);
  for (bLength = 0;b[bLength] != '\0';bLength++);

  //create a new array that can fit in everyone
  char * output = new char[aLength + bLength + 1];

  //put in all of the letters
  for (int i = 0;i < aLength;i++)
  {
    output[i] = a[i];
  }
  for (int i = 0;i < bLength;i++)
  {
    output[aLength + i] = b[i];
  }

  //add the end of line thingo
  output[aLength + bLength] = '\0';

  return output;
}
