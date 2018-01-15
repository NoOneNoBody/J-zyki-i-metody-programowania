//Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

enum ArgumentType{INT,DOUBLE,STRING,CHAR};

int doubleDecimalLength(double value)
{
  if((int)(value*100.0)%100 == 0)
  {
    return 0;
  }
  else if((int)(value*100.0)%10 == 0)
  {
    return 2;
  }
  else
  {
    return 3;
  }
}

void printSpaces(int spacesCount)
{
  for(int i=0;i<spacesCount;++i)
  {
    printf(" ");
  }
}

void printInt(int value)
{
  printf("%d",value);
}

void printDouble(double value)
{
  switch(doubleDecimalLength(value))
  {
    case 0:
    {
      printf("%.0f",value);
      break;
    }
    case 2:
    {
      printf("%.1f",value);
      break;
    }
    case 3:
    {
      printf("%.2f",value);
      break;
    }
  }
}

void printString(char *value)
{
  printf("%s",value);
}

void printChar(char value)
{
  printf("%c",value);
}

int checkLength(void* argument, enum ArgumentType type)
{
  int length = 0;
  switch(type)
  {
    case INT:
    {
      length = (int)log10(*(int*)argument);
      break;
    }
    case DOUBLE:
    {
      length = (int)log10((int)(*(double*)argument))+doubleDecimalLength(*(double*)argument);
      break;
    }
    case STRING:
    {
      length = strlen((char*)argument);
      break;
    }
    case CHAR:
    {
      if(isprint(*(char*)argument))
      {
        length = 1;
      }
      else
      {
        length = 0;
      }
      break;
    }
  }
  return length;
}

void printArgument(void* argument, enum ArgumentType type)
{
  switch(type)
  {
    case INT:
    {
      printInt(*(int*)argument);
      break;
    }
    case DOUBLE:
    {
      printDouble(*(double*)argument);
      break;
    }
    case STRING:
    {
      printString((char*)argument);
      break;
    }
    case CHAR:
    {
      if(isprint(*(char*)argument))
      {
        printChar(*(char*)argument);
      }
      break;
    }
  }
}

int printArgumentInTheMiddle(void* argument, enum ArgumentType type, unsigned width)
{
  int startPosition = 0;
  int length = checkLength(argument,type);
  startPosition = (int)width/2-((length+1)/2);
  if(startPosition<0)
  {
    startPosition = 0;
  }
  printSpaces(startPosition);
  printArgument(argument,type);
  printSpaces(width-startPosition-length);
  printf("\n");
}

int main(void)
{
  int a = 1234;
  double b = 32115.124;
  char *text = "Ala ma kota";
  char character = 'A';
  printArgumentInTheMiddle(&a,INT,20);
  printArgumentInTheMiddle(&b,DOUBLE,20);
  printArgumentInTheMiddle(text,STRING,20);
  printArgumentInTheMiddle(&character,CHAR,20);
  return 0;
}
