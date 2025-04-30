#include <limits.h>
#include <unistd.h>

#include "lib.h"

int findNumbers(int *nums, int numsSize) {
	int numbers_count = 0;

	for (int i = 0; i < numsSize; i++) {
		if (nums[i] < 0)
			nums[i] = -nums[i];

		if (nums[i] < 10)
			continue;

		int digits_count = 1;
		while (nums[i] /= 10) {
			digits_count++;
		}

		if (0 == (digits_count & 1)) {
			numbers_count++;
		}
	}

	return numbers_count;
}
