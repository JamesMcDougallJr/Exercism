#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>

#define SUCCESS 1
#define FAIL 255

typedef int buffer_value_t;
typedef int circular_buffer_t;

int write(circular_buffer_t *buffer, buffer_value_t value);
int overwrite(circular_buffer_t *buffer, buffer_value_t value);
int16_t read(circular_buffer_t *buffer, buffer_value_t *buf_val);
void delete_buffer(circular_buffer_t *buffer);
circular_buffer_t *new_circular_buffer(size_t capacity);
void clear_buffer(circular_buffer_t *buffer);

#endif
