#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

//------------------------------------------------------------------
// Prototipi delle funzioni
//------------------------------------------------------------------

// ritorna true se il carattere ch esiste nella stringa pStr.
bool trova_carattereR(const char *pStr, char ch) {
  if (*pStr == '\0') {
    return false;
  }

  if (*pStr == ch) {
    return true;
  }

  return trova_carattereR(pStr + 1, ch);
}

// ritorna il numero di occorrenze del carattere ch nella stringa pStr
int conta_caratteriR(const char *pStr, char ch) {
  if (*pStr == '\0') {
    return 0;
  }

  if (*pStr == ch) {
    return conta_caratteriR(pStr + 1, ch) + 1;
  }
  return conta_caratteriR(pStr + 1, ch);
}

// ritorna true se tutti i caratteri della stringa
// sono lettere maiuscole
bool tutte_maiuscoleR(const char *pStr) {
  if (*pStr == '\0') {
    return true;
  }

  if (*pStr > 90 || *pStr < 65) {
    return false;
  }

  return tutte_maiuscoleR(pStr + 1);
}

// prende in input una stringa pStr e modifica in-place
// i caratteri seguendo queste regole:
// - ogni lettera maiuscola viene sostituita con il carattere ‘$’
// - ogni lettera minuscola viene sostituita con il carattere ‘*’
// - tutti gli altri caratteri sono sostituiti con il carattere ‘-’
void converti_caratteriR(char *pStr) {
  if (*pStr != '\0') {

    if (isupper(*pStr)) {
      *pStr = '$';
    } else if (islower(*pStr)) {
      *pStr = '*';
    } else {
      *pStr = '-';
    }

    converti_caratteriR(pStr + 1);
  }
}

// elimina in-place tutte le occorrenze del carattere ch
// dalla stringa in input
// SUGGERIMENTO: usare il metodo wrapper fornito.
void filtra_carattereR(char *pStr, char ch) {
  if (*pStr != '\0') {
    if (*pStr == ch) {
      char *next = pStr;

      while (*next != '\0') {
        *next = *(next + 1);
        next++;
      }

      filtra_carattereR(pStr, ch);
    } else {
      filtra_carattereR(pStr + 1, ch);
    }
  }
}

// ESERCIZIO EXTRA
// capovolgi in-place la stringa pStr.
// Es: capovolgi("ciao") produce "oaic"
// SUGGERIMENTO: il metodo deve ritornare il puntatore alla posizione
// dentro al quale si deve scrivere il carattere "capovolto".

// Il caso base ritorna il puntatore iniziale (passato come argomento
// e mai modificato), ed ogni passo di induzione deve ritornare il
// puntatore opportunamente incrementato.

//  caso base: capovolgi_strR(*pStr=='\0', pStrInizio) ritorna pStrInizio
//  passo induttivo:
//    memorizzo ch = *pSrc  (DOMANDA: perche' devo farlo?)
//    sia pDest = capovolgi_strR(pStr+1, pStrInizio)
//    poi scrivi ch in *pDest e ritorna pDest+1

char *capovolgi_strR(char *pStr, char *pStrInizio) {
  if (*pStr == '\0') {
    return pStrInizio;
  }

  char ch = *pStr;

  char *pDest = capovolgi_strR(pStr + 1, pStrInizio);

  *pDest = ch;

  return pDest + 1;
}

void capovolgi_str(char *pStr) { capovolgi_strR(pStr, pStr); }
//------------------------------------------------------------------

