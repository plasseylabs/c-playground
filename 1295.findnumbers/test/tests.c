#include <assert.h>
#include <stdio.h>

#include "lib.h"

int main(void) {
	long long result = 0;

	int nums1[] = {12, 345, 2, 6, 7896};
	int num1_length = sizeof(nums1) / sizeof(int);
	result = findNumbers(nums1, num1_length);
	printf("%lld\n", result);
	assert(2 == result);

	int nums2[] = {12, 345, 2, 6, 7896};
	int num2_length = sizeof(nums2) / sizeof(int);
	result = findNumbers(nums2, num2_length);
	printf("%lld\n", result);
	assert(2 == result);

	int nums3[] = {61, 23, 38, 23, 56, 40, 82, 56, 82, 82, 82, 70, 8,
		       69, 8,  7,  19, 14, 58, 42, 82, 10, 82, 78, 15, 82};
	int num3_length = sizeof(nums3) / sizeof(int);
	result = findNumbers(nums3, num3_length);
	printf("%lld\n", result);
	assert(23 == result);
}
