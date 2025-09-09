#include <stdio.h>

// AI explanation here:
/*
  Quick sort is a divide-and-conquer algorithm:
  1. Pick a pivot (an element from the array).
  2. Partition: Rearrange the array so:
  3. All elements less than the pivot are on the left.
  4. All elements greater than the pivot are on the right.
  5. Recurse: Apply the same steps to the left and right sub-arrays.
  6. Stop when sub-arrays have 0 or 1 element → they’re already sorted.
*/

// TOOLS USED:
// vscode, gcc, ghosty terminal, chat gpt for explaining algorithm

void quick_sort(int *arr, int size) {
  // arr [3, 24, 5, 23, 2, 19, 21]
  // size = 7

  if (size <= 1) {
    return;
  }

  int pivot = arr[size / 2];
  int i = 0;
  int j = size - 1; // start at the ned

  while (i <= j) {
    // move pointer "i" up if less than pivot
    while (arr[i] < pivot) {
      ++i;
    }

    // move pointer "j" down if greater than pivot
    while (arr[j] > pivot) {
      --j;
    }

    // perform swap
    if (i <= j) {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;

      ++i;
      --j;
    }
  }

  // BY THIS POINT i IS GREATER THAN j
  // ofc on each recursive call
  // visual [3, 2, 5, 23, 24, 21, 19]
  //               j      i

  if (j > 0) {
    // opposite j acts as i
    // in other words we are working on the left hand side
    // this also handles the previous pivot point
    quick_sort(arr, j + 1);
  }

  if (i < size) {
    // left side gets removed 3, 2, 5, 23
    // visual [24, 21, 19]
    //          i
    // size - i === 7 - 4 = 3 (which is our new size)
    quick_sort(arr + i, size - i);
  }
}

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

  quick_sort(arr, size);

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
  printf("CECS 342 Assignment 1\n");
  printf("Name: Carlos Aguilera\n");
  printf("Algorithm: quick sort, Language: C\n\n");

  run_test_case(NULL, 0);

  int test_case_input_1[] = {3};
  run_test_case(test_case_input_1, 1);

  int test_case_input_2[] = {3, 2, 1};
  run_test_case(test_case_input_2, 3);

  int test_case_input_3[] = {42, -33, 102, -74, 30, 1, 1000, -756, 33, -7, 10};
  run_test_case(test_case_input_3, 11);

  return 0;
}