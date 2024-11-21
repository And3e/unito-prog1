#include <stdio.h>
#include <math.h>

int main(void) {
  int x, y, z;

  printf("Introduci il primo numero (per es. 8):   ");
  scanf("%d", &x);
  printf("Introduci il secondo numero (per es. 2): ");
  scanf("%d", &y);
  printf("Introduci il terzo numero (per es. 3):   ");
  scanf("%d", &z);

  // divisione intera
  int media1 = (x + y + z) / 3;
  printf("int media1: (x+y+z)/3 = %d (divisione intera)\n", media1);

  // divisione intera e cast a double
  double media2 = (x + y + z) / 3;
  printf("double media2: (x+y+z)/3 = %lf (divisione intera e cast a double)\n", media2);

  // divisione con virgola - risultato atteso!!
  double media3 = (x + y + z) / 3.0;
  printf("double media3: (x+y+z)/3.0 = %lf (divisione in virgola)\n", media3);

  // ESERCIZIO: 
  // Consideriamo tre varianti per calcolare media3: 
  // double media3 = (x + y + z) / 3.0;
  // double media3 = (double)(x + y + z) / 3;
  // double media3 = (double)((x + y + z) / 3); 

  // Cosa fanno rispettivamente? 

  // 1) somma x, y, z e poi fa il cast perché 3 è double
  // 2) somma x, y, z, poi fa il cast in double, poi divide la somma double con 3 (int)
  // 3) somma x, y, z, poi divide li divide con 3 (int), poi fa il cast del risultato in double

  // Quali sono i tipi delle operazioni intermedie?

  // 1) int / double
  // 2) double / int
  // 3) int / int

  // Dove avviene il cast da int a double nelle tre varianti?

  // 1) prima di fare la divisione con 3.0 (double)
  // 2) dopo aver fatto la somma di x, y, z
  // 3) alla fine, dopo aver fatto tutti i calcoli in int

  puts("");
  // arrotondiamo il valore di media3 ad intero
  printf("(int)media3 = %d\n", (int) media3);
  printf("(int)floor(media3) = %d\n", (int)floor(media3));
  printf("(int)round(media3) = %d\n", (int)round(media3));
  printf("(int)ceil(media3)  = %d\n", (int)ceil(media3));

  
  // ESERCIZIO: qual è la differenza tra i due modi di arrotondamento proposti?
  // Provare usando in input i valori 1,2,5

  // floor() restituisce il valore più grande intero che è minore o uguale al numero dato (== arrotonda verso il basso al numero intero più vicino)
  // round() arrotonda al numero intero più vicino. Se la parte decimale è minore di 0.5, il numero viene arrotondato verso l'intero inferiore, mentre se è maggiore o uguale a 0.5, il numero viene arrotondato verso l'intero superiore
  // ceil() restituisce il valore più piccolo intero che è maggiore o uguale al numero dato (== arrotonda verso l'alto al numero intero più vicino)

  puts("");
  // Problemi imprevisti dovuti a range di numeri finito,
  // che portano a rappresentazione binaria approssimata
  double f = 4.35;
  printf("4.35 * 100 = %d\n", (int)(f * 100)); // provare round() prima del cast!
  printf("4.35 * 100 = %d\n", (int)round(f * 100));
  
  
  // DOMANDA: spiegare per quale motivo il codice (int)(f * 100) non
  // produce il valore atteso (435).
}