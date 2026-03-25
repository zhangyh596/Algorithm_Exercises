#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

//空间复杂度不够好
//int arr[50005];
//
//int cmp(const void* p1, const void* p2)
//{
//	return *(int*)p1 - *(int*)p2;
//}
//
//struct ListNode* sortList(struct ListNode* head) {
//	struct ListNode* pcur = head;
//	
//	//先把节点的值存入数组当中
//	int count = 0;
//	while (pcur != NULL)
//	{
//		arr[count] = pcur->val;
//		count++;
//		pcur = pcur->next;
//	}
//
//	qsort(arr, count, sizeof(int), cmp);
//
//	//把数组里面的元素从小到大放入链表
//	pcur = head;
//	int index = 0;
//	while (pcur != NULL)
//	{
//		pcur->val = arr[index];
//		index++;
//		pcur = pcur->next;
//	}
//	return head;
//}

//优化空间复杂度
//合并两个有序链表思想
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode dummy;
	dummy.next = NULL;
	struct ListNode* ptail = &dummy;

	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			ptail->next = l1;
			ptail = l1;
			l1 = l1->next;
		}
		else
		{
			ptail->next = l2;
			ptail = l2;
			l2 = l2->next;
		}
	}

	if (l1 != NULL)
	{
		ptail->next = l1;
	}
	else
	{
		ptail->next = l2;
	}

	return dummy.next;
}

struct ListNode* sortList(struct ListNode* head) {
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	//找中间节点，利用归并排序
	struct ListNode* slow = head;
	struct ListNode* fast = head->next;//目的是为了让slow->next指向中间节点
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	//归并排序思想
	struct ListNode* mid = slow->next;
	slow->next = NULL;

	struct ListNode* left = sortList(head);
	struct ListNode* right = sortList(mid);

	return merge(left, right);
}