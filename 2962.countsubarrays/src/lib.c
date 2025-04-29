#include <limits.h>
#include <unistd.h>

#include "lib.h"

long long countSubarrays(int *nums, int numsSize, int k) {
	int max_element = INT_MIN;
	for (int i = 0; i < numsSize; i++) {
		if (max_element < nums[i])
			max_element = nums[i];
	}
	int max_element_count = 0;
	long long array_count = 0;

	for (int left = 0, right = 0; right < numsSize; right++) {
		if (nums[right] == max_element)
			++max_element_count;
		if (max_element_count < k)
			continue;
		while (left <= right && max_element_count >= k) {
			array_count += numsSize - right;
			if (nums[left++] == max_element)
				max_element_count--;
		}
	}

	return array_count;
}
