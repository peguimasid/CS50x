#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_string_alpha(char *string) {
  for (int i = 0; i < strlen(string); i++) {
    if (!isalpha(string[i])) return false;
  }

  return true;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    return printf("Usage: ./substitution <key> <plaintext>\n");
  }

  char *key = argv[1];
  char *plaintext = argv[2];

  if (strlen(key) != 26) {
    return printf("Key must contain 26 characters.\n");
  }

  if (!is_string_alpha(key)) {
    return printf("Key must only contain alphabetic characters.\n");
  }

  printf("Key = %s | Text = %s\n", key, plaintext);
}
