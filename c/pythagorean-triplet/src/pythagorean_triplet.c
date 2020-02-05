#include "pythagorean_triplet.h"

triplets_t triplets_with_sum(int N) {
  int m;
  int n;
  for(m = 0; m < N; m++) {
    for(n = 0; n < N; n++) {
      if (2*m*(m+n)) {
        int triplet[SIZEOFTRIPLET];
        triplet[0] = (m*m) - (n*n);
        triplet[1] = (2*m*n);
        triplet[2] = (m*m) + (n*n);
        return triplet;
      }
    }
  }
}