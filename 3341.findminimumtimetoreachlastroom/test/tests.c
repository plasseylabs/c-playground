#include <assert.h>
#include <stdio.h>

#include "lib.h"

int main(void) {
	int result = 0;
	int row0[2] = {0, 4};
	int row1[2] = {4, 4};

	int *rooms[2] = {row0, row1};
	int roomsSize = 2;
	int roomsColSize[2] = {2, 2};
	result = minTimeToReach(rooms, roomsSize, roomsColSize);
	printf("%d\n", result);
	assert(6 == result);
}
