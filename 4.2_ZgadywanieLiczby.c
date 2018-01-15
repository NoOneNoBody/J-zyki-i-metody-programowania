/*Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b
Zadanie zgadywanie liczby */
#include<stdio.h>
#include<math.h>

int wczytaj_liczbe_calkowita(void)
{
  int liczba = 0;
  do
  {
    printf("Podaj liczbę całkowitą od 1 do 10: ");
    scanf("%d", &liczba);
    if(liczba < 1 || liczba > 10)
    {
      printf("Wybrano nie właściwą liczbę!\n");
    }
  }
  while (liczba < 1 || liczba > 10);
  return liczba;
}

void zgadnij_liczbe(int liczba)
{
  if(liczba > 5)
  {
    if(liczba > 7)
    {
      if(liczba > 8)
      {
        if(liczba > 9)
        {
          printf("Liczba to 10\n");
        }
        else
        {
          printf("Liczba to 9\n");
        }
      }
      else
      {
        printf("Liczba to 8\n");
      }
    }
    else if(liczba > 6)
    {
      printf("Liczba to 7\n");
    }
    else
    {
      printf("Liczba to 6\n");
    }
  }
  else if(liczba > 3)
  {
    if(liczba > 4)
    {
      printf("Liczba to 5\n");
    }
    else
    {
      printf("Liczba to 4\n");
    }
  }
  else if(liczba > 2)
  {
    printf("Liczba to 3\n");
  }
  else if(liczba > 1)
  {
    printf("Liczba to 2\n");
  }
  else
  {
    printf("Liczba to 1\n");
  }
}

int main(void)
{
  int liczba = wczytaj_liczbe_calkowita();
  zgadnij_liczbe(liczba);

  return 0;
}
