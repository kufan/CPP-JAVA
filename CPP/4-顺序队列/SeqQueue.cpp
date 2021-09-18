#include <cstdlib>

#include "SeqQueue.h"

// ��ʼ������
SeqQueue* Init_SeqQueue() {
	SeqQueue* queue = NULL;
	queue = (SeqQueue*)malloc(sizeof(SeqQueue));
	if (NULL == queue) {
		perror("malloc: ");
		return NULL;
	}

	// ��ʼ�������ռ�
	for (int i = 0; i < MAX_SIZE; i++) {
		queue->data[i] = NULL;
	}
	queue->size = 0;

	return queue;
}

// ��Ӳ���
// ����β������һ�� dt Ԫ�أ�����β������Ԫ��
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

	// ���£���������  size ��Ԫ�أ����һ��Ԫ���±� size-1
	// �ٲ���һ��Ԫ�أ����±� size
	queue->data[queue->size] = dt;
	queue->size++;

	return 0;
}

// ���ض���Ԫ��
void* Front_SeqQueue(SeqQueue* queue) {
	if (NULL == queue) {
		return NULL;
	}
	if (queue->size == 0) {
		return NULL;
	}
	
	return queue->data[0];
}

// ����
// ɾ������Ԫ�� --> ����ɾ����������Ԫ��
int Pop_SeqQueue(SeqQueue* queue) {
	if (NULL == queue) {
		return -1;
	}
	if (queue->size == 0) {
		return -2;
	}

	// ɾ����������Ԫ��
	for (int i = 0; i < queue->size - 1; i++) {
		queue->data[i] = queue->data[i + 1];
	}
	queue->size--;

	return 0;
}

// ���ض���βԪ��
void* Back_SeqQueue(SeqQueue* queue) {
	if (queue == NULL) {
		return NULL;
	}
	if (queue->size == 0) {
		return NULL;
	}

	return queue->data[queue->size - 1];
}

// ���д�С
int GetSize_SeqQueue(SeqQueue* queue) {
	if (queue == NULL) {
		return -1;
	}

	return queue->size;
}

// ��ն���
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

// ����
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