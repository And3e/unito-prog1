#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(void) {
  // La costante pi greco
  const float PI_GRECO = 3.1415926535f;
  // DOMANDA: cosa significa const?
  // 'const' è un valore che non può cambiare ;-)

  // La costante pi greco è comunque già definita nel linguaggio C:
  // si chiama M_PI ed è disponibile con l'inclusione di <math.h>

  printf("PI_GRECO: %f\n", PI_GRECO);
  printf("M_PI: %f\n", M_PI);

  // Chiediamo all'utente il raggio
  printf("* Inserisci il raggio del cerchio: ");
  float r;
  scanf("%f", &r);
  
  // Calcolo della circonferenza e dell'area
  // ESERCIZIO: completare il codice
  //??? circonferenza = ????
  float circonferenza = 2 * M_PI * r;

  printf("La circonferenza del cerchio e': %f\n", circonferenza);

  // ESERCIZIO: completare il codice
  //??? area = ????
  float area = M_PI * (r * r);

  printf("L'area del cerchio e': %f\n", area);
}