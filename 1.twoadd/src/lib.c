#include <stdlib.h>
#include <unistd.h>

#include "lib.h"

int key_calculate(int value) { return (value + TABLESIZE) & TABLESIZE_MASK; }

void insert(Node *hash_table, int value, int index) {
	int key = key_calculate(value);
	(hash_table + key)->index = index;
	(hash_table + key)->on = 1;
}

int search(Node *hash_table, int value) {
	int key = key_calculate(value);
	if ((hash_table + key)->on) {
		return (hash_table + key)->index;
	}
	return -1;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {

	Node hash_table[TABLESIZE] = {0};

	insert(hash_table, nums[0], 0);
	for (int i = 1; i < numsSize; i++) {
		int complement = target - nums[i];
		int index = search(hash_table, complement);
		if (index != -1) {
			int *result = (int *)malloc(2 * sizeof(int));
			result[0] = index;
			result[1] = i;
			*returnSize = 2;
			return result;
		}
		insert(hash_table, nums[i], i);
	}
	*returnSize = 0;
	return NULL;
}
