#pragma once

#include <iostream>
#include <cstdlib>
#include "LinkStack.h"

// ��Ҫ����ջԪ������װ
typedef struct MYCHAR {
	StackNode node;

	char* pAddr;  // ֻ�뽫Ҫ��ջ�� '('
	int index;    // ��¼����ջ�� '(' ���±�
}MyChar;

// �Ѵ���ջ�� '(' ��װΪһ�� �ṹ��
MyChar* CreateMyChar(char* p, int pos);

// ʶ�� (
bool IsLeft(char c);

// ʶ�� )
bool IsRight(char c);

// ָ��ʧ�������
void ShowErr(char* str, int pos);