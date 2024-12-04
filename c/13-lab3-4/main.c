/*
Scrivere un programma che riceve dallo standard input (cioè che legge con scanf)
due numeri interi n ed m, e stampa un messaggio a seconda che valga una di
queste condizioni:

se n è pari e maggiore di m, allora stampa "C1"
se n è pari e minore o uguale ad m, allora stampa "C2"
se invece n è dispari, procede in questo modo:
se anche m è dispari stampa "C3"
se invece m non é dispari ma è più del doppio di n, allora stampa "C4"
in ogni altro caso, stampa "ALTRO"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_string_number(char string[]) {
  for (int i = 0; i < strlen(string); i++) {
    if (string[i] < '0' || string[i] > '9') {
      return 0;
    }
  }
  return 1;
}

int safe_number_insert(char message[]) {
  char n_string[] = "";
  int check_result = 0;

  do {
    if (message[0] != '\0') {
      printf("%s", message);
    }
    scanf("%s", n_string);

    check_result = !is_string_number(n_string);
    if (check_result) {
      printf("\nErrore! Inserisci soltanto cifre!\n");
    }
  } while (check_result);

  return atoi(n_string);
}

int main(void) {
  int n, m;

  n = safe_number_insert("");
  m = safe_number_insert("");

  if (n % 2 == 0) {
    if (n > m) {
      printf("C1\n");
    } else {
      printf("C2\n");
    }
  } else {
    if (m % 2 == 1) {
      printf("C3\n");
    } else if (m > (n * 2)) {
      printf("C4\n");
    } else {
      printf("ALTRO");
    }
  }
}