#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//	struct ListNode* pcurA = headA;
//	while (pcurA)
//	{
//		struct ListNode* pcurB = headB;
//		while (pcurB)
//		{
//			if (pcurB == pcurA)
//			{
//				return pcurA;
//			}
//			pcurB = pcurB->next;
//		}
//		pcurA = pcurA->next;
//	}
//	return NULL;
//}

//优化解法
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
	struct ListNode* pcurA = headA;
	struct ListNode* pcurB = headB;
	int lenA = 0, lenB = 0;

	while (pcurA)
	{
		lenA++;
		pcurA = pcurA->next;
	}
	while (pcurB)
	{
		lenB++;
		pcurB = pcurB->next;
	}

	pcurA = headA;
	pcurB = headB;
	if (lenA > lenB)
	{
		for (int i = 0; i < lenA - lenB; i++)
		{
			pcurA = pcurA->next;
		}
	}
	else
	{
		for (int i = 0; i < lenB - lenA; i++)
		{
			pcurB = pcurB->next;
		}
	}

	while (pcurA && pcurB)
	{
		if (pcurA == pcurB)
		{
			return pcurA;
		}
		pcurA = pcurA->next;
		pcurB = pcurB->next;
	}
	return NULL;
}