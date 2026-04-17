#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

//struct ListNode* partition(struct ListNode* head, int x) {
//	struct ListNode dummy;
//	dummy.val = -1;
//	dummy.next = head;
//
//	//找到第一个大于或等于x的节点
//	struct ListNode* prev = &dummy;
//	struct ListNode* pcur = dummy.next;
//	while (pcur != NULL && pcur->val < x)
//	{
//		prev = pcur;
//		pcur = pcur->next;
//	}
//
//	struct ListNode* curr_prev = prev;
//	while (pcur != NULL)
//	{
//		if (pcur->val >= x)
//		{
//			curr_prev = pcur;
//			pcur = pcur->next;
//			continue;
//		}
//		else
//		{
//			struct ListNode* next = pcur->next;
//
//			curr_prev->next = next;
//
//			pcur->next = prev->next;
//			prev->next = pcur;
//			
//			prev = pcur;
//			pcur = next;
//		}
//	}
//	return dummy.next;
//}


struct ListNode* partition(struct ListNode* head, int x) {
	struct ListNode* smallhead, * smalltail;
	struct ListNode* largehead, * largetail;

	smallhead = smalltail = (struct ListNode*)malloc(sizeof(struct ListNode));
	largehead = largetail = (struct ListNode*)malloc(sizeof(struct ListNode));

	struct ListNode* pcur = head;
	while (pcur)
	{
		if (pcur->val < x)
		{
			smalltail->next = pcur;
			smalltail = smalltail->next;
		}
		else
		{
			largetail->next = pcur;
			largetail = largetail->next;
		}
		pcur = pcur->next;
	}

	largetail->next = NULL;
	smalltail->next = largehead->next;

	struct ListNode* ret = smallhead->next;
	free(smallhead);
	smallhead = NULL;
	free(largehead);
	largehead = NULL;

	return ret;
}