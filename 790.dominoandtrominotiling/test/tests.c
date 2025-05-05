#include <assert.h>
#include <stdio.h>

#include "lib.h"

int main(void) {
	int n = 1, result = 0;

	result = numTilings(n);
	printf("n: %4d, variants: %9d\n", n, result);
	assert(result == 1);

	n = 10;
	result = numTilings(n);
	printf("n: %4d, variants: %9d\n", n, result);
	assert(result == 1255);

	n = 30;
	result = numTilings(n);
	printf("n: %4d, variants: %9d\n", n, result);
	assert(result == 312342182);

	n = 60;
	result = numTilings(n);
	printf("n: %4d, variants: %9d\n", n, result);
	assert(result == 882347204);

	n = 1000;
	result = numTilings(n);
	printf("n: %4d, variants: %9d\n", n, result);
	assert(result == 979232805);

	n = 1001;
	result = numTilings(n);
	printf("n: %4d, variants: %9d\n", n, result);
	assert(result == 0);
}
