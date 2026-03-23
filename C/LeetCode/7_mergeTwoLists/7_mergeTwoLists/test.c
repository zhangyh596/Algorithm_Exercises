#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	//创建哨兵节点
	struct ListNode* newhead;
	struct ListNode* newtail;
	newhead = newtail = (struct ListNode*)malloc(sizeof(struct ListNode));

	struct ListNode* l1 = list1;
	struct ListNode* l2 = list2;
	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			newtail->next = l1;
			newtail = l1;
			l1 = l1->next;
		}
		else
		{
			newtail->next = l2;
			newtail = l2;
			l2 = l2->next;
		}
	}

	if (l1 != NULL)
	{
		newtail->next = l1;
	}
	else
	{
		newtail->next = l2;
	}

	struct ListNode* ret = newhead->next;
	free(newhead);
	newhead = NULL;
	return ret;
}

//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//	if (list1 == NULL)
//	{
//		return list2;
//	}
//	if (list2 == NULL)
//	{
//		return list1;
//	}
//	struct ListNode* l1 = list1;
//	struct ListNode* l2 = list2;
//
//	struct ListNode* newhead, * newtail;
//	newhead = newtail = (struct ListNode*)malloc(sizeof(struct ListNode));
//
//	while (l1 && l2)
//	{
//		if (l1->val < l2->val)
//		{
//			newtail->next = l1;
//			newtail = newtail->next;
//			l1 = l1->next;
//		}
//		else
//		{
//			newtail->next = l2;
//			newtail = newtail->next;
//			l2 = l2->next;
//		}
//	}
//	if (l1)
//	{
//		newtail->next = l1;
//	}
//	if (l2)
//	{
//		newtail->next = l2;
//	}
//
//	struct ListNode* ret = newhead->next;
//	free(newhead);
//	newhead = NULL;
//	return ret;
//}