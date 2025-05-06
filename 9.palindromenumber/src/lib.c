#include <unistd.h>

#include "lib.h"

int isPalindrome(int x) {
	if (!x)
		return 1;
	if (x < 0 || x % 10 == 0)
		return 0;
	long result = 0, temp = x;
	while (x) {
		int rem = x % 10;
		result = result * 10 + rem;
		x /= 10;
		if (result == x || result == temp) {
			return 1;
		}
	}
	return 0;
}
