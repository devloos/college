#include "fast_sort.h"

const char first_name[] = "Carlos";
const char last_name[] = "Aguilera";

void fast_sort(int *a, size_t size) {
  // nothing to sort just return
  if (size < 1) {
    return;
  }

  int pvt = a[size / 2];
  int i = 0;
  int j = size - 1;

  while (i <= j) {
    // what are we saying here?
    // if its already less than pvt than go ahead and leave it where it is
    while (a[i] < pvt) {
      ++i;
    }

    // same as above condition but greater than
    while (a[j] > pvt) {
      --j;
    }

    // we have reached the negation of the above two conditions therefore we
    // perform swap Reason is simple i and j values are greater and less than
    // pvt respectively
    if (i <= j) {
      int t = a[i];
      a[i] = a[j];
      a[j] = t;

      // since we swapped and values are not positioned correctly we can inc
      ++i;
      --j;
    }
  }

  // by this point we have succesfully put all elements less than pvt to the
  // left and elements greater than pvt to the right

  // do left side
  if (j > 0) {
    fast_sort(a, j + 1);
  }

  // do right side
  if (i < size) {
    fast_sort(a + i, size - i);
  }
}