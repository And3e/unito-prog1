#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int is_string_number(char string[]) {
  for (int i = 0; i < strlen(string); i++) {
    if (string[i] < '0' || string[i] > '9') {
      return 0;
    }
  }
  return 1;
}

int safe_number_insert(char message[], char error_message[], int min, int max) {
  char n_string[] = "";
  int number;
  int check_result;

  do {
    if (message[0] != '\0') {
      printf("%s", message);
    }

    scanf("%s", n_string);

    check_result = !is_string_number(n_string);

    number = check_result ? 0 : atoi(n_string);

    if (!check_result && min != max) {
      check_result = (number < min || number > max);
    }

    if (check_result) {
      printf("%s", error_message[0] != '\0'
                       ? error_message
                       : "\nErrore! Inserisci un valore valido!\n");
    }
  } while (check_result);

  return number;
}

char *get_longest_string(char *strings[]) {
  int index = 0;
  for (int i = 1; strings[i] != NULL; i++) {
    if (strlen(strings[i]) > strlen(strings[index])) {
      index = i;
    }
  }
  return strings[index];
}

char *get_repeated_string(char pattern[], int length) {
  int pattern_len = strlen(pattern);
  if (pattern_len == 0 || length <= 0) {
    return "";
  }

  // memory allocation
  char *out_string = malloc(length + 1); // +1 null terminator
  if (!out_string) {
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < length; i++) {
    out_string[i] = pattern[i % pattern_len];
  }
  out_string[length] = '\0';

  return out_string;
}

void out_menu(char title[], char *options[]) {
  // +2 +3 .. +2
  int padding = 7;

  int longest_string_length = strlen(get_longest_string(options));

  int title_separator_length = longest_string_length - strlen(title) + padding;
  int title_surplus_separator_length = title_separator_length % 2 == 0 ? 0 : 1;

  char *dash_separator = get_repeated_string(
      "-", longest_string_length + padding + title_surplus_separator_length);
  char *space_separator = get_repeated_string(
      " ", (title_separator_length + title_surplus_separator_length) / 2);

  printf("\n#%s#\n", dash_separator);
  printf("|%s%s%s|\n", space_separator, title, space_separator);
  printf("#%s#\n", dash_separator);

  for (int i = 0; options[i] != NULL; i++) {
    int current_length = strlen(options[i]);
    int spaces_to_fill =
        longest_string_length - current_length + title_surplus_separator_length;

    char *padding_spaces =
        spaces_to_fill > 0 ? get_repeated_string(" ", spaces_to_fill) : "";

    printf("|  %d. %s%s  |\n", i + 1, options[i], padding_spaces);

    if (spaces_to_fill > 0) {
      free(padding_spaces);
    }
  }

  printf("#%s#\n", dash_separator);

  free(dash_separator);
  free(space_separator);
}

double average(int numbers[], int size) {
  double somma = 0;

  if (size <= 0) {
    return 0;
  }

  for (int i = 0; i < size; i++) {
    somma += numbers[i];
  }

  return somma / size;
}

int main(void) {
  int x, y, z;
  int menu_choice;

  char title[] = "Menu Title";
  char *options[] = {"Somma", "Prodotto", "Media", NULL};

  x = safe_number_insert(" *Inserisci il primo numero: ", "", 0, 0);
  y = safe_number_insert(" *Inserisci il secondo numero: ", "", 0, 0);
  z = safe_number_insert(" *Inserisci il terzo numero: ", "", 0, 0);

  int numbers[] = {x, y, z};

  out_menu(title, options);
  menu_choice = safe_number_insert(
      " *Inserisci un opzione: ", "Menu selezionato non valido!\n", 1, 3);

  switch (menu_choice) {
  case 1: {
    printf("Risultato somma: %d", numbers[0] + numbers[1] + numbers[2]);
    break;
  }
  case 2: {
    printf("Risultato prodotto: %d", numbers[0] * numbers[1] * numbers[2]);
    break;
  }
  case 3: {
    printf("Risultato media: %f", average(numbers, 3));
    break;
  }
  }
}