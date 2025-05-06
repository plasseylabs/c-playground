#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

int main(void) {
	int input = 0;
	char *result = NULL;

	input = 3749;
	result = intToRoman(input);
	char *expected = "MMMDCCXLIX";
	printf("%4d\n%s\n%s\n", input, result, expected);
	assert(!strcmp(result, expected));
	if (result)
		free(result);
}
