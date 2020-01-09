#include "armstrong_numbers.h"
#include <stdio.h>
/**
 * is_armstrong_number 
 */
int is_armstrong_number(int candidate) {
  printf("Candidate: %d\n", candidate);
  printf("Candidate / 10: %d\n", candidate/10);
  int candidateTo0 = candidate/10;
  int numDigits = 1;
  while(candidateTo0 > 0) {
    numDigits++;
    candidateTo0 /= 10;
  }
  printf("numDigits: %d\n", numDigits);

  int sum = 0;
  candidateTo0 = candidate;
  while (candidateTo0 > 0) {
    int lastDigit = candidateTo0 % 10;
    candidateTo0 /= 10;
    int toAddToSum = 1;
    for(int i = 0; i < numDigits; i++) {
      toAddToSum *= lastDigit;
    } 
    sum += toAddToSum;
  }
  printf("Sum: %d\n", sum);
  return sum == candidate;
}
