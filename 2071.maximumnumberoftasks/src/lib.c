#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "lib.h"

void array_display(int a[], int a_length) {
	for (int i = 0; i < a_length; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

uint check(int *tasks, int *workers, const int workersSize, int pills,
	   const int strength, const int median) {
	int ws[workersSize];
	int ptr = workersSize - 1;
	uint head = ptr, tail = ptr;
	for (int i = median - 1; i >= 0; --i) {
		while (ptr >= workersSize - median &&
		       workers[ptr] + strength >= tasks[i]) {
			ws[head] = workers[ptr];
			--head;
			--ptr;
		}
		if (head == tail) {
			return 0;
		}
		if (ws[tail] >= tasks[i]) {
			--tail;
		} else {
			if (!pills) {
				return 0;
			}
			--pills;
			++head;
		}
	}

	return 1;
}

int maxTaskAssign(int *tasks, int tasksSize, int *workers, int workersSize,
		  int pills, int strength) {
	qsort(tasks, tasksSize, sizeof(int), compare);
	qsort(workers, workersSize, sizeof(int), compare);

	uint left = 1,
	     right = (tasksSize < workersSize) ? tasksSize : workersSize,
	     max_number = 0;
	while (left <= right) {
		uint median = (left + right) / 2;
		if (check(tasks, workers, workersSize, pills, strength,
			  median)) {
			max_number = median;
			left = median + 1;
		} else {
			right = median - 1;
		}
	}
	return max_number;
}
