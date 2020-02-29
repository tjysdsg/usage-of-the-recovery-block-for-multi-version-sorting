#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <memory.h>
#include "acceptance_test.h"
#include "sort.h"

int main() {
  size_t N = 10000;
  int *array = (int *) malloc(sizeof(int) * N);
  int *array_copy = (int *) malloc(sizeof(int) * N);
  srand48(time(nullptr));
  for (int i = 0; i < N; ++i) { array[i] = (int) lrand48(); }
  printf("Calling bubble_sort_mutant\n");
  memcpy(array_copy, array, N * sizeof(int));
  bubble_sort_mutant(array_copy, N);
  if (!acceptance_test(array_copy, N)) {
    printf("bubble_sort_mutant failed, fallback to heap_sort\n");
    memcpy(array_copy, array, N * sizeof(int));
    heap_sort(array_copy, N);
    if (!acceptance_test(array_copy, N)) {
      printf("heap_sort failed\n");
      abort();
    } else {
      printf("heap_sort success\n");
    }
  } else {
    printf("bubble_sort success\n");
  }
  return 0;
}
