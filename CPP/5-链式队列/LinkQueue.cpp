#include <cstdlib>

#include "LinkQueue.h"

// 初始化队列
LinkQueue* Init_LinkQueue() {
	LinkQueue* queue = NULL;

	queue = (LinkQueue*)malloc(sizeof(LinkQueue));
	if(NULL == queue) {
		perror("malloc ");
		return NULL;
	}

	// 初始化堆区这块空间
	queue->size      = 0;
	queue->head.next = NULL;
	queue->rear      = &(queue->head); // 此时 head 既是头也是尾

	return queue;
}

// 入队操作: 把指针 dt 所指向的节点，插入到链表末尾(数据只能从队尾入队)
int Push_LinkQueue(LinkQueue* queue, QueueNode* dt) {
	if (NULL == queue) {
		return -1;
	}
	if (NULL == dt) {
		return -2;
	}

	queue->rear->next = dt;
	queue->rear = dt;

	queue->size++;
	
	return 0;
}

// 获得队头元素(其实就是链表中第一个节点的地址)
QueueNode* Front_LinkQueue(LinkQueue* queue) {
	if (NULL == queue) {
		return NULL;
	}

	return queue->head.next;
}

// 获得队尾元素
QueueNode* Back_LinkQueue(LinkQueue* queue) {
	if (NULL == queue) {
		return NULL;
	}

	return queue->rear;
}

// 出队操作: 删除队列中第一个节点(区别于头节点)
int Pop_LinkQueue(LinkQueue* queue) {
	if (NULL == queue) {
		return -1;
	}
	if (queue->size == 0) {
		return -2;
	}

	// 队列中，刚好只有一个元素时
	if (1 == queue->size) {
		queue->head.next = NULL;
		// 此时的 head 既是头，也是尾
		queue->rear = &(queue->head);
		queue->size = 0;
		return 0;
	}
	
	// 队列中元素个数多于一个时
	QueueNode* pCur = queue->head.next;
	queue->head.next = pCur->next;
	queue->size--;

	return 0;
}

// 获得队列大小
int GetSize_LinkQueue(LinkQueue* queue) {
	if (NULL == queue) {
		return -1;
	}
	
	return queue->size;
}

// 清空队列
int Clear_LinkQueue(LinkQueue* queue) {
	if (NULL == queue) {
		return -1;
	}
	
	queue->head.next = NULL;
	queue->size      = 0;
	queue->rear      = NULL;

	return 0;
}

// 销毁队列
int Destroy_LinkQueue(LinkQueue* queue) {
	if (NULL == queue) {
		return -1;
	}

	// 确保堆区空间，只被释放一次
	if (queue != NULL) {
		free(queue);
		queue = NULL;
	}

	return 0;
}