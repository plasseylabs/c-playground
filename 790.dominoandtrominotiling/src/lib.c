#include <unistd.h>

#include "lib.h"

#define POOL_SIZE 4
#define MOD 1000000007

int numTilings(int n) {
	if (n < 1)
		return 0;
	long variants[POOL_SIZE] = {1, 2, 5, 0};
	for (int i = 3; i < n; ++i) {
		variants[i & 3] =
		    (variants[(i + 3) & 3] * 2 + variants[(i + 1) & 3]) % MOD;
	}
	return variants[(n - 1) & 3];
}
