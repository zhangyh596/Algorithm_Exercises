#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode dummy;
	dummy.next = NULL;
	struct ListNode* tail = &dummy;

	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}

	if (l1)
	{
		tail->next = l1;
	}
	else
	{
		tail->next = l2;
	}
	return dummy.next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
	if (listsSize == 0)
		return NULL;

	struct ListNode* mergedList = lists[0];

	for (int i = 1; i < listsSize; i++)
	{
		mergedList = mergeTwoLists(mergedList, lists[i]);
	}
	return mergedList;
}