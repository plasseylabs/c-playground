#include <unistd.h>

#include "lib.h"

int isPalindrome(int x) {
	if (!x)
		return 1;
	if (x < 0 || x % 10 == 0)
		return 0;
	if (x < 10)
		return 1;

	int result = 0;
	while (x > result) {
		int rem = x % 10;
		result = result * 10 + rem;
		if (result == x)
			return 1;
		x /= 10;
		if (!result ^ x)
			return 1;
	}
	return 0;
}
