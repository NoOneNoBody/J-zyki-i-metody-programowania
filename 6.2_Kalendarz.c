/*Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b*/
#include <stdio.h>
#include<time.h>
#include <stdlib.h>

void print_day(struct tm tm)
{
  printf("%2d ",tm.tm_mday);
  if(tm.tm_wday==6)
  {
    printf("\n");
  }
}

void print_month()
{
  time_t t = time(NULL);
  int time_of_day = 24*60*60;
  struct tm tm = *localtime(&t);
  printf("ND PN WT SR CZ PT SB \n");
  while(tm.tm_mday != 1)
  {
    t -= time_of_day;
    tm = *localtime(&t);
  }
  for(int i =0; i<tm.tm_wday; ++i)
  {
    printf("   ");
  }
  print_day(tm);
  t += time_of_day;
  tm = *localtime(&t);
  while(tm.tm_mday != 1)
  {
    print_day(tm);
    t += time_of_day;
    tm = *localtime(&t);
  }
  printf("\n");
}

int main(void)
{
  print_month();
  
  return 0;
}
