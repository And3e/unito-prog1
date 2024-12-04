#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void leggi_matrice_irregolare(const size_t rows, const size_t cols,
                              int mat[rows][cols], size_t rags[rows]) {
  for (size_t r = 0; r < rows; r++) {
    scanf("%zu", &rags[r]);
    for (size_t c = 0; c < rags[r]; c++) {
      scanf("%d", &mat[r][c]);
    }
  }
}

void print_v(const size_t d, int v[]) {
  printf("\n|");

  for (size_t i = 0; i < d; i++) {
    printf(" %d |", v[i]);
  }
}

bool is_prefisso(const size_t dA, int a[], const size_t dB, int b[]) {
  bool result = false;

  if (dA <= dB) {
    result = true;

    for (size_t i = 0; i < dA; i++) {
      if (a[i] != b[i]) {
        result = false;
      }
    }
  }

  return result;
}

int main(void) {
  size_t rowsA, colsA;
  scanf("%zu %zu", &rowsA, &colsA);

  int matA[rowsA][colsA];
  size_t ragsA[rowsA];

  leggi_matrice_irregolare(rowsA, colsA, matA, ragsA);

  size_t rowsB, colsB;
  scanf("%zu %zu", &rowsB, &colsB);

  int matB[rowsB][colsB];
  size_t ragsB[rowsB];

  leggi_matrice_irregolare(rowsB, colsB, matB, ragsB);

  // COMPLETARE

  for (size_t rA = 0; rA < rowsA; rA++) {
    for (size_t rB = 0; rB < rowsB; rB++) {

      if (is_prefisso(ragsA[rA], matA[rA], ragsB[rB], matB[rB])) {
        printf("%zu %zu\n", rA, rB);
      }
    }
  }
}