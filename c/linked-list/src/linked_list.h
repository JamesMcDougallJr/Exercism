#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#define TRUE 1
#define FALSE 0
typedef int ll_data_t;

typedef struct ListNode
{
  ll_data_t data;
  struct ListNode *next;
  struct ListNode *prev;
} ListNode;

// A structure to allow me to know the tail and the size of the linked list
// Most implementations on't have the head which isn't as useful to me
typedef struct LinkedList {
  int size;
  ListNode *head, *tail;
} LinkedList;

// constructs a new list of items
LinkedList *new_list(void);

// checks if the list is empty
bool is_list_empty(LinkedList *list);

// inserts item at back of list
bool push(LinkedList *list, ll_data_t item_data);

// removes item from back of list
ll_data_t pop(LinkedList *list);

// removes item from front of list
ll_data_t shift(LinkedList *list);

// inserts item at front of list
bool unshift(LinkedList *list, ll_data_t item_data);

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(LinkedList *list);

#endif
