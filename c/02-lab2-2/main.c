#include <stdio.h>

int main() {
  int n1, n2, n12;

  printf("* Inserisci il primo numero intero: ");
  scanf("%d", &n1);
  printf("* Inserisci il secondo numero intero: ");
  scanf("%d", &n2);

  n12 = n1 + n2;

  printf("\nLa variabile n12 vale: %d\n", n12);
  printf("Il prodotto tra n1 e n2 vale: %d\n", n1*n2);
  printf("La divisione intera tra n1 e n2 vale: %d\n", n1/n2);
  printf("La divisione reale tra n1 e n2 vale: %f\n", (double)n1/n2);
  printf("Il resto della divisione intera tra n1 e n2 vale: %d\n", n1%n2);
  
  return 0;
}

