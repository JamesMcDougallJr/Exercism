#include "acronym.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *abbreviate(const char *phrase) {
  if(!phrase) return 0;
  if(phrase[0] =='\0') return NULL;
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
  abbreviation[0] = toupper(phrase[0]);
  while(phrase[i] != '\0') {
    if(phrase[i] == ' ' || phrase[i] == '-' ) {
      abbreviation[abbrevIndex++] = toupper(phrase[i+1]);
    }
    i++;
  }
  return abbreviation;
}
