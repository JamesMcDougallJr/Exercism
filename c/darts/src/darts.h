#ifndef DARTS_H
#define DARTS_H

#define CENTER_POINTS 10
#define MIDDLE_POINTS 5
#define OUTER_POINTS 1
#define OUT_OF_BOUNDS_POINTS 0

#define OUTER 10
#define MIDDLE 5
#define CENTER 1

typedef struct {
  float x;
  float y;
} coordinate_t;

typedef unsigned char uint8_t;
uint8_t score(coordinate_t landingPosition);
#endif
