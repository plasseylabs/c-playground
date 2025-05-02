#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "lib.h"

#define MAX_LENGTH 100001
typedef enum { LEFT, RIGHT, NEUTRAL } Force;

char *pushDominoes(char *dominoes) {
	if (!dominoes)
		return NULL;

	int string_length = strlen(dominoes);
	char output[MAX_LENGTH] = {0};

	Force force = NEUTRAL;
	for (int left = 0, right = 0; dominoes[right]; ++right) {
		if ('L' == dominoes[right]) {
			if (NEUTRAL == force) {
				for (int i = left; i <= right; ++i) {
					output[i] = 'L';
				}
			} else {
				int median = (right + left) / 2;
				for (int i = median + 1; i <= right; ++i) {
					output[i] = 'L';
				}
				if (!((right - left) & 1))
					output[median] = '.';
			}
			force = NEUTRAL;
			left = right;
			continue;
		}
		if ('R' == dominoes[right]) {
			force = RIGHT;
			output[right] = 'R';
			left = right;
			continue;
		}
		if ('.' == dominoes[right]) {
			if (RIGHT == force) {
				output[right] = 'R';
			} else
				output[right] = '.';
		}
	}
	char *result = (char *)malloc((string_length + 1) * sizeof(char *));
	if (!result)
		return NULL;
	memcpy(result, output, string_length + 1);
	return result;
}
