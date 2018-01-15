/*Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b
Przeliczanie stopni na radiany oraz radianów na stopnie */
#include<stdio.h>
#define M_PI 3.14159265358979323846

double Stopnie_na_Radiany(double stopnie)
{
  double radiany = (stopnie/180.0)*M_PI;
  return radiany;
}

double Radiany_na_Stopnie(double radiany)
{
  double stopnie = (radiany*180.0)/M_PI;
  return stopnie;
}

int main(void)
{
  int wybor = 0;
  do
  {
    printf("Przeliczanie:\n1.Stopni na radiany\n2.Radiany na stopnie\n");
    scanf("%d",&wybor);
  } while(wybor != 1 && wybor != 2);
  printf("Podaj wartość do konwersji: ");
  double wartosc = 0;
  scanf("%lf",&wartosc);
  if(wybor == 1)
  {
    printf("To %lf radianów\n",Stopnie_na_Radiany(wartosc));
  }
  else
  {
    printf("To %lf stopni\n",Radiany_na_Stopnie(wartosc));
  }
  return 0;
}
