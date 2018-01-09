/*Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b*/
#include <stdio.h>
#include <stdlib.h>

double Srednia_wazona(int *poczatek, int *koniec)
{
  int ilosc = 0;
  int suma = 0;
  int i=0;
  do{
    int wartosc = *(poczatek+i);
    suma += wartosc*(i);
    ilosc += i;
    ++i;
  }while(poczatek+i<=koniec);
  return (suma/ilosc);
}

int main(void)
{
  int tab[6];
  for(int i=0;i<6;++i)
  {
    printf("Podaj liczbe nr %d: ",(i+1));
    scanf("%d",&tab[i]);
  }
  double srednia = Srednia_wazona(&tab[0],&tab[5]);
  printf("Srednia wazona liczb to: %lf\n",srednia);
  return 0;
}
