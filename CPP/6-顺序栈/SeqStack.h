#pragma once

#define MAX_SIZE 1024
#define SEQSTACK_TRUE  1
#define SEQSTACK_FALSE 0

// ���ջ
typedef struct SEQSTACK {
	// ָ������,������Ԫ�ر���ָ�룬�������п��Ա�����������ָ��
	void* data[MAX_SIZE];
	int size;  // ��¼�����е�ǰ��Ԫ�ظ���
}SeqStack;

// ��ʼ��ջ
SeqStack* Init_Stack();

// ��ջ
int Push_SeqStack(SeqStack* stack, void* dt);

// ���ջ��Ԫ��
void* Front_SeqStack(SeqStack* stack);

// ��ջ����
int Pop_SeqStack(SeqStack* stack);

// �ж�ջ�Ƿ�Ϊ��
int IsEmpty(SeqStack* stack);

// ���ջ��Ԫ�ظ���
int GetSize_SeqStack(SeqStack* stack);

// ���ջ
int Clear_SeqStack(SeqStack* stack);

// ����ջ
int Destroy_SeqStack(SeqStack* stack);