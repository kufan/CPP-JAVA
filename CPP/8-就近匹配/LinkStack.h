#pragma once

#define LINKSTACK_TRUE  1
#define LINKSTACK_FALSE 0

// ����ڵ�
typedef struct STACKNODE {
	struct STACKNODE* next;
}StackNode;

// ��������
typedef struct LINKSTACK {
	StackNode head;  // �����ͷ
	int size;   // ��������С
}LinkStack;

LinkStack* Init_Stack();

// ��ջ���������ǰ� dt ���Ԫ�أ����뵽�����ͷ��
int Push_LinkStack(LinkStack* stack, StackNode* dt);

// ����ջ��Ԫ��
StackNode* Front_LinkStack(LinkStack* stack);

// ��ջ���� -- ɾ����һ���ڵ�
int Pop_LinkStack(LinkStack* stack);

// �ж�ջ�Ƿ�Ϊ��
int IsEmpty(LinkStack* stack);

// ���ջ��Ԫ�ظ���
int GetSize_LinkStack(LinkStack* stack);

// ���
int Clear_LinkStack(LinkStack* stack);

// ����
int Destroy_LinkStack(LinkStack* stack);