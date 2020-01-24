#include "acronym.h"
#include <stdlib.h>
#include <stdio.h>

char *abbreviate(const char *phrase) {
  char *abbreviation;
  int i = 0;
  int numChars = 1;
  while(phrase[i] != '\0') {
    if(phrase[i] == ' ') {
      numChars++;
    }
    i++;
  }
  abbreviation = (char*) malloc(sizeof(char) * numChars);
  i = 1;
  int abbrevIndex = 1;
  abbreviation[0] = phrase[0];
  while(phrase[i] != '\0') {
    if(phrase[i] == ' ') {
      abbreviation[abbrevIndex++] = phrase[i+1];
    }
    i++;
  }
  return abbreviation;
}
