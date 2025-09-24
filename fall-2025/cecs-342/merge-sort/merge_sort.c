#include "merge_sort.h"
#include <stdlib.h>
#include <string.h>

// [2, 1, 4, 3, 5, 6]
// [2, 1], [4,3,5,6]
// [2, 1, 4], [3, 5, 6]
// [2, 1], [4], [3,5], [6]
// [2], [1], [4], [3], [5], [6]
// [1, 2], [3, 4], [5, 6]
// [1, 2, 3, 4], [5, 6]
void sort(int *a, int *tmp, size_t left, size_t right) {
  if (right - left <= 1) {
    return;
  }

  size_t mid = left + (right - left) / 2; // e.g. 2

  // mid = 1, left = 0, right 1
  // mid = 2, left = 0, right 4
  sort(a, tmp, left, mid);
  sort(a, tmp, mid, right);

  //   tried to optimize here but failed
  //   if (a[mid - 1] <= a[mid]) {
  //     memcpy(tmp + left, a[left], mid - 1);
  //     memcpy(tmp + left, a[left], mid + right);
  //     return;
  //   }

  size_t l = left;
  size_t j = mid;

  size_t k = left; // start at left and fill up tmp

  // essentially which ever finishes first depending on elements
  while (l < mid && j < right) {
    if (a[l] <= a[j]) {
      tmp[k++] = a[l++];
    } else {
      tmp[k++] = a[j++];
    }
  }

  // either l or r will still have elements so clean them up by simply appending
  // this is valid because the array that still has elements will be sorted
  while (l < mid) {
    tmp[k++] = a[l++];
  }

  while (j < right) {
    tmp[k++] = a[j++];
  }

  // Copy merged run back to a
  memcpy(a + left, tmp + left, sizeof(int) * (right - left));
}

void merge_sort(int *a, size_t n) {
  int *tmp = malloc(sizeof(int) * n);

  sort(a, tmp, 0, n);

  free(tmp);
}