#include <limits.h>
#include <unistd.h>

#include "lib.h"

long long countSubarrays(int *nums, int numsSize, int k) {
	int max_element_positions[1000000];
	long long array_count = 0;

	for (int i = 0, p = 0, max_element = 0; i < numsSize; i++) {
		if (max_element < nums[i]) {
			max_element = nums[i];
			p = 0;
			array_count = 0;
		}

		if (max_element == nums[i]) {
			max_element_positions[p++] = i;
		}

		if (p >= k) {
			array_count += max_element_positions[p - k] + 1;
		}
	}

	return array_count;
}
