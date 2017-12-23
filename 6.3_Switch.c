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

void Wyswietl(int tablica[])
{
  for(int i=0;i<10;i++)
  {
    printf("%d ",tablica[i]);
  }
  printf("\n");
}

void Srednia(int tablica[])
{
  int suma = 0;
  for(int i=0;i<10;i++)
  {
    suma += tablica[i];
  }
  printf("Srednia liczb: %f\n",(suma/10.0));
}

void Sortuj(int tablica[],int posortowana[])
{
  for(int i=0;i<10;i++)
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

void MinMax(int tablica[])
{
  int min=tablica[0];
  int max = tablica[0];
  for(int i=1;i<10;i++)
  {
    if(tablica[i]<min)
    {
      min = tablica[i];
    }
    if(tablica[i]>max)
    {
      max = tablica[i];
    }
  }
  printf("Minimalna wartosc to: %d, a maksymalna to: %d.\n",min,max);
}

int main()
{
  int choise = 0;
  int chosen = 1;
  int tablica [10];
  Losuj(tablica);
  int tablica_posortowana [10];
  do
  {
    choise = 0;
    chosen = 1;
    printf("1.Losuj tablice\n2.Wyswietl\n3.Srednia\n4.Mediana\n5.Minimalna i maksymalna wartosc\n6.Wyjdz\n");
    scanf("%d",&choise);
    switch(choise)
    {
      case 1:
      {
        Losuj(tablica);
        break;
      }
      case 2:
      {
        Wyswietl(tablica);
        break;
      }
      case 3:
      {
        Srednia(tablica);
        break;
      }
      case 4:
      {
        Sortuj(tablica,tablica_posortowana);
        printf("Mediana liczb: %f\n",(tablica_posortowana[4]+tablica_posortowana[5])/2.0);
        break;
      }
      case 5:
      {
        MinMax(tablica);
        break;
      }
      case 6:
      {
        chosen = 0;
        break;
      }
    }
  }while(chosen);

  return 0;
}
