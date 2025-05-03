#include <string.h>
#include <unistd.h>

#include "lib.h"

int check_palindrome(const char *s, int l, int r) {
	for (; l < r;) {
		if (s[l++] != s[r--]) {
			return 0;
		}
	}
	return 1;
}

char *longestPalindrome(char *s) {
	if (!s)
		return NULL;
	int string_length = strlen(s);
	int start = 0, longest_length = 0;

	for (int left = 0; left < string_length - longest_length; ++left) {
		for (int right = string_length - 1;
		     right - left > longest_length; --right) {
			if (!check_palindrome(s, left, right))
				continue;
			start = left;
			longest_length = right - left;
		}
	}

	s[start + longest_length + 1] = '\0';
	return s + start;
}
