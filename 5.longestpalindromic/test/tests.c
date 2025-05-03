#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

int main(void) {
	char *result = NULL;

	char line1[] = "babad";
	result = longestPalindrome(line1);
	printf("%s longest substing: %s\n", line1, result);
	assert(!strcmp(result, "bab"));

	char line2[] = "cbbd";
	result = longestPalindrome(line2);
	printf("%s longest substing: %s\n", line2, result);
	assert(!strcmp(result, "bb"));

	char line3[] = "pwwkew";
	result = longestPalindrome(line3);
	printf("%s longest substing: %s\n", line3, result);
	assert(!strcmp(result, "ww"));

	char line4[] = "au";
	result = longestPalindrome(line4);
	printf("%s longest substing: %s\n", line4, result);
	assert(!strcmp(result, "a"));

	char line5[] = "aab";
	result = longestPalindrome(line5);
	printf("%s longest substing: %s\n", line5, result);
	assert(!strcmp(result, "aa"));

	char line6[] = "aaaaa";
	result = longestPalindrome(line6);
	printf("%s longest substing: %s\n", line6, result);
	assert(!strcmp(result, "aaaaa"));

	char line7[] = "aaaabaaa";
	result = longestPalindrome(line7);
	printf("%s longest substing: %s\n", line7, result);
	assert(!strcmp(result, "aaabaaa"));
}
