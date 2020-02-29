#include "sort.h"

void bubble_sort(int arr[], size_t n) {
  int c, d, t;
  for (c = 0; c < n - 1; ++c) {
    for (d = 0; d < n - c - 1; ++d) {
      if (arr[d] > arr[d + 1]) {
        // swapping
        t = arr[d];
        arr[d] = arr[d + 1];
        arr[d + 1] = t;
      }
    }
  }
}

void heap_sort(int arr[], size_t N) {
  unsigned int n = N, i = n / 2, parent, child;
  int t;
  for (;;) {
    if (i > 0) {
      i--;
      t = arr[i];
    } else {
      n--;
      if (n == 0) {
        return;
      }
      t = arr[n];
      arr[n] = arr[0];
    }
    parent = i;
    child = i * 2 + 1;
    while (child < n) {
      if (child + 1 < n && arr[child + 1] > arr[child]) {
        child++;
      }
      if (arr[child] > t) {
        arr[parent] = arr[child];
        parent = child;
        child = parent * 2 + 1;
      } else {
        break;
      }
    }
    arr[parent] = t;
  }
}

void bubble_sort_mutant(int arr[], size_t n) {
  int c, d, t;
  // for (c = 0; c < n - 1; ++c) {
  for (c = 1 /* FIXME: MUTATION HERE */; c < n - 1; ++c) {
    for (d = 0; d < n - c - 1; ++d) {
      if (arr[d] > arr[d + 1]) {
        // swapping
        t = arr[d];
        arr[d] = arr[d + 1];
        arr[d + 1] = t;
      }
    }
  }
}

void heap_sort_mutant(int arr[], size_t N) {
  unsigned int n = N, i = n / 2, parent, child;
  int t;
  for (;;) {
    if (i > 0) {
      i--;
      t = arr[i];
    } else {
      n--;
      if (n == 0) {
        return;
      }
      t = arr[n];
      arr[n] = arr[0];
    }
    parent = i;
    // child = i * 2 + 1;
    child = i * 2 /* FIXME: MUTATION HERE */;
    while (child < n) {
      if (child + 1 < n && arr[child + 1] > arr[child]) {
        child++;
      }
      if (arr[child] > t) {
        arr[parent] = arr[child];
        parent = child;
        child = parent * 2 + 1;
      } else {
        break;
      }
    }
    arr[parent] = t;
  }
}
