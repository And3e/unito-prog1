#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

//------------------------------------------------------------------

int min(int a, int b) { return (a < b) ? a : b; }

// Restituisce il valore minimo nell'array a[] attraverso una ricerca
// lineare. Se l'array è vuoto, restituisce INT_MAX
// Usa la ricorsione controvariante (crescente):
// involucro
int ricerca_minimo_conR(const int a[], const size_t left, const size_t right) {
  if (left >= right) {
    return a[left - 1];
  }

  int minr = ricerca_minimo_conR(a, left + 1, right);
  return min(minr, a[left]);
}

int ricerca_minimo_con(const size_t aLen, const int a[]) {
  if (!aLen) {
    return INT_MAX;
  }

  return ricerca_minimo_conR(a, 0, aLen);
}

// Usa la ricorsione covariante (decrescente):
// involucro
int ricerca_minimo_covR(const int a[], const size_t left, const size_t right) {
  if (left >= right) {
    return a[right + 1];
  }

  int minr = ricerca_minimo_covR(a, left, right - 1);
  return min(a[right - 1], minr);
}

int ricerca_minimo_cov(const size_t aLen, const int a[]) {
  if (!aLen) {
    return INT_MAX;
  }

  return ricerca_minimo_covR(a, 0, aLen);
}

// Usa la ricorsione dicotomica (dimezzamento intervalli):
int ricerca_minimo_dicR(const int a[], const size_t left, const size_t right) {
  if (left >= right) {
    return a[left - 1];
  } else if (right - left == 1) {
    return a[left];
  }
  
  int mid = left + (right - left) / 2;

  int minL = ricerca_minimo_dicR(a, left, mid);
  int minR = ricerca_minimo_dicR(a, mid, right);
  return min(minL, minR);
}

// involucro
int ricerca_minimo_dic(const size_t aLen, const int a[]) {
  if (!aLen) {
    return INT_MAX;
  }

  return ricerca_minimo_dicR(a, 0, aLen);
}

//------------------------------------------------------------------

// Sostituisce tutti i numeri dispari nell'array a[] con il loro doppio
// Usa la ricorsione controvariante (crescente):
// involucro
void raddoppia_dispari_conR(int a[], const size_t left, const size_t right) {
  if (left < right) {
    if (a[left] % 2) {
      a[left] *= 2;
    }
    raddoppia_dispari_conR(a, left + 1, right);
  }
}
void raddoppia_dispari_con(const size_t aLen, int a[]) {
  raddoppia_dispari_conR(a, 0, aLen);
}

// Usa la ricorsione covariante (decrescente):
// involucro
void raddoppia_dispari_covR(int a[], const size_t left, const size_t right) {
  if (left < right) {
    if (a[right - 1] % 2) {
      a[right - 1] *= 2;
    }
    raddoppia_dispari_covR(a, left, right - 1);
  }
}
void raddoppia_dispari_cov(const size_t aLen, int a[]) {
  raddoppia_dispari_covR(a, 0, aLen);
}

// Usa la ricorsione dicotomica (dimezzamento intervalli):
// involucro
void raddoppia_dispari_dicR(int a[], const size_t left, const size_t right) {
  if (right - left == 1) {
    if (a[left] % 2) {
      a[left] *= 2;
    }
  } else if (left < right) {
    int mid = left + (right - left) / 2;
    raddoppia_dispari_dicR(a, left, mid);
    raddoppia_dispari_dicR(a, mid, right);
  }
}
void raddoppia_dispari_dic(const size_t aLen, int a[]) {
  raddoppia_dispari_dicR(a, 0, aLen);
}

//------------------------------------------------------------------

// Restituisce true se nell'array a[] esistono valori maggiori o uguali a
// val. Usa la ricorsione controvariante (crescente):
// involucro
bool esiste_maggiore_conR(const int a[], const int val, const size_t left,
                          const size_t right) {
  if (left >= right) {
    return false;
  }

  if (a[left] >= val) {
    return true;
  }

  return esiste_maggiore_conR(a, val, left + 1, right);
}
bool esiste_maggiore_con(const size_t aLen, const int a[], const int val) {
  return esiste_maggiore_conR(a, val, 0, aLen);
}

