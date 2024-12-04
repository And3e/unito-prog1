#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define R 2
#define C 5

void print_matrice(int in[R][C]) {
  int j=0, d=2;

  // ' '
  printf("%*s", d + 3, "");
  for (int i = 0; i < C; i++) {
    printf(" %*d  ", d, i + 1);
  }
  printf("\n");

  for (int i = 0; i < R; i++) {
    j++;

    printf("%*d  ", d + 1, j);

    for (int k = 0; k < C; k++) {

      if (in[i][k] > 0) {
        printf("|%*d| ", d, in[i][k]);
      } else {
        printf("|%*d| ", d, in[i][k]);
        printf("|%*s| ", d, "-");
      }
    }
    printf("\n");
  }
}

// Codice di Gio
bool elem_div_mat(const int mat[R][C]) {
  bool e_divisivo = true;

  for (size_t r = 0; r < R && e_divisivo; r++) {
    bool esistenza_divisivo = false;

    for (size_t c = 0; c < C && !esistenza_divisivo; c++) {
      bool controllo_divisioni = true;

      int divisore = mat[r][c];

      for (size_t x = 0; x < C && controllo_divisioni; x++) {
        if (mat[r][x] % divisore != 0 && c != x) {
          controllo_divisioni = false;
        }
      }

      if (controllo_divisioni) {
        esistenza_divisivo = true;
      }
    }

    if (!esistenza_divisivo) {
      e_divisivo = false;
    }
  }

  return e_divisivo;
}

bool el_divide_1_el_nella_riga(int mat[R][C]) {
  bool result = true;
  bool divisore_riga_found;

  for (size_t i = 0; i < R && result; i++) {
    divisore_riga_found = false;

    for (size_t c = 0; c < C; c++) {
      for (size_t k = 0; k < C && !divisore_riga_found; k++) {
        if (k != c && mat[i][k] % mat[i][c] == 0) {
          divisore_riga_found = true;
        }
      }
    }

    if (!divisore_riga_found) {
      result = false;
    }
  }

  return result;
}

bool el_divide_tutti_el_nella_riga(int mat[R][C]) {
  bool tutte_dividono = true;

  for (size_t i = 0; i < R && tutte_dividono; i++) {
    bool divisore_trovato = false;

    for (size_t c = 0; c < C && !divisore_trovato; c++) {
      bool divisore_valido = true;

      for (size_t k = 0; k < C && divisore_valido; k++) {
        if (c != k && mat[i][k] % mat[i][c] != 0) {
          divisore_valido = false;
        }
      }

      if (divisore_valido) {
        divisore_trovato = true;
      }
    }

    if (!divisore_trovato) {
      tutte_dividono = false;
    }
  }

  return tutte_dividono;
}

int main() {
  int mat1[R][C] = {{15, 19, 30, 29, 31}, {18, 19, 36, 29, 31}}; // false
  int mat2[R][C] = {{17, 19, 23, 29, 31}, {17, 19, 23, 29, 31}}; // false
  int mat3[R][C] = {{12, 8, 4, 16, 20}, {4, 8, 12, 16, 20}};     // true

  printf("\nMatrice 1:\n");
  print_matrice(mat1);
  printf("\nMatrice 2:\n");
  print_matrice(mat2);
  printf("\nMatrice 3:\n");
  print_matrice(mat3);

  printf("\nPer ciascuna riga, un elemento divide gli altri della riga: \n");
  printf("Matrice 1: %s", el_divide_tutti_el_nella_riga(mat1) ? "true\n" : "false\n");
  printf("Matrice 2: %s", el_divide_tutti_el_nella_riga(mat2) ? "true\n" : "false\n");
  printf("Matrice 3: %s", el_divide_tutti_el_nella_riga(mat3) ? "true\n" : "false\n");
}
