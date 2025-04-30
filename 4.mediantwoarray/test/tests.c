#include <assert.h>
#include <stdio.h>

#include "lib.h"

int main(void) {
	double result = 0;

	int nums11[] = {1, 3};
	int nums12[] = {2};
	int num11_length = sizeof(nums11) / sizeof(int);
	int num12_length = sizeof(nums12) / sizeof(int);
	result =
	    findMedianSortedArrays(nums11, num11_length, nums12, num12_length);
	printf("%f\n", result);
	assert(2.0 == result);

	int nums21[] = {1, 3};
	int nums22[] = {2, 4};
	int num21_length = sizeof(nums21) / sizeof(int);
	int num22_length = sizeof(nums22) / sizeof(int);
	result =
	    findMedianSortedArrays(nums21, num21_length, nums22, num22_length);
	printf("%f\n", result);
	assert(2.5 == result);
}
