#include <assert.h>
#include <stdio.h>

#include "lib.h"

int main(void) {
	long long result = 0, k = 0;

	int nums1[] = {1, 3, 2, 3, 3};
	k = 2;
	int num1_length = sizeof(nums1) / sizeof(int);
	result = countSubarrays(nums1, num1_length, k);
	printf("%lld\n", result);
	assert(6 == result);

	int nums2[] = {1, 4, 2, 1};
	k = 3;
	int num2_length = sizeof(nums2) / sizeof(int);
	result = countSubarrays(nums2, num2_length, k);
	printf("%lld\n", result);
	assert(0 == result);

	int nums3[] = {61, 23, 38, 23, 56, 40, 82, 56, 82, 82, 82, 70, 8,
		       69, 8,  7,  19, 14, 58, 42, 82, 10, 82, 78, 15, 82};
	k = 2;
	int num3_length = sizeof(nums3) / sizeof(int);
	result = countSubarrays(nums3, num3_length, k);
	printf("%lld\n", result);
	assert(224 == result);
}
