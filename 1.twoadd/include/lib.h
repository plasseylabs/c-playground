#ifndef PLASSEYLAB_PLAYGROUND_TWO_ADD_H
#define PLASSEYLAB_PLAYGROUND_TWO_ADD_H

#define TABLESIZE (1 << 16)
#define TABLESIZE_MASK (TABLESIZE - 1)

typedef struct Node {
	int index;
	int on;
} Node;

int *twoSum(int *nums, int numsSize, int target, int *returnSize);

#endif // !PLASSEYLAB_PLAYGROUND_TWO_ADD_H
