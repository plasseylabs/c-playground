#include <unistd.h>

#include "lib.h"

#define MAX_SIZE 1001
#define MOD 1000000007

int numTilings(int n) {
	if (n < 1 || n >= MAX_SIZE)
		return 0;
	long variants[MAX_SIZE] = {1, 2, 5, 0};
	for (int i = 3; i < n; ++i) {
		variants[i] = (variants[i - 1] * 2 + variants[i - 3]) % MOD;
	}
	return variants[n - 1];
}
