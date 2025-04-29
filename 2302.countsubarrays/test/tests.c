#include <assert.h>
#include <stdio.h>

#include "lib.h"

int main(void) {
	long long result = 0, k = 0;

	int nums1[] = {2, 1, 4, 3, 5};
	k = 10;
	result = countSubarrays(nums1, 5, k);
	assert(6 == result);
	printf("%lld\n", result);

	int nums2[] = {1, 1, 1};
	k = 5;
	result = countSubarrays(nums2, 3, k);
	assert(5 == result);
	printf("%lld\n", result);
}
