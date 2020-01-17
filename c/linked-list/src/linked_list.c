#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * new_list returns a pointer to an empty LinkedList structure
 */
LinkedList *new_list(void) {
  LinkedList *list = (LinkedList*) malloc(sizeof(LinkedList));
  list->size = 0;
  return list;
}

// checks if the list is empty
bool is_list_empty(LinkedList *list) {
  if(list) {
    printf("Is list empty: %u\n", list->size);
    return list->size == 0;
  }
  return TRUE;
}

/**
 * push appends and item to the list
 * Param list is a pointer to the list to append to
 * Param item_data is the data of the new node
 */
bool push(LinkedList *list, ll_data_t item_data) {
  ListNode *new_tail = (ListNode*) malloc(sizeof(ListNode));
  if(!list) return FALSE;
  if (new_tail) {
    new_tail->data = item_data; // initialize the nnew node

    if (list->tail) // if the tail is not null, just append
    {
      new_tail->prev = list->tail; // the new item's prev is the old tail
      list->tail->next = new_tail; // the old list's tail's next is the new node
      list->tail = new_tail; // the list's new tail is, well, the new node
    } else // if the tail is null, the  list is empty
    {
      list->tail = new_tail;
      list->head = new_tail;
    }
    list->size++;
    return TRUE;

  }
  return FALSE;
}

/**
 * pop removes the tail, deallocating its memory but returning its value
 * Param list is a pointer to a LinkedList struct
 */
ll_data_t pop(LinkedList *list) {
  ListNode *old_tail = list->tail; // grab a pointer to the old tail
  list->tail = old_tail->prev; // the new tail is the 2nd to last item
  ll_data_t old_tail_data = old_tail->data; // save the data since it will be free'd
  if(old_tail) free(old_tail); // free the old tail, since it's being removed
  else printf("Old tail not valid to free: %p\n", (void*) old_tail);
  list->size--;
  return old_tail_data;
}

/**
 * shift removes an item from the front of the list,
 * such that the head is not pointing to the 2nd item
 * Param list is a pointer to a LinkedList struct
 */
ll_data_t shift(LinkedList *list) {
  ListNode *head_ptr = list->head;
  ll_data_t head_data = head_ptr->data;
  list->head = head_ptr->next;
  printf("Head_ptr %p\n", (void*) head_ptr);
  if(head_ptr) free(head_ptr);
  else printf("head_ptr not valid to be free'd: %p\n", (void*) head_ptr);
  list->size--;
  return head_data;
}

/**
 * Basically prepend
 */
bool unshift(LinkedList *list, ll_data_t item_data) {
  ListNode *new_node = (ListNode *) malloc(sizeof(ListNode));
  if(new_node) {
    new_node->data = item_data;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
    return TRUE;
  }
  return FALSE;
}

/**
 * delete_list will deallocate all memory associated with
 * this object
 * Param list is the object to deallocate
 */
void delete_list(LinkedList *list) {
  ListNode *current = list->head;
  ListNode *next;
  int i;
  for(i = 0; i < list->size; i++) {
    if(current) {
      next = current->next;
      free(current);
      current = next;
    } else
    {
      printf("Why is current not valid: %p\n", (void*) current);
    }
  }
}
