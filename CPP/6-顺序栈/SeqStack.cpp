#include <cstdlib>

#include "SeqStack.h"

// 初始化栈
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

// 入栈
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

	// 此时数组中有 size 个元素，最后一个元素下标 size-1
	// 新来的元素，其下标就会变成 size
	stack->data[stack->size] = dt;
	stack->size++;

	return 0;
}

// 获得栈顶元素
void* Front_SeqStack(SeqStack* stack) {
	if (NULL == stack) {
		return NULL;
	}

	if (0 == stack->size) {
		return NULL;
	}

	// 栈顶元素也就是数组中最后一个元素
	return stack->data[stack->size - 1];
}


// 出栈操作
int Pop_SeqStack(SeqStack* stack) {
	if (NULL == stack) {
		return -1;
	}
	if (0 == stack->size) {
		return -2;
	}

	// 就是删除数组中最后一个元素:其实就是第 size 个元素
	// 也就是下标为 size-1 的元素
	stack->data[stack->size - 1] = NULL;
	stack->size--;

	return 0;
}

// 判断栈是否为空
int IsEmpty(SeqStack* stack) {
	if (NULL == stack) {
		return -1;
	}

	if (0 == stack->size) {
		return SEQSTACK_TRUE;
	}

	return SEQSTACK_FALSE;
}

// 获得栈中元素个数
int GetSize_SeqStack(SeqStack* stack) {
	if (NULL == stack) {
		return -1;
	}

	return stack->size;
}

// 清空栈
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

// 销毁栈
int Destroy_SeqStack(SeqStack* stack) {
	if (stack != NULL) {
		free(stack);
		stack = NULL;
	}

	return 0;
}