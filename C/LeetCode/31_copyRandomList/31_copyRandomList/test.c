#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int val;
	struct Node* next;
	struct Node* random;
};

struct Node* copyRandomList(struct Node* head) {
	//如果为空直接返回
	if (head == NULL)
		return NULL;

	//让创建的新节点直接跟在老节点后面
	struct Node* pcur = head;
	while (pcur)
	{
		struct Node* temp = pcur->next;
		struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
		newnode->val = pcur->val;

		newnode->next = temp;
		pcur->next = newnode;
		pcur = temp;
	}

	//开始对创建的新节点的random进行操作
	//新链表一定是偶数个节点
	pcur = head;
	while (pcur)
	{
		if (pcur->random == NULL)
		{
			pcur->next->random = NULL;
		}
		else
		{
			pcur->next->random = pcur->random->next;
		}
		pcur = pcur->next->next;
	}

	//最后把链表拆分成原来的老链表和复制的新链表
	pcur = head;
	struct Node* newhead = head->next;
	struct Node* newcur = newhead;
	while (pcur)
	{
		//跳过创建的新节点
		pcur->next = pcur->next->next;
		if (newcur->next != NULL)
		{
			newcur->next = newcur->next->next;
		}

		pcur = pcur->next;
		newcur = newcur->next;
	}
	return newhead;
}