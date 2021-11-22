#include <cstdlib>

#include "SeqStack.h"

// ��ʼ��ջ
SeqStack* Init_Stack() {
	SeqStack* stack = NULL;
	stack = (SeqStack*)malloc(sizeof(SeqStack));
	if (NULL == stack) {
		perror("stack");
		return NULL;
	}

	for (int i = 0; i < MAX_SIZE; i++) {
		stack->data[i] = NULL;
	}
	stack->size = 0;

	return stack;
}

// ��ջ
int Push_SeqStack(SeqStack* stack, void* dt) {
	if (NULL == stack) {
		return -1;
	}
	if (NULL == dt) {
		return -2;
	}

	if (MAX_SIZE == stack->size) {
		return -3;
	}

	// ��ʱ�������� size ��Ԫ�أ����һ��Ԫ���±� size-1
	// ������Ԫ�أ����±�ͻ��� size
	stack->data[stack->size] = dt;
	stack->size++;

	return 0;
}

// ���ջ��Ԫ��
void* Front_SeqStack(SeqStack* stack) {
	if (NULL == stack) {
		return NULL;
	}

	if (0 == stack->size) {
		return NULL;
	}

	// ջ��Ԫ��Ҳ�������������һ��Ԫ��
	return stack->data[stack->size - 1];
}


// ��ջ����
int Pop_SeqStack(SeqStack* stack) {
	if (NULL == stack) {
		return -1;
	}
	if (0 == stack->size) {
		return -2;
	}

	// ����ɾ�����������һ��Ԫ��:��ʵ���ǵ� size ��Ԫ��
	// Ҳ�����±�Ϊ size-1 ��Ԫ��
	stack->data[stack->size - 1] = NULL;
	stack->size--;

	return 0;
}

// �ж�ջ�Ƿ�Ϊ��
int IsEmpty(SeqStack* stack) {
	if (NULL == stack) {
		return -1;
	}

	if (0 == stack->size) {
		return SEQSTACK_TRUE;
	}

	return SEQSTACK_FALSE;
}

// ���ջ��Ԫ�ظ���
int GetSize_SeqStack(SeqStack* stack) {
	if (NULL == stack) {
		return -1;
	}

	return stack->size;
}

// ���ջ
int Clear_SeqStack(SeqStack* stack) {
	if (NULL == stack) {
		return -1;
	}
	
	for (int i = 0; i < MAX_SIZE; i++) {
		stack->data[i] = NULL;
	}
	stack->size = 0;
	
	return 0;
}

// ����ջ
int Destroy_SeqStack(SeqStack* stack) {
	if (stack != NULL) {
		free(stack);
		stack = NULL;
	}

	return 0;
}