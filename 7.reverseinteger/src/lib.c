#include <limits.h>
#include <unistd.h>

#include "lib.h"

int reverse(int x) {
	int result = 0;
	while (x) {
		int rem = x % 10;
		x /= 10;
		if (result > INT_MAX / 10)
			return 0;
		if (result < INT_MIN / 10)
			return 0;
		result = result * 10 + rem;
	}
	return result;
}
