#include <stdio.h>

// int main(void) {
//   float f1, f2;
//   printf("Inserisci due numeri reali: ");
//   scanf("%f %d", &f1, &f2);

//   float risultato = (f1 + f2) / 2);
//   printf("Risultato = %f %d\n", &risultato);

//   // Calcoliamo il quadrato
//   // float quadrato = risultato * risultato;
//   printf("Il quadrato e' \n", quadrato) }
// }

int main(void) {
  float f1, f2;
  printf("Inserisci due numeri reali: ");
  scanf("%f %f", &f1, &f2);

  float risultato = ((f1 + f2) / 2);
  printf("Risultato = %f\n", risultato);

  // Calcoliamo il quadrato
  float quadrato = risultato * risultato;
  printf("Il quadrato e' %f\n", quadrato);
}

// 1) [r6] scanf usa %d per un float
// 2) [r8] manca una parentesi ( dopo l'=
// 3) [r9] prinf ha %d superfluo (e non corretto, dato che si sta stampando un float)
// 4) [r9] &risultato non dovrebbe avere l'indicatore &
// 5) [r12] togliere il commento
// 6) [r13] manca segnaposto %f dentro il prinf
// 7) [r13] manca ;
// 8) [r13] c'è una parentesi } di troppo

