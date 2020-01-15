#include "word_count.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Loop over the input text. Create word_count_word_t structs as you go.
 * If you encounter a new word, look for it in the array. If its not there, 
 * we'll create a new one
 */
int word_count(const char *input_text, word_count_word_t * words) {
  int index = 0, str_begin_index=0, unique_words= 0;

  printf("Input Text: %s\n", input_text);
  while(input_text[index] != '\0') {
    printf("Character: %c\n", input_text[index]);
    if ( input_text[index] == ' ' && index - str_begin_index < MAX_WORD_LENGTH) {
      char substr[index - str_begin_index];
      memcpy( substr, &input_text[str_begin_index], index - str_begin_index );
      substr[index] = '\0';
      printf("Substring : %s\n", substr);
      if(count_word(substr, words, index-str_begin_index))
      {
        unique_words++;
      }
      str_begin_index = index + 1;
    } else if(input_text[index] == ' ') // if the character was too long
    {
      // don't add this word, but still update the str_begin_index
      str_begin_index = index + 1;
    }
    index++;
  }
  char substr[index - str_begin_index];
  memcpy(substr, &input_text[str_begin_index], index - str_begin_index);
  substr[index] = '\0';
  printf("Substr: %s\n",substr);
  if(count_word(substr, words, index-str_begin_index)) // if new word
  {
    unique_words++;
  }
  return unique_words;
}

/**
 * If the given word exists in the array, add it. Otherwise, create
 * a new struct
 */
int count_word(const char *word, word_count_word_t *words, int string_length) {
  int i;
  for(i = 0; i < MAX_WORDS; i++) {
    if(words[i].count == 0) // If we find the first null struct
    {
      // put the given word in a new struct
      memcpy(&(words[i].text), word, string_length);
      words[i].count = 1;
      return TRUE;
    } else if(strcmp(words[i].text, word) == 0)
    {
      // this word is already in my array, increment
      words[i].count ++;
      return FALSE;
    }
  }
  return FALSE;
}
