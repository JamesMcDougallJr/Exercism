#include "linked_list.h"


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
  return list->size;
}

/**
 * push appends and item to the list
 * Param list is a pointer to the list to append to
 * Param item_data is the data of the new node
 */
bool push(LinkedList *list, ll_data_t item_data) {
  ListNode *new_tail = (ListNode*) malloc(sizeof(ListNode));
  if (new_tail) {
    new_tail->data = item_data;
    new_tail->prev = list->tail; // the new item's prev is the old tail
    list->tail->next = new_tail; // the old list's tail's next is the new node
    list->tail = new_tail; // the list's new tail is, well, the new node
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
  old_tail_data = old_tail->data; // save the data since it will be free'd
  free(old_tail); // free the old tail, since it's being removed
  return old_tail_data;
}

/**
 * shift removes an item from the front of the list,
 * such that the head is not pointing to the 2nd item
 * Param list is a pointer to a LinkedList struct
 */
ll_data_t shift(LinkedList *list) {

  return 0;
}


bool prepend(LinkedList *list, ll_data_t item_data) {
  return 0;
}

/**
 * delete_list will deallocate all memory associated with
 * this object
 * Param list is the object to deallocate
 */
void delete_list(LinkedList *list) {
  return ;
}
