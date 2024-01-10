#include "dictionary.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t BYTE;

typedef struct node {
  char word[LENGTH + 1];
  struct node *next;
} node;

int num_words = 0;

const unsigned int N = 26;

node *table[N];

bool check(const char *word) {
  unsigned int index = hash(word);

  node *n = table[index];

  while (n) {
    if (strcmp(n->word, word) == 0) {
      return true;
    }
    n = n->next;
  }

  return false;
}

unsigned int hash(const char *word) {
  return toupper(word[0]) - 'A';
}

bool load(const char *dictionary) {
  FILE *source = fopen(dictionary, "r");
  BYTE buffer;

  char word[LENGTH + 1];

  while (fscanf(source, "%s", word) != EOF) {
    unsigned int index = hash(word);

    node *tmp = table[index];

    node *new_node = malloc(sizeof(node));

    if (new_node == NULL) return false;

    strcpy(new_node->word, word);

    new_node->next = tmp;
    table[index] = new_node;

    num_words++;
  }

  fclose(source);
  return true;
}

unsigned int size(void) {
  return num_words;
}

bool unload(void) {
  for (int i = 0; i < N; i++) {
    node *n = table[i];
    while (n) {
      node *tmp = n;
      n = n->next;
      free(tmp);
    }
  }

  return true;
}
