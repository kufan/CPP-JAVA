#include <cstdlib>

#include "LinkStack.h"

LinkStack* Init_Stack() {
	LinkStack* stack = NULL;
	stack = (LinkStack*)malloc(sizeof(LinkStack));
	if(NULL == stack) {
		perror("malloc");
		return NULL;
	}

	stack->head.next = NULL;
	stack->size      = 0;

	
	return stack;
}


// 入栈操作：就是把 dt 这个元素，插入到链表的头部
int Push_LinkStack(LinkStack* stack, StackNode* dt) {
	if (NULL == stack) {
		return -1;
	}
	if (dt == NULL) {
		return -2;
	}

	dt->next = stack->head.next;
	stack->head.next = dt;

	stack->size++;

	return 0;
}

// 返回栈顶元素
StackNode* Front_LinkStack(LinkStack* stack) {
	if (NULL == stack) {
		return NULL;
	}
	if(0 == stack->size) {
		return NULL;
	}

	return stack->head.next;
}

// 出栈操作 -- 删除第一个节点
int Pop_LinkStack(LinkStack* stack) {
	if (NULL == stack) {
		return NULL;
	}
	if (0 == stack->size) {
		return NULL;
	}

	StackNode* pDel  = stack->head.next;
	stack->head.next = pDel->next;
	// pDel->next = NULL;  // 可有可无

	stack->size--;

	return 0;
}

// 判断栈是否为空
int IsEmpty(LinkStack* stack) {
	if (NULL == stack) {
		return -1;
	}

	if (0 == stack->size) {
		return LINKSTACK_TRUE;
	}

	return LINKSTACK_FALSE;
}

// 获得栈中元素个数
int GetSize_LinkStack(LinkStack* stack) {
	if (NULL == stack) {
		return -1;
	}
	
	return stack->size;
}

// 清空
int Clear_LinkStack(LinkStack* stack) {
	if (NULL == stack) {
		return -1;
	}

	stack->head.next = NULL;
	stack->size      = 0;

	return 0;
}

// 销毁
int Destroy_LinkStack(LinkStack* stack) {
	if (stack != NULL) {
		free(stack);
		stack = NULL;
	}

	return 0;
}