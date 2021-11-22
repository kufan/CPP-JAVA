#pragma once

#include <iostream>
#include <cstdlib>
#include "LinkStack.h"

// ��Ҫ�Դ���ջ��Ԫ�أ����з�װ
typedef struct MYCHAR {
	StackNode node;

	char* pAddr;  // ָ�� p ��ָ���Ԫ�أ���Ҫ��ջ
}MyChar;

// ���� --> �������
// ��װ����ջԪ��
MyChar* CreateMyChar(char* p);

// ʶ������
bool IsNum(char c);

// ʶ�� '('
bool IsLeft(char c);

// ʶ�� ')'
bool IsRight(char c);

// ʶ�������
bool IsOperator(char c);

// ȷ������������ȼ�
int GetPriority(char c);

// ���ֵĲ���
int NumOperator(char* p);

// '(' �Ĳ���
int LeftOperator(LinkStack* stack, char* p);

// ')' �Ĳ���
int RightOperator(LinkStack* stack);

// ������Ĳ���
int OO(LinkStack* stack, char* p);