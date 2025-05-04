#include <assert.h>
#include <stdio.h>

#include "lib.h"

int main(void) {
	int result = 0;
	int row0[2] = {1, 2};
	int row1[2] = {2, 1};
	int row2[2] = {3, 4};
	int row3[2] = {1, 2};
	int row4[2] = {1, 2};

	int *dominoes[5] = {row0, row1, row2, row3, row4};
	int dominoesSize = 5;
	int dominoesColSize[5] = {2, 2, 2, 2, 2};
	result = numEquivDominoPairs(dominoes, dominoesSize, dominoesColSize);
	printf("%d\n", result);
	assert(6 == result);
}
