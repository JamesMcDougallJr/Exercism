#include "rna_transcription.h"
#include <stdlib.h>
#include <stdio.h>

char *to_rna(const char *dna) {
  int length = 0;

  while(dna[length] != '\0') {
    length++;
  }

  int index = 0;
  char *transcription = (char*) malloc(sizeof(char)*length);
  while (dna[index] != '\0') {
    if(dna[index] == 'G') {
      transcription[index] = 'C';
    } else if(dna[index] == 'C') {
      transcription[index] = 'G';
    } else if(dna[index] == 'T') {
      transcription[index] = 'A';
    } else if(dna[index] == 'A') {
      transcription[index] = 'U';
    } else {
      printf("Invalid Char: %c\n", dna[index]);
    }
  }
  return transcription;
}
