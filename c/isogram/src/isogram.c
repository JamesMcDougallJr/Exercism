#include "isogram.h"
#include <stdio.h>

bool is_isogram(const char phrase[]) {
  if (!phrase) return false;
  char all_chars[ASCII_SIZE] = {0};
  unsigned int index = 0;
  while (phrase[index] != '\0') {
    unsigned int to_int = (unsigned int) phrase[index];
    //printf("Char %c converted to int %d\n", phrase[index], to_int);
    if (all_chars[to_int] != 0 && phrase[index] != '-' && phrase[index] != ' ') {
      return false;
    } else if (is_letter(to_int)) {
      int difference = 'a' - 'A';
      if (to_int < 'a' && (all_chars[to_int] != 0 || all_chars[to_int+difference])) {
        // then it is the capital
        return false;
      } else if(all_chars[to_int] != 0 || all_chars[to_int-difference] != 0) {
        // then is is the lower case version
        return false;
      }
    }
    all_chars[to_int] = 1;
    index++;
  }
  return true;
}

bool is_letter(unsigned int check_is_letter) {
  return (check_is_letter >= 65 && check_is_letter <= 90) || (check_is_letter >= 97 && check_is_letter <= 122);
}
