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

bool has_repeating_letters(char *string) {
  int key_len = 26;

  int count[key_len];

  for (int i = 0; i < key_len; i++) {
    count[i] = 0;
  }

  for (int i = 0; i < key_len; i++) {
    int char_position = toupper(string[i]) - 65;
    count[char_position]++;
  }

  for (int i = 0; i < key_len; i++) {
    if (count[i] != 1) return true;
  }

  return false;
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

  if (has_repeating_letters(key)) {
    return printf("Each char must appear just once\n");
  }

  printf("Key = %s | Text = %s\n", key, plaintext);
}
