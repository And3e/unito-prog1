#include <stdio.h>

int main(void) {
  int x = 5;
  int y = 8;
  printf("x: %d, y: %d\n", x, y);

  // scambio x con y usando una variabile intermedia
  int temp = x;
  x = y;
  y = temp;

  printf("x: %d, y: %d\n", x, y);

  puts("--");

  int v1 = 1, v2 = 2, v3 = 3, v4 = 4;

  printf("v1: %d, v2: %d, v3: %d, v4: %d\n", v1, v2, v3, v4);

  temp = v1;
  v1 = v2;
  v2 = v3;
  v3 = v4;
  v4 = temp;

  printf("v1: %d, v2: %d, v3: %d, v4: %d\n", v1, v2, v3, v4);
}