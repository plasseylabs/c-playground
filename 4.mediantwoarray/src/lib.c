#include <limits.h>
#include <unistd.h>

#include "lib.h"

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2,
			      int nums2Size) {
	double median = 0.0;
	int merged_length = nums1Size + nums2Size;
	int merged_array[1001] = {0};

	for (int i = 0, j = 0; i + j < merged_length / 2 + 1;) {
		if (j == nums2Size || (i < nums1Size && nums1[i] < nums2[j])) {
			merged_array[i + j] = nums1[i];
			i++;
		} else {
			merged_array[i + j] = nums2[j];
			j++;
		}
	}

	int middle = merged_length / 2;
	if ((merged_length & 1) == 0) {
		median = ((double)merged_array[middle] +
			  (double)merged_array[middle - 1]) /
			 2.0;
	} else {

		median = (double)merged_array[middle];
	}

	return median;
}
