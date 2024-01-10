// Implements a dictionary's functionality

#include "dictionary.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t BYTE;

// Represents a node in a hash table
typedef struct node {
  char word[LENGTH + 1];
  struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word) {
  // TODO
  return false;
}

// Hashes word to a number
unsigned int hash(const char *word) {
  // TODO: Improve this hash function
  return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary) {
  FILE *source = fopen(dictionary, "r");
  BYTE buffer;

  char word[LENGTH + 1];

  while (fscanf(source, "%s", word) != EOF) {
    unsigned int index = hash(word);

    node *tmp = table[index];

    node *new_node = malloc(sizeof(node));
    strcpy(new_node->word, word);

    new_node->next = tmp;
    table[index] = new_node;
  }

  fclose(source);
  return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void) {
  // TODO
  return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void) {
  // TODO
  return false;
}
