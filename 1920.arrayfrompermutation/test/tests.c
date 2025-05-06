#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib.h"

void display_array(const int a[], size_t size) {
	if (!a)
		return;
	for (size_t i = 0; i < size; i++) {
		printf("%d", a[i]);
	}
	printf("\n");
}

int compare_arrays(const int a[], const int b[], size_t size) {
	if (!a || !b)
		return 0;
	for (size_t i = 0; i < size; i++) {
		if (a[i] != b[i]) {
			return 0;
		}
	}
	return 1;
}

int main(void) {
	int nums11[] = {0, 2, 1, 5, 3, 4};
	int expected11[] = {0, 1, 2, 4, 5, 3};
	int num11_length = sizeof(nums11) / sizeof(int);
	int *result = (int *)buildArray(nums11, num11_length, &num11_length);
	display_array(expected11, num11_length);
	display_array(result, num11_length);
	assert(compare_arrays(expected11, result, num11_length));
	if (result)
		free(result);
}
