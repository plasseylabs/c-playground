#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

#include "lib.h"

int main(void) {
	int num = 0, result = 0;

	num = 123;
	result = reverse(num);
	assert(321 == result);
	printf("[%d,%d]\n", num, result);

	num = -123;
	result = reverse(num);
	assert(-321 == result);
	printf("[%d,%d]\n", num, result);

	num = -1234;
	result = reverse(num);
	printf("[%d,%d]\n", num, result);
	assert(-4321 == result);

	num = -1534236469;
	result = reverse(num);
	printf("[%d,%d]\n", num, result);
	assert(0 == result);

	num = 1534236469;
	result = reverse(num);
	printf("[%d,%d]\n", num, result);
	assert(0 == result);

	num = 1;
	for (int i = 0; i < 30; ++i) {
		num <<= 1;
		++num;
	}
	result = reverse(num);
	printf("[%d,%d]\n", num, result);
	assert(0 == result);

	for (int i = 0; i < 5; ++i) {
		--num;
		result = reverse(num);
		printf("[%d,%d]\n", num, result);
		assert(0 == result);
	}

	num = INT_MAX;
	result = reverse(num);
	printf("[%d,%d]\n", num, result);
	assert(0 == result);

	num = INT_MIN;
	result = reverse(num);
	printf("[%d,%d]\n", num, result);
	assert(0 == result);

	printf("%d - %d\n", INT_MIN, INT_MAX);
}
