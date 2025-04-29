#include <limits.h>
#include <stdio.h>
#include <unistd.h>

#include "lib.h"

void print_max_element_positions(int max_element_positions[]) {
	for (int i = 0; max_element_positions[i] != -1; i++) {
		printf("%d ", max_element_positions[i]);
	}
	printf("\n");
}

long long countSubarrays(int *nums, int numsSize, int k) {
	int max_element = INT_MIN;
	int max_element_positions[1024 * 1024] = {0};
	int last_index = 0;
	for (int i = 0, p = 0; i < numsSize; i++) {
		if (max_element < nums[i]) {
			max_element = nums[i];
			p = 0;
		}
		if (max_element == nums[i]) {
			max_element_positions[p++] = i;
			last_index = p;
		}
		if (i == numsSize - 1) {
			for (; p < numsSize; p++) {
				max_element_positions[p] = -1;
			}
		}
	}

	print_max_element_positions(max_element_positions);

	long long array_count = 0;

	for (int i = 0, j = k - 1; j < last_index; i++, j++) {
		array_count += (max_element_positions[i]) *
			       (numsSize - max_element_positions[j]);
	}

	return array_count;
}
