//Wykona³ Micha³ Warzecha I rok Informatyka EAIIB grupa 6b
#include <stdio.h>
#include <stdlib.h>
#include "clipboard.h"
int main()
{
  initialise();
  printToStdout();
  printf("\n");
  set("Hello world!");
  printToStdout();
  printf("\n");
  append("Tekst sie miesci.");
  printToStdout();
  printf("\n");
  append("Teraz tekst sie nie miesci, gdyz jest on zbyt dlugi.");
  printToStdout();
  printf("\n");
  clean();
  printToStdout();
  return 0;
}
