#include <stdbool.h>
#include <stdio.h>

// ritorna il massimo comun divisore (MCD) tra a e b usando
// l'algoritmo di Euclide per l'MCD:
//   MCD(a, 0) = a
//   MCD(a, b) = MCD(b, a mod b)
int mcd_euclideR(int a, int b) {
  // caso base: MCD(a, 0) = a
  if (!b) {
    return a;
  }
  // passo induttivo: MCD(a, b) = MCD(b, a mod b)
  return mcd_euclideR(b, a % b);
}

//------------------------------------------------------------------

// COMPLETARE

//------------------------------------------------------------------

// somma tutti gli interi dispari tra 0 ed n (incluso)
int somma_dispariR(int n) {
  if (!n) {
    return n;
  }

  // dispari
  if (n % 2) {
    return n + somma_dispariR(n - 1);
  }

  return somma_dispariR(n - 1);
}

// ritorna il prodotto di tutti gli interi multipli di k
// partendo da n e scendendo fino a n_min (incluso)
// se non ci sono multipli di k nell'intervallo, allora ritorna 1.
int prodotto_multipli_in_intervalloR(int n_min, int n, int k) {
  if (n == k) {
    return n;
  }

  if (n < n_min) {
    // == return n < n_min
    // 1: elemento neutro della moltiplicazione
    return 1;
  }

  if (!(n % k)) {
    return n * prodotto_multipli_in_intervalloR(n_min, n - 1, k);
  }
  return prodotto_multipli_in_intervalloR(n_min, n - 1, k);
}

// ritorna true se esiste un numero tra n_min ed n (estremi inclusi)
// che e' un divisore di k. Ritorna false altrimenti.
bool esiste_divisore_in_intervalloR(int n_min, int n, int k) {
  if (n < n_min) {
    return false;
  }

  if (!(k % n)) {
    return true;
  }
  return esiste_divisore_in_intervalloR(n_min, n - 1, k);
}

//------------------------------------------------------------------

int main(void) {
  // Unit test per algoritmo di Euclide
  puts("MCD con Euclide:");
#define NUM 6

  const int a_vals[NUM] = {2, 8, 7, 12, 81, 2172};
  const int b_vals[NUM] = {0, 4, 5, 7, 15, 3288};
  const int mcd_vals[NUM] = {2, 4, 1, 1, 3, 12};

  for (size_t i = 0; i < NUM; i++) {
    int mcd = mcd_euclideR(a_vals[i], b_vals[i]);
    printf("[%s] MCD(%d, %d) = %d\n", (mcd == mcd_vals[i] ? "Ok" : "NO"),
           a_vals[i], b_vals[i], mcd);
  }

  // Unit test per somma dispari
  puts("\nSomma dispari:");
  const int somma_vals[NUM] = {0, 4, 9, 16, 64, 2702736};
  for (size_t i = 0; i < NUM; i++) {
    int somma = somma_dispariR(b_vals[i]);
    printf("[%s] somma_dispari(%d) = %d\n",
           (somma == somma_vals[i] ? "Ok" : "NO"), b_vals[i], somma);
  }

  // Unit test per prodotto multipli
  puts("\nProdotto multipli:");
  const int n_vals[NUM] = {2, 7, 31, 15, 179, 2672};
  const int k_vals[NUM] = {2, 4, 10, 1, 37, 231};
  const int pm_vals[NUM] = {2, 1, 6000, 32760, 16428, 5869710};
  for (size_t i = 0; i < NUM; i++) {
    int prod_mult =
        prodotto_multipli_in_intervalloR(a_vals[i], n_vals[i], k_vals[i]);
    printf("[%s] prodotto_multipli_in_intervallo(%d, %d, %d) = %d\n",
           (prod_mult == pm_vals[i] ? "Ok" : "NO"), a_vals[i], n_vals[i],
           k_vals[i], prod_mult);
  }

  // Unit test per esiste divisore
  puts("\nEsiste divisore:");
  const int div_vals[NUM] = {2, 1, 25, 9, 242, 42};
  const bool ed_vals[NUM] = {true, false, true, false, true, false};
  for (size_t i = 0; i < NUM; i++) {
    bool esiste =
        esiste_divisore_in_intervalloR(a_vals[i], n_vals[i], div_vals[i]);
    printf("[%s] esiste_divisore_in_intervallo(%d, %d, %d) = %d\n",
           (esiste == ed_vals[i] ? "Ok" : "NO"), a_vals[i], n_vals[i],
           div_vals[i], esiste);
  }
}

//------------------------------------------------------------------
