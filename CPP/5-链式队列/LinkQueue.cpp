#include <cstdlib>

#include "LinkQueue.h"

// ��ʼ������
LinkQueue* Init_LinkQueue() {
	LinkQueue* queue = NULL;

	queue = (LinkQueue*)malloc(sizeof(LinkQueue));
	if(NULL == queue) {
		perror("malloc ");
		return NULL;
	}

	// ��ʼ���������ռ�
	queue->size      = 0;
	queue->head.next = NULL;
	queue->rear      = &(queue->head); // ��ʱ head ����ͷҲ��β

	return queue;
}

// ��Ӳ���: ��ָ�� dt ��ָ��Ľڵ㣬���뵽����ĩβ(����ֻ�ܴӶ�β���)
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

// ��ö�ͷԪ��(��ʵ���������е�һ���ڵ�ĵ�ַ)
QueueNode* Front_LinkQueue(LinkQueue* queue) {
	if (NULL == queue) {
		return NULL;
	}

	return queue->head.next;
}

// ��ö�βԪ��
QueueNode* Back_LinkQueue(LinkQueue* queue) {
	if (NULL == queue) {
		return NULL;
	}

	return queue->rear;
}

// ���Ӳ���: ɾ�������е�һ���ڵ�(������ͷ�ڵ�)
int Pop_LinkQueue(LinkQueue* queue) {
	if (NULL == queue) {
		return -1;
	}
	if (queue->size == 0) {
		return -2;
	}

	// �����У��պ�ֻ��һ��Ԫ��ʱ
	if (1 == queue->size) {
		queue->head.next = NULL;
		// ��ʱ�� head ����ͷ��Ҳ��β
		queue->rear = &(queue->head);
		queue->size = 0;
		return 0;
	}
	
	// ������Ԫ�ظ�������һ��ʱ
	QueueNode* pCur = queue->head.next;
	queue->head.next = pCur->next;
	queue->size--;

	return 0;
}

// ��ö��д�С
int GetSize_LinkQueue(LinkQueue* queue) {
	if (NULL == queue) {
		return -1;
	}
	
	return queue->size;
}

// ��ն���
int Clear_LinkQueue(LinkQueue* queue) {
	if (NULL == queue) {
		return -1;
	}
	
	queue->head.next = NULL;
	queue->size      = 0;
	queue->rear      = NULL;

	return 0;
}

// ���ٶ���
int Destroy_LinkQueue(LinkQueue* queue) {
	if (NULL == queue) {
		return -1;
	}

	// ȷ�������ռ䣬ֻ���ͷ�һ��
	if (queue != NULL) {
		free(queue);
		queue = NULL;
	}

	return 0;
}