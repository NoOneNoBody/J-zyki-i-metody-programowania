/*Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b
Mnożenie macierzy */
#include<stdio.h>
#include <time.h>
#include <stdlib.h>

void Mnorzenie_macierzy(const int rozmiar,int macierz[rozmiar][rozmiar][rozmiar], int wynik[rozmiar][rozmiar])
{
  for(int i=0;i<rozmiar;i++)
  {
    for(int j=0;j<rozmiar;j++)
    {
      wynik[i][j] = macierz[i][0][0]*macierz[0][j][1]+macierz[i][1][0]*macierz[1][j][1];
    }	
  }
}

void Generuj_macierz(const int rozmiar, int macierz[rozmiar][rozmiar])
{
  for(int i=0;i<rozmiar;i++)
  {
    for(int j=0;j<rozmiar;j++)
    {
      macierz[i][j] = (rand() % 201)-100;
      printf("%4d ",macierz[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void Laczenie_macierzy(const int rozmiar, int macierzA[rozmiar][rozmiar], int macierzB[rozmiar][rozmiar], int macierz_polaczona[rozmiar][rozmiar][rozmiar])
{
  for(int i=0;i<rozmiar;i++)
  {
    for(int j=0;j<rozmiar;j++)
    {
      for(int k=0;k<rozmiar;k++)
      {
        if(k == 0)
        {
          macierz_polaczona[i][j][k] = macierzA[i][j];
        }
        else
        {
          macierz_polaczona[i][j][k] = macierzB[i][j];
        }
      }
    }
  }
}

void Wyswietl_macierz_2na2(int macierz[2][2])
{
  printf("%6d %6d\n%6d %6d\n", macierz[0][0], macierz[0][1], macierz[1][0], macierz[1][1]);
}

int main(void)
{
  srand(time(NULL));
  int macierz1[2][2];
  int macierz2[2][2];
  int macierz_polaczona[2][2][2];
  int wynik[2][2];
  const int rozmiar = sizeof(macierz1)/sizeof(macierz1[0]);
  printf("Pierwsza macierz:\n");
  Generuj_macierz(rozmiar,macierz1);
  printf("Druga macierz:\n");
  Generuj_macierz(rozmiar,macierz2);
  Laczenie_macierzy(rozmiar,macierz1,macierz2,macierz_polaczona);
  Mnorzenie_macierzy(rozmiar,macierz_polaczona,wynik);
  printf("Wynikowa macierz:\n");
  Wyswietl_macierz_2na2(wynik);
  return 0;
}
