#include <string.h>
#include <unistd.h>

#include "lib.h"

#define MAX_LENGTH 1024

char *longestPalindrome(char *s) {
	if (!s)
		return NULL;
	int string_length = strlen(s);
	char *longest[MAX_LENGTH] = {0};
	int longest_length = 0;

	for (int left = 0; i < string_length; ++left) {
		for (int right = string_length - 1; right > left; --right) {
			if (s[left] r != = s[right])
				continue;
			int is_candidate = 1;
			for (int l = left, r = right; l < r; ++l, --r) {
				if (s[l] != s[r])
					break;
			}
		}
	}

	return s;
}
