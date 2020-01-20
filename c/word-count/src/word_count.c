#include "word_count.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int count_word(word_count_word_t * words, char *word);

/**
 * Loop over the input text. Create word_count_word_t structs as you go.
 * If you encounter a new word, look for it in the array. If its not there, 
 * we'll create a new one
 */
int word_count(const char *input_text, word_count_word_t * words) {
  int index = 0;
  int beginning_of_word = 0;
  int num_words = 0;
  int word_length = 0;
  int num_unique = 0;
  while(input_text[index] != '\0') {
    if(num_words > MAX_WORDS) return EXCESSIVE_NUMBER_OF_WORDS;
    if(input_text[index] == ' ') {
      word_length = index - beginning_of_word;
      char substring[word_length];
      strncpy(substring, &input_text[beginning_of_word], word_length);
      substring[word_length] = '\0';
      printf("Substring %s\n", substring);
      num_unique += count_word(words, substring);
    }
  }
  return num_unique;
}

int count_word(word_count_word_t *words, char *word) {
  int i;
  for(i = 0; i < )
}
