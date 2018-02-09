/*Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b
Porównyanie czasu */
#include<stdio.h>

int Porownaj_czas(int pierwszy_czas[3], int drugi_czas[3])
{
  const int ilosc_elementow_czasu = 3;
  for(int i=0;i<ilosc_elementow_czasu;i++)
  {
    if(pierwszy_czas[i] > drugi_czas[i])
    {
      return -1;
    }
    else if(pierwszy_czas[i] < drugi_czas[i])
    {
      return 1;
    }
  }
  return 0;
}

int Zapytaj_o_czas(char* nazwa_jednostki, char* nazwa_numeru, int max)
{
  int czas = max;
  do
  {
    printf("Podaj %s %s czasu: ",nazwa_jednostki,nazwa_numeru);
    scanf("%d",&czas);
  } while(czas >= max || czas < 0);
  return czas;
}

void Wczytaj_czas(int czas[3])
{
  czas[0] = Zapytaj_o_czas("godziny","pierwszego",24);
  czas[1] = Zapytaj_o_czas("minuty","pierwszego",60);
  czas[2] = Zapytaj_o_czas("sekundy","pierwszego",60);
}

void Wypisz_wynik(int pierwszy_czas[3], int drugi_czas[3], int wynik)
{
  switch(wynik)
  {
    case -1:
      printf("Czas %d2:%d2:%d2 jest wiekszy niż %d2:%d2:%d2\n",pierwszy_czas[0],pierwszy_czas[1],pierwszy_czas[2],drugi_czas[0],drugi_czas[1],drugi_czas[2]);
      break;
    case 0:
      printf("Czas %d2:%d2:%d2 jest równy %d2:%d2:%d2\n",pierwszy_czas[0],pierwszy_czas[1],pierwszy_czas[2],drugi_czas[0],drugi_czas[1],drugi_czas[2]);
      break;
    case 1:
      printf("Czas %d2:%d2:%d2 jest wiekszy niż %d2:%d2:%d2\n",drugi_czas[0],drugi_czas[1],drugi_czas[2],pierwszy_czas[0],pierwszy_czas[1],pierwszy_czas[2]);
      break;
  }
}

int main(void)
{
  int pierwszy_czas[3];
  int drugi_czas[3];
  Wczytaj_czas(pierwszy_czas);
  Wczytaj_czas(drugi_czas);
  int wynik = Porownaj_czas(pierwszy_czas,drugi_czas);
  Wypisz_wynik(pierwszy_czas,drugi_czas,wynik);
  return 0;
}
