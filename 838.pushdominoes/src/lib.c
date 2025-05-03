#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "lib.h"

#define MAX_LENGTH 100001
typedef enum { LEFT, RIGHT, NEUTRAL } Force;

char *pushDominoes(char *dominoes) {
	if (!dominoes)
		return NULL;

	char output[MAX_LENGTH] = {0};

	Force force = NEUTRAL;
	int left = 0, right = 0;
	for (; dominoes[right]; ++right) {
		switch (dominoes[right]) {
		case 'L':
			if (NEUTRAL == force) {
				for (int i = left; i <= right; ++i) {
					output[i] = 'L';
				}
			} else {
				int median = (right + left) / 2;
				if (!((right - left) & 1))
					output[median] = '.';
				for (int i = ++median; i <= right; ++i) {
					output[i] = 'L';
				}
			}
			force = NEUTRAL;
			left = right;
			break;
		case 'R':
			force = RIGHT;
			output[right] = 'R';
			left = right;
			break;
		case '.':
			if (RIGHT == force) {
				output[right] = 'R';
			} else
				output[right] = '.';
		}
	}
	char *result = (char *)malloc((++right) * sizeof(char *));
	if (!result)
		return NULL;
	memcpy(result, output, right);
	return result;
}
