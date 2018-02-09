/*Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b
Porównyanie czasu */
#include<stdio.h>

int Porownaj_czas(const int ilosc_elementow_czasu, int pierwszy_czas[ilosc_elementow_czasu], int drugi_czas[ilosc_elementow_czasu])
{
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

void Wczytaj_czas(int czas[3], char* nazwa)
{
  czas[0] = Zapytaj_o_czas("godziny",nazwa,24);
  czas[1] = Zapytaj_o_czas("minuty",nazwa,60);
  czas[2] = Zapytaj_o_czas("sekundy",nazwa,60);
}

void Wypisz_wynik(int pierwszy_czas[3], int drugi_czas[3], int wynik)
{
  switch(wynik)
  {
    case -1:
      printf("Czas %02d:%02d:%02d jest wiekszy niż %02d:%02d:%02d\n",pierwszy_czas[0],pierwszy_czas[1],pierwszy_czas[2],drugi_czas[0],drugi_czas[1],drugi_czas[2]);
      break;
    case 0:
      printf("Czas %02d:%02d:%02d jest równy %02d:%02d:%02d\n",pierwszy_czas[0],pierwszy_czas[1],pierwszy_czas[2],drugi_czas[0],drugi_czas[1],drugi_czas[2]);
      break;
    case 1:
      printf("Czas %02d:%02d:%02d jest wiekszy niż %02d:%02d:%02d\n",drugi_czas[0],drugi_czas[1],drugi_czas[2],pierwszy_czas[0],pierwszy_czas[1],pierwszy_czas[2]);
      break;
  }
}

int main(void)
{
  int pierwszy_czas[3];
  int drugi_czas[3];
  Wczytaj_czas(pierwszy_czas,"pierwszego");
  Wczytaj_czas(drugi_czas,"drugiego");
  int wynik = Porownaj_czas(3,pierwszy_czas,drugi_czas);
  Wypisz_wynik(pierwszy_czas,drugi_czas,wynik);
  
  return 0;
}
