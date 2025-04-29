#ifndef PLASSEYLAB_PLAYGROUND_TWO_ADD_LINKED_LIST_H
#define PLASSEYLAB_PLAYGROUND_TWO_ADD_LINKED_LIST_H

typedef struct ListNode {
	int val;
	struct ListNode *next;
} ListNode;

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2);
ListNode *init(int value);
void append_next(ListNode *l, int value);
void release(ListNode *l);
void list_display(ListNode *l);

#endif // !PLASSEYLAB_PLAYGROUND_TWO_ADD_LINKED_LIST_H
