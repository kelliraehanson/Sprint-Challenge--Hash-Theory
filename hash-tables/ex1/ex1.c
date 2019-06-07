#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  /* YOUR CODE HERE */
for (int i = 0; i < length; i ++) { // Put everything into hash table
int weight = weights[i];
int total = limit - weight;
int index = hash_table_retrieve(ht, total);

if (index != -1) { // When calling `hash_table_retrieve` with a key that doesn't exist 
// in the hash table, `hash_table_retrieve` will return -1. When index is not equal to -1.
Answer *data = malloc(sizeof(Answer)); // Malloc is used to allocate a block of memory on the heap. 
// The program accesses this block of memory via a pointer that malloc returns. 
data->index_1 = i; // set in the i
data->index_2 = index; // the arrow operator (->) 
// in C is used to access a member of a struct which is referenced by the pointer in question.
return data; // Retrun data
}

hash_table_insert(ht, weight, i); // Insert (add) the weight and current i (index) to the hash table.
}

destroy_hash_table(ht); // Free ht
  return NULL;
}


void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{
  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1);  // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer* answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2);  // {1, 0}

  // TEST 3
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer* answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3);  // {3, 1}

  // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4);  // {6, 2}

  return 0;
}

#endif
