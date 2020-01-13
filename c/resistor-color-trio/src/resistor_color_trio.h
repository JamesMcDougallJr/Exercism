#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H
typedef int uint16;
typedef enum resistor_band_t {
  BLACK = 0,
  BROWN = 1,
  RED = 2,
  ORANGE = 3,
  YELLOW = 4,
  GREEN = 5,
  BLUE = 6,
  VIOLET = 7,
  GREY = 8,
  WHITE = 9,
} resistor_band_t;

typedef enum unit_t {
  OHMS = 1,
  KILOOHMS = 1000,
} unit_t;

typedef struct resistor_value_t {
  unit_t unit;
  uint16 value;
} resistor_value_t;

resistor_value_t color_code(resistor_band_t[]);

#endif
