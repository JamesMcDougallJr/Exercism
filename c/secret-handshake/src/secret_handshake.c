#include "secret_handshake.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char **commands(size_t number) {
  const char **command_list = (const char **) malloc(sizeof(char*) * MAX_COMMANDS);
  memset(command_list, 0, sizeof(char*)*MAX_COMMANDS);
  if(number == 0) return command_list;
  int comm_index = 0;
  if(number & 1) command_list[comm_index++] = "wink";
  if(number & 2) command_list[comm_index++] = "double blink";
  if(number & 4) command_list[comm_index++] = "close your eyes";
  if(number & 8) command_list[comm_index++] = "jump";
  if(number & 16) {
    const char **reversed = (const char**) malloc(sizeof(char*) * MAX_COMMANDS);
    int i;
    int j = 0;
    for(i = MAX_COMMANDS - 1; i >= 0; i--)
    {
      if(command_list[i] != NULL) {
        printf("Command List [%d]: %s\n", i, command_list[i]);
        reversed[j++] = command_list[i];
      }
    }
    free(command_list);
    return reversed;
  }
  return command_list;
}
