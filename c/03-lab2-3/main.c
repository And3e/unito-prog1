#include <stdio.h>

int main() {
  // Quali risultati otteniamo in C da queste espressioni:
  int x1 = 7 + 3 * 6 / 2 - 1;
  int x2 = 2 % 2 + 2 * 2 - 2 / 2;
  int x3 = (3 * 9 * (3 + (9 * 3 / (3))));

  // Quali di queste espressioni corrisponde ad: y = ax3 + 7 ?
  // int y = a * x * x * x + 7;
  // int y = a * x * x * (x + 7);
  // int y = (a * x) * x * (x + 7);
  // int y = (a * x) * x * x + 7;
  // int y = a * (x * x * x) + 7;
  // int y = a * x * (x * x + 7);

  printf("Domanda 1:\n");
  printf("7 + 3 * 6 / 2 - 1 = %d\n", x1);
  printf("7 + 3 * 6 / 2 - 1 = %d\n", x2);
  printf("7 + 3 * 6 / 2 - 1 = %d\n", x3);

  printf("Domanda 2:\n");
  printf("  - int y = a * x * x * x + 7;\n");
  printf("  - int y = (a * x) * x * x + 7;\n");
  printf("  - int y = a * (x * x * x) + 7;\n");

  return 0;
}

