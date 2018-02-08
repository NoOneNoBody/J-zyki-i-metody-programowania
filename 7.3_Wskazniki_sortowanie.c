/*Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b*/
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void Losuj(int tablica[], int rozmiar)
{
  srand(time(NULL));
  for(int i=0;i<rozmiar;++i)
  {
    tablica[i] = rand()%100;
  }
}

void Sortowanie(int *wskazniki[], int rozmiar)
{
  int sorted = 0;
  int *tmp;
  for(int i=0;i<rozmiar;++i)
  {
    sorted = 1;
    for(int j=0;j<rozmiar-1-i;++j)
    {
      if(*wskazniki[j]>*wskazniki[j+1])
      {
        sorted = 0;
        tmp = wskazniki[j+1];
        wskazniki[j+1]=wskazniki[j];
        wskazniki[j]=tmp;
      }
    }
    if(sorted)
    {
      break;
    }
  }
}

void Wyswietl(int tablica[], int rozmiar)
{
  for(int i=0;i<rozmiar;++i)
  {
    printf("%d ",tablica[i]);
  }
  printf("\n");
}

void Wyswietl_wskazniki(int *wskazniki[], int rozmiar)
{
  for(int i=0;i<rozmiar;++i)
  {
    printf("%d ",*wskazniki[i]);
  }
  printf("\n");
}

void Kopiuj_wskazniki(int tablica[], int *wskazniki[], int rozmiar)
{
  for(int i=0;i<rozmiar;++i)
  {
    wskazniki[i] = &tablica[i];
  }
}

int main(void)
{
  int tablica[10];
  int rozmiar = sizeof(tablica)/sizeof(tablica[0]);
  Losuj(tablica, rozmiar);
  int *wskazniki[10];
  Kopiuj_wskazniki(tablica, wskazniki, rozmiar);
  printf("Wylosowana tablica:\n");
  Wyswietl(tablica, rozmiar);
  Sortowanie(wskazniki, rozmiar);
  printf("Posortowana tablica wskaznikow:\n");
  Wyswietl_wskazniki(wskazniki, rozmiar);
  printf("Nienaruszona oryginalna tablica:\n");
  Wyswietl(tablica, rozmiar);

  return 0;
}
