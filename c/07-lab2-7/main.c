#include <stdio.h>

int main() {
  int pacchi_di_orecchiette, pomodori;
  float prezzo_pacchi_di_orecchiette = 1.5, prezzo_pomodori_kg = 2.5;
  float totale = 0;

  printf("* Inserisci il numero di pacchi di orecchiette: ");
  scanf("%d", &pacchi_di_orecchiette);
  printf("* Inserisci la quantità di pomodori (in kg): ");
  scanf("%d", &pomodori);

  totale += (pacchi_di_orecchiette * prezzo_pacchi_di_orecchiette);
  totale += (pomodori * prezzo_pomodori_kg);

  printf("\nTotale acquisti: %f\n", totale);
}

