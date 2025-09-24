#include "merge_sort.h"
#include <stdio.h>

// AI explanation here:
/*
  So, in C, when you implement it, you’ll be:
  Recursively splitting the array.
  Using a merge function that merges two sorted halves into one sorted array.
  Copying the result back into the original array.
*/

// TOOLS USED:
// vscode, gcc, ghosty terminal, chat gpt for explaining algorithm

void run_test_case(int *arr, int size) {
  printf("Input: {");
  for (int i = 0; i < size; i++) {
    // if not at end print with comma
    if (i + 1 < size) {
      printf("%d, ", arr[i]);
    } else {
      printf("%d", arr[i]);
    }
  }
  printf("}\n");

  merge_sort(arr, size);

  printf("Sorted: {");
  for (int i = 0; i < size; i++) {
    // if not at end print with comma
    if (i + 1 < size) {
      printf("%d, ", arr[i]);
    } else {
      printf("%d", arr[i]);
    }
  }
  printf("}\n\n");
}

int main(void) {
  printf("CECS 342 Assignment 3\n");
  printf("Name: Carlos Aguilera\n");
  printf("Algorithm: merge sort, Language: C\n\n");

  run_test_case(NULL, 0);

  int test_case_input_1[] = {3};
  run_test_case(test_case_input_1, 1);

  int test_case_input_2[] = {3, 2, 1};
  run_test_case(test_case_input_2, 3);

  int test_case_input_3[] = {42, -33, 102, -74, 30, 1, 1000, -756, 33, -7, 10};
  run_test_case(test_case_input_3, 11);

  return 0;
}