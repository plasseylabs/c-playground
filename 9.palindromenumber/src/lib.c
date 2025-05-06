#include <unistd.h>

#include "lib.h"

int isPalindrome(int x) {
	if (x == 0)
		return 1;
	if (x < 0 || x % 10 == 0)
		return 0;
	if (x < 10)
		return 1;

	int reversed = 0;
	while (x > reversed) {
		reversed = reversed * 10 + x % 10;
		x /= 10;
	}

	return x == reversed || x == reversed / 10;
}
