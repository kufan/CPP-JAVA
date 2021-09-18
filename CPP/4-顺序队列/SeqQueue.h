#pragma once

#define MAX_SIZE 1024

// ˳�����
typedef struct SEQQUEUE {
	// ָ�����飬���� data ��ֻ�ܱ��� void* ���͵�ָ��
	void* data[MAX_SIZE];
	
	int size;  // ��¼������Ԫ�ظ���
}SeqQueue;

// ��ʼ������
SeqQueue* Init_SeqQueue();

// ��Ӳ���
int Push_SeqQueue(SeqQueue* queue, void* dt);

// ���ض���Ԫ��
void* Front_SeqQueue(SeqQueue* queue);

// ����
int Pop_SeqQueue(SeqQueue* queue);

// ���ض���βԪ��
void* Back_SeqQueue(SeqQueue* queue);

// ���д�С
int GetSize_SeqQueue(SeqQueue* queue);

// ��ն���
int Clear_SeqQueue(SeqQueue* queue);

// ����
int Destroy_SeqQueue(SeqQueue* queue);