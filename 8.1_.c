//Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Suma(int ilosc, int* liczby)
{
  int suma = 0;
  for(int i=0;i<ilosc;++i)
  {
    suma += liczby[i];
  }
  return suma;
}

int Srednia(int ilosc, int suma)
{
  return (suma/ilosc);
}

void Sortuj(int ilosc,int *tablica,int *posortowana)
{
  for(int i=0;i<ilosc;++i)
  {
    posortowana[i]=tablica[i];
    int j = i;
    while(j>0 && posortowana[j]<posortowana[j-1])
    {
      int tmp = posortowana[j-1];
      posortowana[j-1]= posortowana[j];
      posortowana[j] = tmp;
      --j;
    }
  }
}

int Mediana(int ilosc, int *posortowane)
{
  if(ilosc%2)
  {
    return posortowane[(ilosc/2)];
  }
  else
  {
    return ((posortowane[(ilosc/2)-1]+posortowane[(ilosc/2)])/2);
  }
}

int Dominanta(int ilosc, int *liczby,int *czy_istnieje)
{
  if(ilosc>0)
  {
    int max_powturzenia = 1;
    int dane_powturzenia = 1;
    int dana_liczba = liczby[0];
    int dominanta = dana_liczba;
    *czy_istnieje = 1;
    for(int i=1;i<ilosc;++i)
    {
      if(dana_liczba == liczby[i])
      {
        dane_powturzenia += 1;
        if(dane_powturzenia > max_powturzenia)
        {
          max_powturzenia = dane_powturzenia;
          dominanta = dana_liczba;
          *czy_istnieje = 1;
        }
        else if(dane_powturzenia == max_powturzenia)
        {
          *czy_istnieje = 0;
        }
      }
      else
      {
        dana_liczba = liczby[i];
        dane_powturzenia = 1;
        if(dane_powturzenia == max_powturzenia)
        {
          *czy_istnieje = 0;
        }
      }
    }
    return dominanta;
  }
  return 0;
}

int Wczytaj_ilosc_liczb(void)
{
  int ilosc = 0;
  printf("Podaj ilosc liczb do wczytania: ");
  scanf("%d",&ilosc);
  return ilosc;
}

int Wczytywanie(int ilosc, int *dane)
{
  int dana=0;
  for(int i=0;i<ilosc;++i)
  {
    int wartosc_scanf = scanf("%d",&dana);
    if(wartosc_scanf == EOF || wartosc_scanf == 0)
    {
      return i;
    }
    else
    {
      dane[i] = dana;
    }
  }
  return ilosc;
}

int Dziesietne_na_osemkowe(int liczba)
{
  int reszta = 0;
  int i = 0;
  int wynik = 0;
  while(liczba>0)
  {
    reszta = liczba%8;
    liczba /= 8;
    wynik += pow(10,i)*reszta;
    ++i;
  }
  return wynik;
}

void Wypisz_wynik(char *typ, int wynik)
{
  printf("%s: %d %0x %d\n",typ,wynik,wynik,Dziesietne_na_osemkowe(wynik));
}

void Wypisz_wszystko(int ilosc, int *dane)
{
  int *posortowane = (int*)malloc(ilosc*sizeof(int));
  Sortuj(ilosc,dane,posortowane);
  int suma = Suma(ilosc,dane);
  int czy_istnieje_dominanta = 0;
  int dominanta = Dominanta(ilosc,posortowane,&czy_istnieje_dominanta);
  Wypisz_wynik("Suma",Suma(ilosc,dane));
  Wypisz_wynik("Srednia",Srednia(ilosc,suma));
  Wypisz_wynik("Mediana",Mediana(ilosc,posortowane));
  if(czy_istnieje_dominanta)
  {
    Wypisz_wynik("Dominanta",dominanta);
  }
  else
  {
    printf("Dominanta nie istnieje");
  }
}

int main(void)
{
  int ilosc = Wczytaj_ilosc_liczb();
  if(ilosc <= 0)
  {
    printf("Za malo danych");
    return 1;
  }
  int *dane = (int*)malloc(ilosc*sizeof(int));
  if(dane == NULL)
  {
    printf("Zbyt duza liczba danych");
    return 1;
  }
  int wpisana_ilosc = Wczytywanie(ilosc,dane);
  Wypisz_wszystko(wpisana_ilosc,dane);

  return 0;
}
