#include <unistd.h>

#include "lib.h"

long long countSubarrays(int *nums, int numsSize, long long k) {
	long long result = 0, subarray_sum = 0;

	for (int left = 0, right = 0; right < numsSize; right++) {
		subarray_sum += nums[right];
		while (left <= right &&
		       subarray_sum * (right - left + 1) >= k) {
			subarray_sum -= nums[left];
			left++;
		}
		result += right - left + 1;
	}
	return result;
}