// Usa la ricorsione covariante (decrescente):
// involucro
bool esiste_maggiore_covR(const int a[], const int val, const size_t left,
                          const size_t right) {
  if (left + 1 >= right) {
    return false;
  }

  if (a[right - 1] >= val) {
    return true;
  }

  return esiste_maggiore_conR(a, val, left, right - 1);
}
bool esiste_maggiore_cov(const size_t aLen, const int a[], const int val) {
  return esiste_maggiore_covR(a, val, 0, aLen);
}

// Usa la ricorsione dicotomica (dimezzamento intervalli):
// involucro
bool esiste_maggiore_dicR(const int a[], const int val, const size_t left,
                          const size_t right) {
  if (left >= right) {
    return false;
  } else if (right - left == 1) {
    if (a[left] >= val) {
      return true;
    }
  } else {
    int mid = left + (right - left) / 2;
    return esiste_maggiore_dicR(a, val, left, mid) ||
           esiste_maggiore_dicR(a, val, mid, right);
  }

  return false;
}
bool esiste_maggiore_dic(const size_t aLen, const int a[], const int val) {
  return esiste_maggiore_dicR(a, val, 0, aLen);
}

//------------------------------------------------------------------

// Restituisce il numero di occorrenze degli elementi nell'array a[]
// che sono multipli di val.
// Usa la ricorsione controvariante (crescente):
// involucro
size_t conta_multipli_conR(const int a[], const int val, const size_t left,
                           const size_t right) {
  if (left >= right) {
    return 0;
  }

  if (!(a[left] % val)) {
    return 1 + conta_multipli_conR(a, val, left + 1, right);
  }

  return conta_multipli_conR(a, val, left + 1, right);
}
size_t conta_multipli_con(const size_t aLen, const int a[], const int val) {
  return conta_multipli_conR(a, val, 0, aLen);
}

// Usa la ricorsione covariante (decrescente):
// involucro
size_t conta_multipli_covR(const int a[], const int val, const size_t left,
                           const size_t right) {
  if (left >= right) {
    return 0;
  }

  if (!(a[right - 1] % val)) {
    return 1 + conta_multipli_covR(a, val, left, right - 1);
  }

  return conta_multipli_covR(a, val, left, right - 1);
}
size_t conta_multipli_cov(const size_t aLen, const int a[], const int val) {
  return conta_multipli_covR(a, val, 0, aLen);
}

// Usa la ricorsione dicotomica (dimezzamento intervalli):
// involucro
size_t conta_multipli_dicR(const int a[], const int val, const size_t left,
                           const size_t right) {
  if (left >= right) {
    return 0;
  } else if (right - left == 1) {
    if (!(a[left] % val)) {
      return 1;
    } else {
      return 0;
    }
  } else {
    size_t mid = left + (right - left) / 2;
    size_t contaL = conta_multipli_dicR(a, val, left, mid);
    size_t contaR = conta_multipli_dicR(a, val, mid, right);

    return contaL + contaR;
  }

  return 0;
}
size_t conta_multipli_dic(const size_t aLen, const int a[], const int val) {
  return conta_multipli_dicR(a, val, 0, aLen);
}

//------------------------------------------------------------------

