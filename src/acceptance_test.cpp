#include "acceptance_test.h"
#include <ctime>
#include <cstdlib>

bool acceptance_test(const int *array, size_t N) {
  for (int i = 0; i < N - 1; ++i) {
    if (array[i] > array[i + 1]) {
      return false;
    }
  }
  return true;
}

bool test_sort(int *array, size_t N, sort_func_t sort_func) {
  srand48(time(nullptr));
  for (int i = 0; i < N; ++i) { array[i] = (int) lrand48(); }
  sort_func(array, N);
  return acceptance_test(array, N);
}

