/*Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void Wypisz_dane(int ilosc,int dane[])
{
  printf("Podane dane to:\n");
  for(int i=0;i<ilosc;++i)
  {
    printf("%d ",dane[i]);
  }
  printf("\n");
}

void Wypisz_tekst_pobierz_dane(char tekst[])
{
  int ilosc=0;
  int i=0;
  while(tekst[i] != '\0')
  {
    if(tekst[i] == '%' && tekst[i+1] == 'd')
    {
      ++ilosc;
    }
    ++i;
  }
  int dane[ilosc];
  ilosc=0;
  i=0;
  while(tekst[i] != '\0')
  {
    if(tekst[i] == '%' && tekst[i+1] == 'd')
    {
      scanf("%d",&dane[ilosc]);
      ++ilosc;
      i+=2;
      continue;
    }
    printf("%c",tekst[i]);
    ++i;
  }
  Wypisz_dane(ilosc, dane);
}

int main(void)
{
  char tekst[] = "Zmienna 1: %d \ndruga zmienna: %d \ntrzecia: %d\n";
  Wypisz_tekst_pobierz_dane(tekst);
  return 0;
}
