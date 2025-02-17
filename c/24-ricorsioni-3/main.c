#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool esisteCarattereR(const char ch, const char *pStr, const size_t dim,
                      const size_t i) {
  if (i >= dim || *pStr == '\0') {
    // printf("false | *pStr: %c | i: %ld | dim: %ld\n", *pStr, i, dim);
    return false;
  }

  if (*pStr == ch) {
    // printf("true | *pStr: %c | i: %ld | dim: %ld\n", *pStr, i, dim);
    return true;
  }

  return esisteCarattereR(ch, pStr + 1, i + 1, dim);
}

void setCharAtR(const char ch, char *pStr, const size_t position,
                const size_t i) {

  if (i < position) {
    setCharAtR(ch, pStr + 1, position, i + 1);
  } else {
    // printf("\nSET pos: %ld | i: %ld | *pStr: %c | ch: %c\n", position, i,
    // *pStr,
    //        ch);
    *pStr = ch;
  }
}

int conta_valoriR(char *pStr) {
  if (*pStr == '\0') {
    return 1;
  }

  return 1 + conta_valoriR(pStr + 1);
}

void copia_strR(char *pStr, char *cloneStr) {
  if (*pStr != '\0') {
    *cloneStr = *pStr;
    copia_strR(pStr + 1, cloneStr + 1);
  } else {
    *cloneStr = '\0';
  }
}

void e2R(char *pStr, char *pStrI, size_t *dim) {
  if (*pStrI != '\0') {
    printf("giù: %c\n", *pStrI);
    e2R(pStr, pStrI + 1, dim);
  }

  char ch = *(pStrI - 1);
  bool ec = esisteCarattereR(ch, pStr, *dim, 0);
  printf("DA: %c | esiste char: %d\n", ch, ec);

  if (!ec) {
    setCharAtR(ch, pStr, *dim, 0);
    printf("OUT: %c\n", ch);
    *dim += 1;
  }
}

void e2(char *pStr) {

  int size = conta_valoriR(pStr);
  char copyStr[size];
  copia_strR(pStr, &copyStr[0]);

  size_t dim = 0;
  e2R(pStr, copyStr, &dim);

  setCharAtR('\0', pStr, dim, 0);
}

int main(void) {
  char str[] = "amaca";
  e2(str);
  char *result = (strcmp(str, "mca") == 0) ? "OK" : "NO";
  printf("\n%s | %s : %s\n", "amaca", str, result);

  char str2[] = "accompagnamento";
  e2(str2);
  char *result2 = (strcmp(str2, "cpgamento") == 0) ? "OK" : "NO";
  printf("\n%s | %s : %s\n", "accompagnamento", str2, result2);

  char str3[] = "sorprendente";
  e2(str3);
  char *result3 = (strcmp(str3, "soprdnte") == 0) ? "OK" : "NO";
  printf("\n%s | %s : %s\n", "sorprendente", str3, result3);

  char str4[] = "ripetizioni_char";
  e2(str4);
  char *result4 = (strcmp(str4, "petzoni_char") == 0) ? "OK" : "NO";
  printf("\n%s | %s : %s\n", "ripetizioni_char", str4, result4);

  return 0;
}