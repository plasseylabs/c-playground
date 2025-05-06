#include <assert.h>
#include <stdio.h>

#include "lib.h"

int main(void) {
	int x = 121;
	int result = isPalindrome(x);
	printf("%d, %d\n", x, result);
	assert(result);

	x = 0;
	result = isPalindrome(x);
	printf("%d, %d\n", x, result);
	assert(result);

	x = 1;
	result = isPalindrome(x);
	printf("%d, %d\n", x, result);
	assert(result);

	x = -1;
	result = isPalindrome(x);
	printf("%d, %d\n", x, result);
	assert(!result);
}