int main(void) {
// matrice irregolare per il test
#define ROWS 8
#define COLS 15
  int mat[ROWS][COLS] = {
      {16, 20, 30},
      {18, 3, 30, 22, 18, 71, 82, 6, 98, 57, 35, 35, 84, 19, 5},
      {79, 41, 99, 12, 66},
      {63, 56, 79, 48, 28, 62, 15, 78},
      {},
      {30, 66, 14, 88, 30, 23, 29, 50},
      {50, 45, 72, 55, 10, 9, 71, 59, 95, 85, 16, 42, 37, 32, 70},
      {31, 10, 60, 57, 86, 30, 72, 76, 84}};
  size_t rags[ROWS] = {3, 15, 5, 8, 0, 8, 15, 9};

  // Unit test per la ricerca del minimo
  puts("Ricerca del minimo:   controvariante  covariante  dicotomico");
  const int min_res[ROWS] = {16, 3, 12, 15, INT_MAX, 14, 9, 10};
  for (size_t r = 0; r < ROWS; r++) {
    int m1 = ricerca_minimo_con(rags[r], mat[r]);
    int m2 = ricerca_minimo_cov(rags[r], mat[r]);
    int m3 = ricerca_minimo_dic(rags[r], mat[r]);
    printf("[%s] Array %zu: minimo  %-16d%-12d%-8d\n",
           (m1 == min_res[r] && m2 == m1 && m3 == m1 ? "ok" : "NO"), r, m1, m2,
           m3);
  }
  puts("");

  // Unit test per il raddoppio dei dispari
  int mat_doppi[ROWS][COLS] = {
      {16, 20, 30},
      {18, 6, 30, 22, 18, 142, 82, 6, 98, 114, 70, 70, 84, 38, 10},
      {158, 82, 198, 12, 66},
      {126, 56, 158, 48, 28, 62, 30, 78},
      {},
      {30, 66, 14, 88, 30, 46, 58, 50},
      {50, 90, 72, 110, 10, 18, 142, 118, 190, 170, 16, 42, 74, 32, 70},
      {62, 10, 60, 114, 86, 30, 72, 76, 84}};
  puts("Raddoppio dispari:   controvariante  covariante  dicotomico");
  for (size_t r = 0; r < ROWS; r++) {
    int a1[COLS], a2[COLS], a3[COLS];
    for (size_t i = 0; i < rags[r]; i++)
      a1[i] = a2[i] = a3[i] = mat[r][i];

    raddoppia_dispari_con(rags[r], a1);
    raddoppia_dispari_cov(rags[r], a2);
    raddoppia_dispari_dic(rags[r], a3);

    bool tutti_con = true, tutti_cov = true, tutti_dic = true;
    for (size_t i = 0; i < rags[r]; i++) {
      tutti_con = tutti_con && (a1[i] == mat_doppi[r][i]);
      tutti_cov = tutti_cov && (a2[i] == mat_doppi[r][i]);
      tutti_dic = tutti_dic && (a3[i] == mat_doppi[r][i]);
    }
    printf("[%s] Array %zu: doppi  %-16d%-12d%-8d\n",
           (tutti_con && tutti_cov && tutti_dic ? "ok" : "NO"), r, tutti_con,
           tutti_cov, tutti_dic);
  }
  puts("");

  // Unit test per esistenza maggiore
  puts("Esiste maggiore:   controvariante  covariante  dicotomico");
  const bool esiste_res[ROWS] = {false, true, true, false,
                                 false, true, true, true};
  for (size_t r = 0; r < ROWS; r++) {
    bool e1 = esiste_maggiore_con(rags[r], mat[r], 80);
    bool e2 = esiste_maggiore_cov(rags[r], mat[r], 80);
    bool e3 = esiste_maggiore_dic(rags[r], mat[r], 80);
    printf("[%s] Array %zu {%d}: esiste?  %-16d%-12d%-8d\n",
           (e1 == esiste_res[r] && e2 == e1 && e3 == e1 ? "ok" : "NO"), r,
           esiste_res[r], e1, e2, e3);
  }
  puts("");

  // Unit test per conteggio multipli
  puts("Conta multipli:   controvariante  covariante  dicotomico");
  const size_t cm_res[ROWS] = {2, 4, 0, 1, 0, 3, 7, 3};
  for (size_t r = 0; r < ROWS; r++) {
    size_t c1 = conta_multipli_con(rags[r], mat[r], 5);
    size_t c2 = conta_multipli_cov(rags[r], mat[r], 5);
    size_t c3 = conta_multipli_dic(rags[r], mat[r], 5);
    printf("[%s] Array %zu: conteggio?  %-16zu%-12zu%-8zu\n",
           (c1 == cm_res[r] && c2 == c1 && c3 == c1 ? "ok" : "NO"), r, c1, c2,
           c3);
  }
  puts("");
}