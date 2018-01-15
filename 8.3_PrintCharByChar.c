//Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long copyArgumentAndPrintCharByCharReturningSumOfArguments(void* data, size_t sizeOfData)
{
  char *table = (char*)malloc(sizeOfData);
  table = (char*)memcpy((char*)table,(char*)data,sizeOfData);
  long long sum = 0;
  for(int i=0;i<(sizeOfData/sizeof(char))-sizeof(char);++i)
  {
    printf("%x\n",table[i]);
    sum += table[i];
  }
  return sum;
}

int main(void)
{
  char text[] = "Hello world!\n";
  printf("\nSuma: %lld",copyArgumentAndPrintCharByCharReturningSumOfArguments((char*)text,sizeof(text)));
  return 0;
}
