/*Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b
Obliczanie pól i obwodów */
#include<stdio.h>
#include<math.h>

#define M_PI 3.14159265358979323846


int SprawdzCzyPoprawneBokiTrojkata(double bokA, double bokB, double bokC)
{
  return(bokA > 0 && bokB > 0 && bokC > 0 && bokA+bokB > bokC && bokA+bokC > bokB && bokB+bokC > bokA);
}
double PoleTrojkata(double bokA, double bokB, double bokC)
{
  double polowaObwodu = (bokA+bokB+bokC)/2.0;
  double kwadratPolaTrojkata = polowaObwodu*(polowaObwodu-bokA)*(polowaObwodu-bokB)*(polowaObwodu-bokC);
  double poleTrojkata = 0;
  if(kwadratPolaTrojkata > 0)
  {
	  poleTrojkata = sqrt(kwadratPolaTrojkata);
  }
  return (poleTrojkata);
}
double PoleProstokata(double bokA, double bokB)
{
  return (bokA*bokB);
}
double PoleKwadratu(double bok)
{
  return (bok*bok);
}
double PoleKola(double promien)
{
  return (M_PI*(promien*promien));
}
double ObwodTrojkata(double bokA, double bokB, double bokC)
{
  return (bokA+bokB+bokC);
}
double ObwodProstokata(double bokA, double bokB)
{
  return (2.0*(bokA+bokB));
}
double ObwodKwadratu(double bok)
{
  return (4.0*bok);
}
double ObwodKola(double promien)
{
  return (2.0*M_PI*promien);
}

void WczytanieTrojkata(void)
{
  printf("Podaj pierwszy bok trójkąta: ");
  double trojkatBokA=0;
  scanf("%lf",&trojkatBokA);
  printf("Podaj drugi bok trójkąta: ");
  double trojkatBokB=0;
  scanf("%lf",&trojkatBokB);
  printf("Podaj trzeci bok trójkąta: ");
  double trojkatBokC=0;
  scanf("%lf",&trojkatBokC);
  if(!SprawdzCzyPoprawneBokiTrojkata(trojkatBokA, trojkatBokB, trojkatBokC))
  {
    printf("Podano niewłaściwe dane\n");
    return;
  }
  int wybor=0;
  printf("Chcesz policzyć:\n1. Pole\n2. Obwód\n");
  scanf("%d",&wybor);
  switch(wybor)
  {
    case 1:
    {
      double pole = PoleTrojkata(trojkatBokA,trojkatBokB,trojkatBokC);
      if(pole > 0)
      {
        printf("Pole trójkąta wynosi: %f\n",pole);
      }
      else
      {
        printf("Podano niewłaściwe dane\n");
      }
      break;
    }
    case 2:
    {
      printf("Obwód trójkąta wynosi: %f\n",ObwodTrojkata(trojkatBokA,trojkatBokB,trojkatBokC));
      break;
    }
    default:
    {
      printf("Zły numer\n");
      break;
    }
  }
}

void WczytanieProstokata(void)
{
  printf("Podaj pierwszy bok prostokąta: ");
  double prostokatBokA=0;
  scanf("%lf",&prostokatBokA);
  printf("Podaj drugi bok prostokąta: ");
  double prostokatBokB=0;
  scanf("%lf",&prostokatBokB);
  if(prostokatBokA <= 0 || prostokatBokB <= 0)
  {
    printf("Podano niewłaściwe dane\n");
    return;
  }
  int wybor=0;
  printf("Chcesz policzyć:\n1. Pole\n2. Obwód\n");
  scanf("%d",&wybor);
  switch(wybor)
  {
    case 1:
    {
      printf("Pole prostokąta wynosi: %f\n",PoleProstokata(prostokatBokA,prostokatBokB));
      break;
    }
    case 2:
    {
      printf("Obwód prostokąta wynosi: %f\n",ObwodProstokata(prostokatBokA,prostokatBokB));
      break;
    }
    default:
    {
      printf("Zły numer\n");
      break;
    }
  }
}

void WczytanieKwadratu(void)
{
  printf("Podaj bok kwadratu: ");
  double kwadratBok=0;
  scanf("%lf",&kwadratBok);
  if(kwadratBok <= 0)
  {
    printf("Podano niewłaściwe dane\n");
    return;
  }
  int wybor=0;
  printf("Chcesz policzyć:\n1. Pole\n2. Obwód\n");
  scanf("%d",&wybor);
  switch(wybor)
  {
    case 1:
    {
      printf("Pole kwadratu wynosi: %f\n",PoleKwadratu(kwadratBok));
      break;
    }
    case 2:
    {
      printf("Obwód kwadratu wynosi: %f\n",ObwodKwadratu(kwadratBok));
      break;
    }
    default:
    {
      printf("Zły numer\n");
      break;
    }
  }
}

void WczytywanieKola(void)
{
  printf("Podaj promień koła: ");
  double koloPromien=0;
  scanf("%lf",&koloPromien);
  if(koloPromien <= 0)
  {
    printf("Podano niewłaściwe dane\n");
    return;
  }
  int wybor=0;
  printf("Chcesz policzyć:\n1. Pole\n2. Obwód\n");
  scanf("%d",&wybor);
  switch(wybor)
  {
    case 1:
    {
      printf("Pole koła wynosi: %f\n",PoleKola(koloPromien));
      break;
    }
    case 2:
    {
      printf("Obwód koła wynosi: %f\n",ObwodKola(koloPromien));
      break;
    }
    default:
    {
      printf("Zły numer\n");
      break;
    }
  }
}

int main(void)
{
  int wybor=0;
  printf("Wybierz figurę:\n1. Trójkąt\n2. Prostokąt\n3. Kwadrat\n4. Koło\n");
  scanf("%d",&wybor);
  switch(wybor)
  {
    case 1:
    {
      WczytanieTrojkata();
      break;
    }
    case 2:
    {
      WczytanieProstokata();
      break;
    }
    case 3:
    {
      WczytanieKwadratu();
      break;
    }
    case 4:
    {
      WczytywanieKola();
      break;
    }
    default:
      printf("Zły numer\n");
      break;
  }
  
  return 0;
}
