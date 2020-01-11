#ifndef RESISTOR_COLOR_H
#define RESISTOR_COLOR_H
typedef int resistor_band_t; 

enum Color { BLACK = 0,
  BROWN = 1,
  RED = 2,
  ORANGE = 3,
  YELLOW = 4,
  GREEN = 5,
  BLUE = 6,
  VIOLET = 7,
  GREY = 8,
  WHITE = 9,
};

static int colorList[] = {BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE};

const resistor_band_t * colors();
int color_code(resistor_band_t code);

#endif
