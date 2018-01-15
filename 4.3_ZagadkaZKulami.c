/*Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b
Zgadywanie która kula jest najcięższa */
#include<stdio.h>

void zgadnij_ktora_kula(void)
{
  int wybor = 0;
  do
  {
    printf("Czy kule 1, 2 i 3 w porównaniu do kól 4, 5 i 6 ważą:\n1. Więcej\n2. Mniej\n3. Tyle samo\n");
    scanf("%d",&wybor);
  } while(wybor != 1 && wybor != 2 && wybor != 3);
  switch(wybor)
  {
    case 1:
    {
      wybor = 0;
      do
      {
        printf("Czy kula 1 w porównaniu do kóli 2 waży:\n1. Więcej\n2. Mniej\n3. Tyle samo\n");
        scanf("%d",&wybor);
      } while(wybor != 1 && wybor != 2 && wybor != 3);
      switch(wybor)
      {
        case 1:
          printf("Kula 1 jest najcięższa.\n");
          break;
        case 2:
          printf("Kula 2 jest najcięższa.\n");
          break;
        default:
          printf("Kula 3 jest najcięższa.\n");
        break;
      }
      break;
    }
    case 2:
    {
      wybor = 0;
      do
      {
        printf("Czy kula 4 w porównaniu do kóli 5 waży:\n1. Więcej\n2. Mniej\n3. Tyle samo\n");
        scanf("%d",&wybor);
      } while(wybor != 1 && wybor != 2 && wybor != 3);
      switch(wybor)
      {
        case 1:
          printf("Kula 4 jest najcięższa.\n");
          break;
        case 2:
          printf("Kula 5 jest najcięższa.\n");
          break;
        default:
          printf("Kula 6 jest najcięższa.\n");
          break;
      }
      break;
    }
    default:
    {
      wybor = 0;
      do
      {
        printf("Czy kula 7 w porównaniu do kóli 8 waży:\n1. Więcej\n2. Mniej\n3. Tyle samo\n");
        scanf("%d",&wybor);
      } while(wybor != 1 && wybor != 2 && wybor != 3);
      switch(wybor)
      {
        case 1:
          printf("Kula 7 jest najcięższa.\n");
          break;
        case 2:
          printf("Kula 8 jest najcięższa.\n");
          break;
        default:
          printf("Kula 9 jest najcięższa.\n");
          break;
      }
      break;
    }
  }
}

int main(void)
{
  zgadnij_ktora_kula();

  return 0;
}
