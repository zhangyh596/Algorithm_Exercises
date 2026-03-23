#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

//一个一个遍历会超时
//bool isPalindrome(struct ListNode* head) {
//	struct ListNode* phead = head;
//	struct ListNode* ptail = head;
//
//	int count = 0;
//	while (ptail)
//	{
//		count++;
//		ptail = ptail->next;
//	}
//
//	for (int i = 0; i < count / 2; i++)
//	{
//		struct ListNode* prev = head;
//		while (prev->next != ptail)
//		{
//			prev = prev->next;
//		}
//		if (phead->val != prev->val)
//		{
//			return false;
//		}
//		phead = phead->next;
//		ptail = prev;
//	}
//	return true;
//}

//优化算法
bool isPalindrome(struct ListNode* head) {
	//快慢指针找尾节点和中间节点
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	//反转后半部分链表
	struct ListNode* prev = NULL;
	struct ListNode* pcur = slow;
	while (pcur)
	{
		struct ListNode* next = pcur->next;
		pcur->next = prev;
		prev = pcur;
		pcur = next;
	}
	//比较前边部分链表和后半部分链表
	while (prev)
	{
		if (prev->val != head->val)
		{
			return false;
		}
		head = head->next;
		prev = prev->next;
	}
	return true;
}