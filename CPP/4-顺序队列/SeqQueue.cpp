#include <cstdlib>

#include "SeqQueue.h"

// 初始化队列
SeqQueue* Init_SeqQueue() {
	SeqQueue* queue = NULL;
	queue = (SeqQueue*)malloc(sizeof(SeqQueue));
	if (NULL == queue) {
		perror("malloc: ");
		return NULL;
	}

	// 初始化堆区空间
	for (int i = 0; i < MAX_SIZE; i++) {
		queue->data[i] = NULL;
	}
	queue->size = 0;

	return queue;
}

// 入队操作
// 队列尾部插入一个 dt 元素，数组尾部插入元素
int Push_SeqQueue(SeqQueue* queue, void* dt) {
	if (NULL == queue) {
		return -1;
	}
	if (NULL == dt) {
		return -2;
	}
	if (queue->size == MAX_SIZE) {
		return -3;
	}

	// 眼下，数组中有  size 个元素，最后一个元素下标 size-1
	// 再插入一个元素，其下标 size
	queue->data[queue->size] = dt;
	queue->size++;

	return 0;
}

// 返回队首元素
void* Front_SeqQueue(SeqQueue* queue) {
	if (NULL == queue) {
		return NULL;
	}
	if (queue->size == 0) {
		return NULL;
	}
	
	return queue->data[0];
}

// 出队
// 删除队首元素 --> 就是删除数组中首元素
int Pop_SeqQueue(SeqQueue* queue) {
	if (NULL == queue) {
		return -1;
	}
	if (queue->size == 0) {
		return -2;
	}

	// 删除数组中首元素
	for (int i = 0; i < queue->size - 1; i++) {
		queue->data[i] = queue->data[i + 1];
	}
	queue->size--;

	return 0;
}

// 返回队列尾元素
void* Back_SeqQueue(SeqQueue* queue) {
	if (queue == NULL) {
		return NULL;
	}
	if (queue->size == 0) {
		return NULL;
	}

	return queue->data[queue->size - 1];
}

// 队列大小
int GetSize_SeqQueue(SeqQueue* queue) {
	if (queue == NULL) {
		return -1;
	}

	return queue->size;
}

// 清空队列
int Clear_SeqQueue(SeqQueue* queue) {
	if (queue == NULL) {
		return -1;
	}

	for (int i = 0; i < queue->size; i++) {
		queue->data[i] = NULL;
	}
	queue->size = 0;

	return 0;
}

// 销毁
int Destroy_SeqQueue(SeqQueue* queue) {
	if (queue == NULL) {
		return -1;
	}

	if (queue != NULL) {
		free(queue);
		queue = NULL;
	}

	return 0;
}