#include <stddef.h>
#include <stdbool.h>
#include "vendor/unity.h"
#include "../src/linked_list.h"

LinkedList *list = NULL;

void setUp(void)
{
   list = new_list();
}

void tearDown(void)
{
   if (list != NULL) {
      delete_list(list);
      list = NULL;
   }
}

static void test_new_list(void)
{
   TEST_ASSERT_NOT_NULL(list);
}

static void test_is_list_empty_when_empty(void)
{
   printf("test_is_list_empty_when_empty begin\n");
   TEST_ASSERT_TRUE(is_list_empty(list));
   delete_list(list);
   list = NULL;                 // stop list from dangling
   TEST_ASSERT_TRUE(is_list_empty(list));
   printf("test_is_list_empty_when_empty end\n");
}

static void test_is_list_empty_when_not_empty(void)
{
   // pre-populate list
   printf("Is list empty when not empty begin\n");
   ll_data_t data = 12;
   push(list, data);
   TEST_ASSERT_FALSE(is_list_empty(list));
   printf("Is list empty when not empty end\n");
}

static void test_push_with_invalid_list(void)
{
   printf("test push with invalid list begin\n");
   ll_data_t data = 13;
   TEST_ASSERT_FALSE(push(NULL, data));
   printf("test push with invalid list end\n");
}

static void test_push_with_valid_list(void)
{
   printf("test push with valid list begin\n");
   for (size_t data = 14; data < 19; ++data) {
      TEST_ASSERT_TRUE(push(list, data));
   } 
   printf("test push with valid list end\n");
}

static void test_pop_returns_list_data(void)
{
   printf("test_pop_returns_list_data begin\n");
   // pre-populate list
   for (size_t data = 11; data <= 15; ++data) {
      push(list, data);
   }
   for (size_t data = 15; data >= 11; --data) {
      TEST_ASSERT_EQUAL(data, pop(list));
   }
   printf("test_pop_returns_list_data end\n");
}

static void test_unshift_with_invalid_list(void)
{
   printf("test_unshift_with_invalid_list begin \n");
   ll_data_t data = 16;
   TEST_ASSERT_FALSE(unshift(NULL, data));
   printf("test_unshift_with_invalid_list end \n");
}

static void test_unshift_with_valid_list(void)
{
   printf("test_unshift_with_valid_list begin\n");
   for (size_t data = 14; data < 19; ++data) {
      TEST_ASSERT_TRUE(unshift(list, data));
   }
   printf("test_unshift_with_valid_list end\n");
}

static void test_shift_returns_list_data(void)
{
   // pre-populate list
   for (size_t data = 12; data < 17; ++data) {
      push(list, data);
   }

   for (size_t data = 12; data < 17; ++data) {
      TEST_ASSERT_EQUAL(data, shift(list));
   }
}

int main(void)
{
   UnityBegin("test/test_linked_list.c");

   RUN_TEST(test_new_list);
   RUN_TEST(test_is_list_empty_when_empty);
   RUN_TEST(test_is_list_empty_when_not_empty);
   RUN_TEST(test_push_with_invalid_list);
   RUN_TEST(test_push_with_valid_list);
   RUN_TEST(test_pop_returns_list_data);
   RUN_TEST(test_unshift_with_invalid_list);
   RUN_TEST(test_unshift_with_valid_list);
   RUN_TEST(test_shift_returns_list_data);

   return UnityEnd();
}
