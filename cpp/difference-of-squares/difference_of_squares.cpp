#include "difference_of_squares.h"

namespace difference_of_squares {

  int square_of_sum (int n) {
    return (n*(n+1) / 2)*(n*(n+1)/2);
  }

  int sum_of_squares(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
      sum += i*i;
    }
    return sum;
  }

  int difference(int n) {
    int sum_of = sum_of_squares(n);
    int square_of = square_of_sum(n);
    int diff = sum_of - square_of;
    return diff < 0 ? diff*(-1) : diff;
  }

}  // namespace difference_of_squares
