/*Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b
Mnożenie macierzy */
#include<stdio.h>
#include <time.h>
#include <stdlib.h>

void Mnorzenie_macierzy_2na2(int macierz[2][2][2], int wynik[2][2])
{
  for(int i=0;i<2;i++)
  {
    for(int j=0;j<2;j++)
    {
      wynik[i][j] = macierz[i][0][0]*macierz[0][j][1]+macierz[i][1][0]*macierz[1][j][1];
    }	
  }
}

void Generuj_macierz(int macierz[2][2], int rozmiar)
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

void Laczenie_macierzy_2na2(int macierzA[2][2], int macierzB[2][2], int macierz_polaczona[2][2][2])
{
  for(int i=0;i<2;i++)
  {
    for(int j=0;j<2;j++)
    {
      for(int k=0;k<2;k++)
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
  const int rozmiar = 2;
  printf("Pierwsza macierz:\n");
  Generuj_macierz(macierz1,rozmiar);
  printf("Druga macierz:\n");
  Generuj_macierz(macierz2,rozmiar);
  Laczenie_macierzy_2na2(macierz1,macierz2,macierz_polaczona);
  Mnorzenie_macierzy_2na2(macierz_polaczona, wynik);
  printf("Wynikowa macierz:\n");
  Wyswietl_macierz_2na2(wynik);
  return 0;
}
