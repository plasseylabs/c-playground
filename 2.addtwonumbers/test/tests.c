#include <assert.h>

#include "lib.h"

int main(void) {
	ListNode *l1 = init(2);
	append_next(l1, 4);
	append_next(l1, 9);
	append_next(l1, 9);
	append_next(l1, 9);
	append_next(l1, 9);
	append_next(l1, 9);
	list_display(l1);
	ListNode *l2 = init(5);
	append_next(l2, 6);
	append_next(l2, 4);
	append_next(l2, 9);
	append_next(l2, 6);
	append_next(l2, 4);
	append_next(l2, 9);
	append_next(l2, 6);
	append_next(l2, 4);
	append_next(l2, 9);
	list_display(l2);
	ListNode *result = addTwoNumbers(l1, l2);
	list_display(result);
	if (result)
		release(result);
	if (l2)
		release(l2);
}
