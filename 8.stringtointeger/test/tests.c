#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

#include "lib.h"

int main(void) {
	char *num = {0};
	int result = 0;

	int int_max = 1;
	for (int i = 0; i < 30; ++i) {
		int_max <<= 1;
		++int_max;
	}
	int int_min = -int_max - 1;
	num = "321";
	result = myAtoi(num);
	printf("[%s,%d]\n", num, result);
	assert(321 == result);

	num = "-123";
	result = myAtoi(num);
	printf("[%s,%d]\n", num, result);
	assert(-123 == result);

	num = "-1234";
	result = myAtoi(num);
	assert(-1234 == result);
	printf("[%s,%d]\n", num, result);

	num = "-1534236469";
	result = myAtoi(num);
	printf("[%s,%d]\n", num, result);
	assert(-1534236469 == result);

	num = "1463847412";
	result = myAtoi(num);
	printf("[%s,%d]\n", num, result);
	assert(1463847412 == result);

	num = "2147483641";
	result = myAtoi(num);
	printf("[%s,%d]\n", num, result);
	assert(2147483641 == result);

	num = "-2147483641";
	result = myAtoi(num);
	printf("[%s,%d]\n", num, result);
	assert(-2147483641 == result);

	num = "0-1";
	result = myAtoi(num);
	printf("[%s,%d]\n", num, result);
	assert(0 == result);

	num = "words and 987";
	result = myAtoi(num);
	printf("[%s,%d]\n", num, result);
	assert(0 == result);

	num = "-91283472332";
	result = myAtoi(num);
	printf("[%s,%d]\n", num, result);
	assert(-2147483648 == result);

	num = "-2147483648";
	result = myAtoi(num);
	printf("[%s,%d]\n", num, result);
	assert(-2147483648 == result);

	num = "-2147483647";
	result = myAtoi(num);
	printf("[%s,%d]\n", num, result);
	assert(-2147483647 == result);

	printf("%d - %d\n", INT_MIN, INT_MAX);
	printf("%d - %d\n", int_min, int_max);
}
