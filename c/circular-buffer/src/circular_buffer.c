#include "circular_buffer.h"

static int buf_index = -1;
static int Capacity = 0;

/**
 * write the value to the buffer at the end of the array. If full,
 * do not overwrite, rather throw an error
 */
int write(circular_buffer_t *buffer, buffer_value_t value) {
  if(buf_index >= Capacity) {
    return FAIL;
  } else {
    buffer[buf_index++] = value;
  }
  return SUCCESS;
}

/**
 * Write the value to the buffer. If the buffer is full, overwrite 
 * the next index (i.e. the oldest one)
 */
int overwrite(circular_buffer_t *buffer, buffer_value_t value) {
  buffer[buf_index++ % Capacity] = value;
  return SUCCESS;
}
int16_t read(circular_buffer_t *buffer, buffer_value_t *buf_val) {
  printf("%d\n", buf_index);
  if(buf_index <= 0) return EXIT_FAILURE;
  return buffer[*buf_val];
}
void delete_buffer(circular_buffer_t *buffer) {
  free(buffer);
}
circular_buffer_t *new_circular_buffer(size_t capacity) {
  buf_index = 0;
  circular_buffer_t *buf = (circular_buffer_t*)malloc(sizeof(int)*capacity);
  memset(buf, -1, capacity);
  Capacity = capacity;
  return buf;
}
void clear_buffer(circular_buffer_t *buffer) {
  free(buffer);
}
