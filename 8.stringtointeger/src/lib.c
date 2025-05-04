#include <limits.h>
#include <string.h>
#include <unistd.h>

#include "lib.h"

int myAtoi(char *s) {
	int string_length = strlen(s), result = 0, sign = 1, started = 0;

	for (int i = 0; i < string_length; ++i) {
		if (s[i] == ' ') {
			if (!started)
				continue;
			else
				break;
		}
		if (s[i] == '-') {
			if (!started) {
				sign = -1;
				++started;
				continue;
			} else {
				break;
			}
		}
		if (s[i] == '+') {
			if (!started) {
				++started;
				continue;
			} else {
				break;
			}
		}
		int char_i = (unsigned char)s[i];
		if (char_i > 57 || char_i < 48) {
			break;
		}
		char_i -= 48;
		++started;
		if (sign == -1 && ((result * sign) == INT_MIN / 10) &&
		    char_i > 7)
			return INT_MIN;
		if (sign == -1 && result > INT_MAX / 10)
			return INT_MIN;
		if (result == INT_MAX / 10 && char_i > 7)
			return INT_MAX;
		if (result > INT_MAX / 10)
			return INT_MAX;

		result = result * 10 + char_i;
	}
	if (result > 0)
		result *= sign;
	return result;
}
