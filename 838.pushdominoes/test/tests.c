#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

int main(void) {
	char input1[] = "RR.L";
	char *output1 = pushDominoes(input1);
	printf("%s\n%s\n", input1, output1);
	assert(0 == strcmp(output1, "RR.L"));
	if (output1)
		free(output1);

	char input2[] = ".L.R...LR..L..";
	char *output2 = pushDominoes(input2);
	printf("%s\n%s\n", input2, output2);
	assert(0 == strcmp(output2, "LL.RR.LLRRLL.."));
	if (output2)
		free(output2);

	char input3[] = "L.....RR.RL.....L.R.";
	char *output3 = pushDominoes(input3);
	printf("%s\n%s\n", input3, output3);
	assert(0 == strcmp(output3, "L.....RRRRLLLLLLL.RR"));
	if (output3)
		free(output3);
}
