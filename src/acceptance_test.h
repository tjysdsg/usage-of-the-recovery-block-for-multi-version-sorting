#ifndef __RECOVERY_BLOCK_FOR_MULTI_VERSION_SORTING_TESTS_ACCEPTANCE_TEST_H__
#define __RECOVERY_BLOCK_FOR_MULTI_VERSION_SORTING_TESTS_ACCEPTANCE_TEST_H__
#include <cstddef>

typedef void(*sort_func_t)(int[], size_t);
bool test_sort(int *array, size_t N, sort_func_t sort_func);
bool acceptance_test(const int *array, size_t N);

#endif /* __RECOVERY_BLOCK_FOR_MULTI_VERSION_SORTING_TESTS_ACCEPTANCE_TEST_H__ */
