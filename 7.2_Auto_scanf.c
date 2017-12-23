#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void auto_scanf(char tekst[],int ilosc, ...)
{
  va_list vl;
  va_start(vl,ilosc);
  int i=0;
  while(tekst[i] != '\0')
  {
    if(tekst[i] == '%' && tekst[i+1] == 'd')
    {
      int d = va_arg(vl,int);
      printf("%d",d);
      i+=2;
      continue;
    }
    printf("%c",tekst[i]);
    i++;
  }
  va_end(vl);
}

int main()
{
  char tekst[] = "Zmienna 1: %d \ndruga zmienna: %d \ntrzecia: %d\n";
  auto_scanf(tekst,4,4,2,0,10);
  return 0;
}
