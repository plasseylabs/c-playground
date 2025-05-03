#include <unistd.h>

#include "lib.h"

int minDominoRotations(int *tops, int topsSize, int *bottoms, int bottomsSize) {
	if (!tops || !bottoms || topsSize != bottomsSize)
		return -1;
	int result = -1;

	int t[7] = {0};
	int b[7] = {0};
	int d[7] = {0};
	for (int i = 0; i < topsSize; ++i) {
		++t[tops[i]];
		++b[bottoms[i]];
		if (tops[i] == bottoms[i])
			++d[tops[i]];
	}
	for (int i = 1; i < 7; ++i) {
		if (t[i] + b[i] - d[i] >= topsSize) {
			int longest = (t[i] > b[i]) ? t[i] : b[i];
			int diff = topsSize - longest;
			if (result != -1)
				result = (diff < result) ? diff : result;
			else
				result = diff;
		}
	}

	return result;
}
