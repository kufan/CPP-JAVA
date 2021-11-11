#pragma once

// �������ڵ�
typedef struct QUEUENODE {
	struct QUEUENODE* next;  // ָ����ʼ��ֱ����һ���ڵ��ָ��
}QueueNode;

// �����������
typedef struct LINKQUEUE {
	QueueNode head;  // �����ͷ�ڵ�
	int size;  // ��¼�����нڵ���� -- ������Ԫ�ظ���
	QueueNode* rear;  // ��ָ���ʼ��ָ������β�ڵ� -- ʼ��ָ�����β��
}LinkQueue;

// ��ʼ������
LinkQueue* Init_LinkQueue();

// ��Ӳ���: ��ָ�� dt ��ָ��Ľڵ㣬���뵽����ĩβ(����ֻ�ܴӶ�β���)
int Push_LinkQueue(LinkQueue* queue, QueueNode* dt);

// ��ö�ͷԪ��
QueueNode* Front_LinkQueue(LinkQueue* queue);

// ��ö�βԪ��
QueueNode* Back_LinkQueue(LinkQueue* queue);

// ���Ӳ���: ɾ�������е�һ���ڵ�(������ͷ�ڵ�)
int Pop_LinkQueue(LinkQueue* queue);

// ��ö��д�С
int GetSize_LinkQueue(LinkQueue* queue);

// ��ն���
int Clear_LinkQueue(LinkQueue* queue);

// ���ٶ���
int Destroy_LinkQueue(LinkQueue* queue);