#include <assert.h>
#include <stdio.h>

#include "lib.h"

int main(void) {
	int result = 0, expected = 0;

	int tops1[] = {2, 1, 2, 4, 2, 2};
	int bottoms1[] = {5, 2, 6, 2, 3, 2};
	int tops1_size = sizeof(tops1) / sizeof(int);
	int bottoms1_size = sizeof(bottoms1) / sizeof(int);
	result = minDominoRotations(tops1, tops1_size, bottoms1, bottoms1_size);
	expected = 2;
	printf("result: %d expected: %d\n", result, expected);
	assert(expected == result);

	int tops2[] = {3, 5, 1, 2, 3};
	int bottoms2[] = {3, 6, 3, 3, 4};
	int tops2_size = sizeof(tops2) / sizeof(int);
	int bottoms2_size = sizeof(bottoms2) / sizeof(int);
	result = minDominoRotations(tops2, tops2_size, bottoms2, bottoms2_size);
	expected = -1;
	printf("result: %d expected: %d\n", result, expected);
	assert(expected == result);
}
