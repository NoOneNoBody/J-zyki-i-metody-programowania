/*Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b
Przeliczanie temperatury */
#include<stdio.h>

double Celsjusz_na_Farenheit(double celsjusz)
{
  double farenheit = 32.0+(9.0/5.0)*celsjusz;
  return farenheit;
}

double Farenheit_na_Celsjusz(double farenheit)
{
  double celsjusz = (5.0/9.0)*(farenheit-32.0);
  return celsjusz;
}

int main()
{
  int wybor = 0;
  do
  {
    printf("Przeliczanie stopni:\n1.Celsjusza na Farenheita\n2.Farenheita na Celsjusza\n");
    scanf("%d",&wybor);
  } while(wybor != 1 && wybor != 2);
  printf("Podaj temperaturę do konwersji: ");
  double temperatura = 0;
  scanf("%lf",&temperatura);
  if(wybor == 1)
  {
    printf("To %lf stopni farenheita\n",Celsjusz_na_Farenheit(temperatura));
  }
  else
  {
    printf("To %lf stopni celsjusza\n",Farenheit_na_Celsjusz(temperatura));
  }
  return 0;
}
