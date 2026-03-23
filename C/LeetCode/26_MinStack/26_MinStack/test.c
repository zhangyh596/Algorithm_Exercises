#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

typedef struct {
	int main_stack[30005];//一号桶正常放球
	int min_stack[30005];//二号桶同步放当前最小值
	int top;//记录下一个球应该放的位置
} MinStack;


MinStack* minStackCreate() {
	MinStack* newStack = (MinStack*)malloc(sizeof(MinStack));
	newStack->top = 0;
	return newStack;
}

void minStackPush(MinStack* obj, int val) {
	obj->main_stack[obj->top] = val;

	if (obj->top == 0)
	{
		obj->min_stack[obj->top] = val;
	}
	else
	{
		if (val < obj->min_stack[obj->top - 1])
		{
			obj->min_stack[obj->top] = val;
		}
		else
		{
			obj->min_stack[obj->top] = obj->min_stack[obj->top - 1];
		}
	}

	obj->top++;
}

void minStackPop(MinStack* obj) {
	obj->top--;
}

int minStackTop(MinStack* obj) {
	return obj->main_stack[obj->top - 1];
}

int minStackGetMin(MinStack* obj) {
	return obj->min_stack[obj->top - 1];
}

void minStackFree(MinStack* obj) {
	free(obj);
	obj = NULL;
}