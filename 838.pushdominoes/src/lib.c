#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "lib.h"

typedef enum { LEFT, RIGHT, NEUTRAL } Force;

char *pushDominoes(char *dominoes) {
	if (!dominoes)
		return NULL;

	int string_length = strlen(dominoes);
	char *output = (char *)malloc((string_length + 1) * sizeof(char *));
	if (!output)
		return NULL;
	for (int i = 0; i <= string_length + 1; i++) {
		output[i] = '\0';
	}

	Force force = NEUTRAL;
	for (int left = 0, right = 0; right < string_length; right++) {
		if ('L' == dominoes[right]) {
			if (NEUTRAL == force) {
				for (int i = left; i <= right; i++) {
					output[i] = 'L';
				}
			} else {
				int median = (right + left) / 2;
				for (int i = median + 1; i <= right; i++) {
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
		}
		if ('.' == dominoes[right]) {
			if (RIGHT == force) {
				output[right] = 'R';
			} else
				output[right] = '.';
		}
	}
	return output;
}