int main(void) {
  // Unit test per la funzione trova_carattereR
  puts("Trova carattere:");
#define NUM 9
  const char *stringhe[NUM] = {
      "Buongiorno a tutti!",
      "123456",
      "La programmazione e' divertente.",
      "Programmare richiede pratica.",
      "XYZ",
      "Gli algoritmi plasmano il mondo digitale.",
      "La logica costruisce programmi robusti.",
      "Le strutture dati organizzano le informazioni.",
      "AABBCCDDEEFF",
  };
  const bool tc_val[NUM] = {true, false, true, false, false,
                            true, false, true, false};
  for (size_t i = 0; i < NUM; i++) {
    bool trovato = trova_carattereR(stringhe[i], 'n');
    printf("[%s] trova_carattere(\"%s\", 'n') = %d\n",
           (tc_val[i] == trovato ? "ok" : "NO"), stringhe[i], trovato);
  }

  // Unit test per la funzione conta_caratteriR
  puts("\nConta caratteri:");
  const int cc_val[NUM] = {1, 0, 3, 4, 0, 4, 3, 4, 0};
  for (size_t i = 0; i < NUM; i++) {
    int cnt = conta_caratteriR(stringhe[i], 'a');
    printf("[%s] conta_caratteri(\"%s\", 'a') = %d\n",
           (cc_val[i] == cnt ? "ok" : "NO"), stringhe[i], cnt);
  }

  // Unit test per la funzione converti_caratteriR
  puts("\nTutte maiuscole:");
  const bool tm_val[NUM] = {false, false, false, false, true,
                            false, false, false, true};
  for (size_t i = 0; i < NUM; i++) {
    bool tutte = tutte_maiuscoleR(stringhe[i]);
    printf("[%s] tutte_maiuscole(\"%s\") = %d\n",
           (tm_val[i] == tutte ? "ok" : "NO"), stringhe[i], tutte);
  }

  // Unit test per la funzione conta_caratteriR
  puts("\nConverti caratteri:");
  char s1[] = "UnA COMbinazIONE Di VARI Car@tteri.";
  const char *c1 = "$*$-$$$*****$$$$-$*-$$$$-$**-*****-";
  printf("     %s\n", s1);
  converti_caratteriR(s1);
  printf("[%s] %s\n\n", (0 == strcmp(s1, c1) ? "ok" : "NO"), s1);

  char s2[] = "Nel linguaggio C non esistono errori, ma solamente ";
  const char *c2 = "$**-**********-$-***-********-******--**-*********-";
  printf("     %s\n", s2);
  converti_caratteriR(s2);
  printf("[%s] %s\n\n", (0 == strcmp(s2, c2) ? "ok" : "NO"), s2);

  char s3[] = "modi innovativi per ottenere delle 'Segmentation Fault'.";
  const char *c3 = "****-**********-***-********-*****--$***********-$****--";
  printf("     %s\n", s3);
  converti_caratteriR(s3);
  printf("[%s] %s\n\n", (0 == strcmp(s3, c3) ? "ok" : "NO"), s3);

  // Unit test per la funzione filtra_carattereR
  puts("\nFiltro caratteri:");
  const char *f1 = "*-*****-*--**-*****-";
  printf("     %s\n", s1);
  filtra_carattereR(s1, '$');
  printf("[%s] %s\n\n", (0 == strcmp(s1, f1) ? "ok" : "NO"), s1);

  const char *f2 = "$--$-------";
  printf("     %s\n", s2);
  filtra_carattereR(s2, '*');
  printf("[%s] %s\n\n", (0 == strcmp(s2, f2) ? "ok" : "NO"), s2);

  const char *f3 = "------$-$--";
  printf("     %s\n", s3);
  filtra_carattereR(s3, '*');
  printf("[%s] %s\n\n", (0 == strcmp(s3, f3) ? "ok" : "NO"), s3);

  // ESERCIZIO EXTRA - funzione capovolgi_str
  // Unit test per la funzione capovolgi_str
  puts("\nCapovolgi stringa:");
  char s4[] = "123 456 789";
  printf("     %s\n", s4);
  capovolgi_str(s4);
  printf("[%s] %s\n\n", (0 == strcmp(s4, "987 654 321") ? "ok" : "NO"), s4);

  char s5[] = "Aceto nell'enoteca"; // situazione poco auspicabile
  printf("     %s\n", s5);
  capovolgi_str(s5);
  printf("[%s] %s\n\n", (0 == strcmp(s5, "acetone'llen otecA") ? "ok" : "NO"),
         s5);
}
