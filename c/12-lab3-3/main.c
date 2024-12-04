#include <stdio.h>

int main(void) {
  int h;
  printf(" *Inserisci un orario 0-24 (hh):");
  scanf("%d", &h);

  if (h >= 5 && h < 15) {
    printf("Buongiorno");
  } else if (h >= 15 && h < 18) {
    printf("Buon pomeriggio");
  } else if (h >= 15 && h < 18) {
    printf("Buonasera");
  } else if (h >= 18 || h < 5) {
    printf("Buona notte");
  }
}
