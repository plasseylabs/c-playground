#include <stdio.h>
#include <stdlib.h>

#include "lib.h"

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	ListNode *n1 = l1;
	ListNode *n2 = l2;
	int over = 0;
	while (n1) {
		int sum = over + n1->val;
		if (n2) {
			sum += n2->val;
		}
		if (sum < 10) {
			n1->val = sum;
			over = 0;
		} else {
			n1->val = sum - 10;
			over = 1;
		}
		if (n1->next) {
			n1 = n1->next;
			if (n2)
				n2 = n2->next;
		} else {
			if (n2) {
				n1->next = n2->next;
				n2->next = NULL;
			}
			n1 = n1->next;
			n2 = NULL;
		}
	}
	if (over)
		append_next(l1, 1);
	return l1;
}

void append_next(ListNode *l, int value) {
	if (!l)
		return;
	ListNode *n = l;
	while (n->next) {
		n = n->next;
	}

	ListNode *next = (ListNode *)malloc(sizeof(ListNode));
	if (!next)
		return;
	next->val = value;
	next->next = NULL;
	n->next = next;
}

ListNode *init(int value) {
	ListNode *next = (ListNode *)malloc(sizeof(ListNode));
	if (!next)
		return NULL;
	next->val = value;
	next->next = NULL;

	return next;
}

void release(ListNode *l) {
	if (!l)
		return;
	struct ListNode *current = l;
	struct ListNode *next = NULL;

	while (current) {
		next = current->next;
		current->next = NULL;
		free(current);
		current = next;
	}
}

void list_display(ListNode *l) {
	if (!l)
		return;
	ListNode *n = l;
	while (n) {
		printf("%d", n->val);
		n = n->next;
	}
	printf("\n");
}
