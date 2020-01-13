#include "resistor_color_trio.h"
#include <stdio.h>
resistor_value_t color_code(resistor_band_t bands[])
{
  uint16 colorCodeSum = 0;
  colorCodeSum += 10 * bands[0];
  colorCodeSum += bands[1];
  printf("%d\n", (int)bands[2]);
  for(int i = 0; i < (int)bands[2]; i++) {
    colorCodeSum *= 10;
  }
  if (colorCodeSum < (uint16) KILOOHMS)
  {
      resistor_value_t resistor = { .value = colorCodeSum, .unit = OHMS};
    return resistor;
  }
  else
  {
    colorCodeSum /= (int)KILOOHMS;
    resistor_value_t resistor = { .value = colorCodeSum, .unit = KILOOHMS};
    return resistor;
  }
}
