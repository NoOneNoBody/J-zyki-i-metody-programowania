/*Wykona³ Micha³ Warzecha I rok Informatyka EAIIB grupa 6b*/
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void Losuj(int tablica[])
{
  srand(time(NULL));
  for(int i=0;i<10;i++)
  {
    tablica[i]=rand()%100;
  }
}

void Sortowanie(int *wskazniki[])
{
  int sorted=0;
  int *tmp;
  for(int i=0;i<10;i++)
  {
    sorted=1;
    for(int j=0;j<9-i;j++)
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

void Wyswietl(int tablica[])
{
  for(int i=0;i<10;i++)
  {
    printf("%d ",tablica[i]);
  }
  printf("\n");
}

void Wyswietl_wskazniki(int *wskazniki[])
{
  for(int i=0;i<10;i++)
  {
    printf("%d ",*wskazniki[i]);
  }
  printf("\n");
}

int main(void)
{
  int tablica[10];
  Losuj(tablica);
  int *wskazniki[10];
  for(int i=0;i<10;i++)
  {
    wskazniki[i] = &tablica[i];
  }
  printf("Wylosowana tablica:\n");
  Wyswietl(tablica);
  Sortowanie(wskazniki);
  printf("Posortowana tablica wskaznikow:\n");
  Wyswietl_wskazniki(wskazniki);
  printf("Nienaruszona oryginalna tablica:\n");
  Wyswietl(tablica);

  return 0;
}
