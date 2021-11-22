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


// ��ջ���������ǰ� dt ���Ԫ�أ����뵽�����ͷ��
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

// ����ջ��Ԫ��
StackNode* Front_LinkStack(LinkStack* stack) {
	if (NULL == stack) {
		return NULL;
	}
	if(0 == stack->size) {
		return NULL;
	}

	return stack->head.next;
}

// ��ջ���� -- ɾ����һ���ڵ�
int Pop_LinkStack(LinkStack* stack) {
	if (NULL == stack) {
		return NULL;
	}
	if (0 == stack->size) {
		return NULL;
	}

	StackNode* pDel  = stack->head.next;
	stack->head.next = pDel->next;
	// pDel->next = NULL;  // ���п���

	stack->size--;

	return 0;
}

// �ж�ջ�Ƿ�Ϊ��
int IsEmpty(LinkStack* stack) {
	if (NULL == stack) {
		return -1;
	}

	if (0 == stack->size) {
		return LINKSTACK_TRUE;
	}

	return LINKSTACK_FALSE;
}

// ���ջ��Ԫ�ظ���
int GetSize_LinkStack(LinkStack* stack) {
	if (NULL == stack) {
		return -1;
	}
	
	return stack->size;
}

// ���
int Clear_LinkStack(LinkStack* stack) {
	if (NULL == stack) {
		return -1;
	}

	stack->head.next = NULL;
	stack->size      = 0;

	return 0;
}

// ����
int Destroy_LinkStack(LinkStack* stack) {
	if (stack != NULL) {
		free(stack);
		stack = NULL;
	}

	return 0;
}