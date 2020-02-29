#include <cstdlib>
#include <cstdio>
#include "sort.h"
#include "acceptance_test.h"

int main() {
  size_t N = 10000;
  int *array = (int *) malloc(sizeof(int) * N);

  if (!test_sort(array, N, bubble_sort)) {
    printf("bubble sort failed\n");
  }
  if (!test_sort(array, N, heap_sort)) {
    printf("heap sort failed\n");
  }

  if (!test_sort(array, N, bubble_sort_mutant)) {
    printf("bubble sort mutant failed\n");
  }
  if (!test_sort(array, N, heap_sort_mutant)) {
    printf("heap sort mutant failed\n");
  }

  free(array);
  return 0;
}
