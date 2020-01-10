#include "darts.h"

unsigned char score(coordinate_t pos) {
  float squared_distance = pos.x * pos.x + pos.y * pos.y;
  if (squared_distance <= CENTER*CENTER) return CENTER_POINTS;
  else if (squared_distance <= MIDDLE*MIDDLE) return MIDDLE_POINTS;
  else if (squared_distance <= OUTER*OUTER) return OUTER_POINTS;
  return OUT_OF_BOUNDS_POINTS;
}
