#include <stdio.h>

#include <stdbool.h>

#define ROWS (size_t)(2)

#define COLS (size_t)(3)

void funcx(int l, size_t aRows, size_t aCols, bool a[aRows][aCols],
           size_t aRags[aRows]) {

  aRags[l - 1] = l;

  for (int i = l - 1; i >= 0; i--) {

    a[l - 1][i] = !(l % 2 == 0);
  }

  // (B)
}

int main(void) {

  bool a[ROWS][COLS] = {{1, 1, 1}, {1, 1, 1}};

  size_t aRags[ROWS];

  for (size_t i = 0; i < ROWS; i++) {
    printf("|");
    for (size_t k = 0; k < COLS; k++) {
      printf(" %i |", a[i][k]);
    }
    printf("\n");
  }

  printf("\n\n****\n\n");

  for (size_t j = 0; j < ROWS; j++) {

    funcx(j + 1, ROWS, COLS, a, aRags); // (A)
  }

  for (size_t i = 0; i < ROWS; i++) {
    printf("|");
    for (size_t k = 0; k < COLS; k++) {
      printf(" %i |", a[i][k]);
    }
    printf("\n");
  }
}

/*
Quanti valori true sono presenti in a immediatamente prima della disallocazione
del frame della funzione main?
→ 1

Quanti valori false sono presenti in a immediatamente prima della disallocazione
del frame della funzione main?
→ 2

Indicare il numero di volte in cui la funzione x è stata chiamata
→ 2

Indicare il valore di aRags[1] immediatamente prima della disallocazione frame
della funzione main
→ 2
*/