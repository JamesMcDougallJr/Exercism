#include "resistor_color_duo.h"
#include<stdio.h>

/*
 * returns the code created by the first two elements in the input array.
 * If the 1st or 2nd array value is garbage, it will return a garbage value
 */
uint16_t color_code (resistor_band_t bands[]) {
  int colorCodeSum = 0;
  colorCodeSum += (10*bands[0]);
  colorCodeSum += bands[1];
  return colorCodeSum;
}
