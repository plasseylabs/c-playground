#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "lib.h"

#define MAX_LENGTH 1024

char *longestPalindrome(char *s) {
	if (!s)
		return NULL;
	int string_length = strlen(s);
	char longest[MAX_LENGTH] = {0};
	longest[0] = s[0];
	int longest_length = 0;

	for (int left = 0; left < string_length - longest_length; ++left) {
		for (int right = string_length - 1;
		     right - left > longest_length; --right) {
			if (s[left] != s[right])
				continue;
			int l = left + 1, r = right - 1, candidate = 1;
			for (; l < r; ++l, --r) {
				if (s[l] != s[r]) {
					candidate = 0;
					break;
				}
			}
			if (!candidate || r - l > 1)
				continue;
			int current_length = right - left;
			if (current_length > longest_length) {
				for (int k = 0, i = left; i <= right;
				     ++k, ++i) {
					longest[k] = s[i];
				}
				longest_length = current_length;
			}
		}
	}
	char *result = (char *)calloc(longest_length + 1, sizeof(char *));
	memcpy(result, longest, longest_length + 1);

	return result;
}
