#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "lib.h"

void array_display(int a[], int a_length) {
	for (int i = 0; i < a_length; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

void sort_ints(int *array, size_t length) {
	qsort(array, length, sizeof(int), compare);
}

int maxTaskAssign(int *tasks, int tasksSize, int *workers, int workersSize,
		  int pills, int strength) {
	int max_task_number = 0;

	sort_ints(tasks, tasksSize);
	sort_ints(workers, workersSize);

	array_display(tasks, tasksSize);
	array_display(workers, workersSize);

	for (int i = 0, j = 0; i < tasksSize && j < workersSize; i++) {
		int taken = 0;
		for (int k = j; k < workersSize; k++) {
			/*
					  printf("count: %3d, task: %3d - %5d,
			   worker: "
						 "%5d - %5d, "
						 "\n",
						 max_task_number, i, tasks[i],
			   k, workers[k]); printf("count: %3d, task: %3d - %5d,
			   worker: "
						 "%5d - %5d, "
						 "pills: %3d\n",
						 max_task_number, i, tasks[i],
			   k, workers[k] + strength, pills);
			*/
			if (workers[k] >= tasks[i]) {
				taken++;
				max_task_number++;
				j++;
				break;
			}
			assert(taken || (workers[k] < tasks[i]));
		}
		if (taken == 1) {
			continue;
		}

		for (int k = j; k < workersSize; k++) {
			if (taken == 0 && pills > 0 &&
			    ((workers[k] + strength) >= tasks[i])) {
				taken++;
				pills--;
				max_task_number++;
				j++;
				break;
			}
			assert((workers[k] + strength * (pills > 0) ? 1 : 0) <
			       tasks[i]);
		}
	}

	return max_task_number;
}
