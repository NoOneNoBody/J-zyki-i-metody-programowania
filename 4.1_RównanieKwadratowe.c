/*Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b
Obliczanie pierwiastków równania kwadratowego */
#include<stdio.h>
#include<math.h>

void Pierwiastki(double a, double b, double c)
{
  if(a != 0)
  {
    double delta = (b*b)-(4.0*a*c);
    if(delta>0)
    {
      double x1 = (sqrt(delta)-b)/(2*a);
      double x2 = (-sqrt(delta)-b)/(2*a);
      printf("Pierwiastki tego równania to %lf oraz %lf.\n",x1,x2);
    }
    else if(delta == 0)
    {
      double x = (-b)/(2*a);
      printf("Pierwiastkiem tego równania jest %lf.\n",x);
    }
    else
    {
      printf("To równanie nie ma rozwiązania w rzeczywistych.\n");
    }
  }
  else
  {
    if(b == 0)
	{
	  if(c == 0)
	  {
	    printf("Rozwiązaniem tego równania są liczby rzeczywiste.\n");
	  }
	  else
	  {
	    printf("To równanie nie ma rozwiązania.\n");
	  }
	}
	else
	{
	  double x = (-c)/b;
	  printf("Pierwiastkiem tego równania jest %lf.\n",x);
	}
  }
}

int main(void)
{
  printf("Podaj parametr przy x^2: ");
  double a = 0;
  scanf("%lf",&a);
  printf("Podaj parametr przy x: ");
  double b = 0;
  scanf("%lf",&b);
  printf("Podaj parametr przy wyrazie wolnym: ");
  double c = 0;
  scanf("%lf",&c);
  Pierwiastki(a,b,c);
  return 0;
}
