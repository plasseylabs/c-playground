#include <unistd.h>

#include "lib.h"

int numEquivDominoPairs(int **dominoes, int dominoesSize,
			int *dominoesColSize) {
	if (!*dominoesColSize) // just to use argiment - not needed
		return 0;
	int max_pairs = 0, num[100] = {0};
	for (int i = 0; i < dominoesSize; i++) {
		int index = dominoes[i][0] < dominoes[i][1]
				? dominoes[i][0] * 10 + dominoes[i][1]
				: dominoes[i][1] * 10 + dominoes[i][0];
		max_pairs += num[index]++;
	}
	return max_pairs;
}
