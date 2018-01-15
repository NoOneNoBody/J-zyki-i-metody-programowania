/*Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b
Liczenie wyznacznika macierzy */
#include<stdio.h>
#include <time.h>
#include <stdlib.h>

int Wyznacznik_macierzy(int macierz[3][3])
{
  int wyznacznik = 0;
  int iloczyn = 1;

  for(int i=0;i<3;i++)
  {
    iloczyn = 1;
    for(int j=0;j<3;j++)
    {
      iloczyn *= macierz[j][(j+i)%3];
    }
    wyznacznik += iloczyn;
  }

  for(int i=0;i<3;i++)
  {
    iloczyn = 1;
    for(int j=0;j<3;j++)
    {
      iloczyn *= macierz[j][(5-(j+i))%3];
    }
    wyznacznik -= iloczyn;
  }
  return wyznacznik;
}

void Losowanie_macierzy(int macierz[3][3])
{
  srand(time(NULL));
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      macierz[i][j] = rand() % 11;
      printf("%2d ",macierz[i][j]);
    }
    printf("\n");
  }
}

int main(void)
{
  int macierz[3][3];
  Losowanie_macierzy(macierz);
  int wyznacznik = Wyznacznik_macierzy(macierz);
  printf("Wyznacznik wynosi %d\n",wyznacznik);
  return 0;
}
