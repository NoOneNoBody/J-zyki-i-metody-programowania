//Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b
#include <stdio.h>
#include <stdlib.h>
#include "clipboard.h"
int main(void)
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
  printf("\n");
  return 0;
}
