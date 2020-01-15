#include "word_count.h"
#include <stdlib.h>

/**
 * Loop over the input text. Create word_count_word_t structs as you go.
 * If you encounter a new word, look for it in the array. If its not there, 
 * we'll create a new one
 */
int word_count(const char *input_text, word_count_word_t * words) {
  int index = 0;
  int str_begin_index = 0;
  while(input_text[index] != '\0') {
    printf("%c", input_text[index]);
    if ( input_text[index] == ' ') {
      char *substr = substring(input_text, str_begin_index, index - str_begin_index);
    }
    index++;
  }
}

/**
 * If the given word exists in the array, add it. Otherwise, create
 * a new struct
 */ 
void count_word(const char *word, word_count_word_t *words) {

}