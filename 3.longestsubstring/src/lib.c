#include <unistd.h>

#include "lib.h"

#define MAX_LENGTH 128

int lengthOfLongestSubstring(char *s) {
	int char_max_index[MAX_LENGTH] = {0};
	for (int i = 0; i < MAX_LENGTH; i++) {
		char_max_index[i] = -1;
	}

	int max_length = 0;

	for (int left = 0, right = 0; s[right] != '\0'; right++) {
		if (char_max_index[(int)s[right]] >= left) {
			left = char_max_index[(int)s[right]] + 1;
		}
		char_max_index[(int)s[right]] = right;
		int current_length = right - left + 1;
		max_length =
		    (max_length > current_length) ? max_length : current_length;
	}

	return max_length;
}
