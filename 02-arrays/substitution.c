#include <stdio.h>

int main(int argc, char **argv) {
  if (argc != 3) {
    return printf("Usage: ./substitution <key> <plaintext>\n");
  }

  char *key = argv[1];
  char *plaintext = argv[2];

  printf("Key = %s | Text = %s\n", key, plaintext);
}
