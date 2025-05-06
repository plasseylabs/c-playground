#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib.h"

int main(void) {
	int returnSize = 0;
	int nums[] = {-3, 2, 3, 90};

	int *result = twoSum(nums, 4, 0, &returnSize);
	assert(returnSize == 2);
	printf("[%d,%d]\n", result[0], result[1]);
	free(result);

	int nums2[] = {3, 3};
	int *result2 = twoSum(nums2, 2, 6, &returnSize);
	assert(returnSize == 2);
	printf("[%d,%d]\n", result2[0], result2[1]);
	free(result2);

	int nums1[] = {0, 2, 4, 0};
	int *result1 = twoSum(nums1, 4, 0, &returnSize);
	assert(returnSize == 2);
	printf("[%d,%d]\n", result1[0], result1[1]);
	free(result1);

	int nums3[] = {11, 2, 7, 15};
	int *result3 = twoSum(nums3, 4, 9, &returnSize);
	assert(returnSize == 2);
	printf("[%d,%d]\n", result3[0], result3[1]);
	free(result3);

	int nums4[] = {-11, 7, 3, 2, 1, 7, -10, 11, 21, 3};
	int *result4 = twoSum(nums4, 10, 11, &returnSize);
	assert(returnSize == 2);
	printf("[%d,%d]\n", result4[0], result4[1]);
	free(result4);
}
