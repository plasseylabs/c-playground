#include <string.h>
#include <unistd.h>

#include "lib.h"

char *longestPalindrome(char *s) {
	if (!s)
		return NULL;
	int string_length = strlen(s);
	int start = 0, candidate = 0, longest_length = 0;

	for (int left = 0; left < string_length - longest_length; ++left) {
		for (int right = string_length - 1;
		     right - left > longest_length; --right) {
			if (s[left] != s[right])
				continue;
			int current_length = right - left;
			if (current_length <= longest_length) {
				candidate = 0;
				break;
			}
			int l = left + 1, r = right - 1;
			candidate = 1;
			for (; l < r; ++l, --r) {
				if (s[l] != s[r]) {
					candidate = 0;
					break;
				}
			}
			if (!candidate)
				continue;
			start = left;
			longest_length = current_length;
		}
	}

	s[start + longest_length + 1] = '\0';
	return s + start;
}
