#include <assert.h>
#include <stdio.h>

#include "lib.h"

int main(void) {
	int result = 0;

	char *line1 = "abcabcbb";
	result = lengthOfLongestSubstring(line1);
	printf("%s longest substing length: %d\n", line1, result);
	assert(3 == result);

	char *line2 = "bbbbb";
	result = lengthOfLongestSubstring(line2);
	printf("%s longest substing length: %d\n", line2, result);
	assert(1 == result);

	char *line3 = "pwwkew";
	result = lengthOfLongestSubstring(line3);
	printf("%s longest substing length: %d\n", line3, result);
	assert(3 == result);

	char *line4 = "au";
	result = lengthOfLongestSubstring(line4);
	printf("%s longest substing length: %d\n", line4, result);
	assert(2 == result);

	char *line5 = "aab";
	result = lengthOfLongestSubstring(line5);
	printf("%s longest substing length: %d\n", line5, result);
	assert(2 == result);
}
