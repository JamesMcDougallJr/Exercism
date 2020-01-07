#include "armstrong_numbers.h"
#include <stdio.h>
/**
 * is_armstrong_number 
 */
int is_armstrong_number(int candidate) {
  printf("Candidate: %d\n", candidate);
  printf("Candidate / 10: %d\n", candidate/10);
  int candidateTo0 = candidate;
  int numDigits = 1;
  while(candidateTo0 > 0) {
    numDigits++;
    candidateTo0 /= 10;
  }
  printf("numDigits: %d\n", numDigits);
  
  return 0;
}
