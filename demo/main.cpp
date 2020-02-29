// #define N_VERSION
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include "acceptance_test.h"
#include "sort.h"
#include <vector>
#include <string>
#include <iostream>

void n_version_recovery_block(int *array,
                              int *array_copy,
                              size_t N,
                              std::vector<sort_func_t> sort_funcs,
                              std::vector<std::string> func_names) {
  size_t n_funcs = sort_funcs.size();
  for (size_t i = 0; i < n_funcs; ++i) {
    memcpy(array_copy, array, N * sizeof(int));
    std::cout << "calling " << func_names[i] << "\n";
    sort_funcs[i](array_copy, N);
    if (!acceptance_test(array_copy, N)) {
      std::cout << func_names[i] << " failed\n";
    } else {
      std::cout << func_names[i] << " succeeded\n";
      break;
    }
  }
}

int main() {
  size_t N = 10000;
  int *array = (int *) malloc(sizeof(int) * N);
  int *array_copy = (int *) malloc(sizeof(int) * N);
  srand48(time(nullptr));
  for (int i = 0; i < N; ++i) { array[i] = (int) lrand48(); }
  #ifndef N_VERSION
  std::cout << "Calling bubble_sort_mutant\n";
  memcpy(array_copy, array, N * sizeof(int));
  bubble_sort_mutant(array_copy, N);
  if (!acceptance_test(array_copy, N)) {
    std::cout << "bubble_sort_mutant failed, fallback to heap_sort\n";
    memcpy(array_copy, array, N * sizeof(int));
    heap_sort(array_copy, N);
    if (!acceptance_test(array_copy, N)) {
      std::cout << "heap_sort failed\n";
      abort();
    } else {
      std::cout << "heap_sort success\n";
    }
  } else {
    std::cout << "bubble_sort success\n";
  }
  #else
  auto funcs = std::vector<sort_func_t>{bubble_sort_mutant, heap_sort_mutant, bubble_sort, heap_sort};
  auto func_names = std::vector<std::string>{"bubble_sort_mutant", "heap_sort_mutant", "bubble_sort", "heap_sort"};
  n_version_recovery_block(array, array_copy, N, funcs, func_names);
  #endif
  return 0;
}
