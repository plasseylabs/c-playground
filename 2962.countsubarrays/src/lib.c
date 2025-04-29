#include <limits.h>
#include <unistd.h>

#include "lib.h"

long long countSubarrays(int *nums, int numsSize, int k) {
	int max_element = INT_MIN;
	int max_element_positions[1024 * 1024] = {0};
	for (int i = 0; i < numsSize; i++) {
		if (max_element < nums[i])
			max_element = nums[i];
		max_element_positions[i] = -1;
	}
	int max_element_count = 0;
	long long array_count = 0;

	for (int right = 0, rpos = 0; right < numsSize; right++) {
		if (nums[right] == max_element) {
			max_element_positions[rpos++] = right;
		}
	}

	if (max_element_count > k)
		array_count++;

	return array_count;
}
