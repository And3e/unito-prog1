/*
Scrivere un programma che riceve dallo standard input (cioè che legge con scanf)
quattro numeri interi x1, x2, x3 e x4, li riordini con opportune operazioni di
scambio, e alla fine li ristampi su di un unica linea di testo dal più piccolo
al più grande.

Suggerimento: procedere con una variabile alla volta:

partire con x1 e ottenere: x1 ≤ x2, x3, x4
a seguito procedere con x2 per ottenere: x2 ≤ x3, x4
infine procedere con: x3 ≤ x4
*/

#include <stdio.h>

void swap(int *x1, int *x2) {
  int temp = *x1;
  *x1 = *x2;
  *x2 = temp;
}

int main(void) {
  int x1, x2, x3, x4;

  scanf("%d%d%d%d", &x1, &x2, &x3, &x4);

  // x1
  if (x1 > x2) {
    swap(&x1, &x2);
  }
  if (x1 > x3) {
    swap(&x1, &x3);
  }
  if (x1 > x4) {
    swap(&x1, &x4);
  }

  // x2
  if (x2 > x3) {
    swap(&x2, &x3);
  }
  if (x2 > x4) {
    swap(&x2, &x4);
  }

  // x3 / x4
  if (x3 > x4) {
    swap(&x3, &x4);
  }

  printf("%d %d %d %d\n", x1, x2, x3, x4);

  return 0;
}
