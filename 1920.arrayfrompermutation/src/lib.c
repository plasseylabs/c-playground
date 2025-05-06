#include <stdlib.h>
#include <unistd.h>

#include "lib.h"

int *buildArray(int *nums, int numsSize, int *returnSize) {
	if (!nums || !returnSize)
		return NULL;
	int *result = (int *)calloc(numsSize, sizeof(int));
	if (!result)
		return NULL;
	for (int i = 0; i < numsSize; ++i) {
		result[i] = nums[nums[i]];
	}
	*returnSize = numsSize;
	return result;
}
