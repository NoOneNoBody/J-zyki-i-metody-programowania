/*Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b*/
#include <stdio.h>
#include <stdlib.h>

double Srednia_wazona(int *poczatek, int *koniec)
{
  int ilosc = 0;
  int suma = 0;
  for(int i=0;poczatek+i<=koniec;++i)
  {
    int wartosc = *(poczatek+i);
    suma += wartosc*(i);
    ilosc += i;
  }
  return (suma/(double)ilosc);
}

int main(void)
{
  int tab[6];
  const int rozmiar = sizeof(tab)/sizeof(tab[0]);
  for(int i=0;i<rozmiar;++i)
  {
    printf("Podaj liczbe nr %d: ",(i+1));
    scanf("%d",&tab[i]);
  }
  double srednia = Srednia_wazona(&tab[0],&tab[rozmiar-1]);
  printf("Srednia wazona liczb to: %lf\n",srednia);
  
  return 0;
}
