#pragma once

#include <cstdlib>
#include "LinkStack.h"

// ��Ҫ����ջԪ�ؽ��з�װ
// ��װΪһ���ṹ��
typedef struct MYVAL {
	StackNode node;
	
	int val;   // ��Ҫ��ջ������
}MyVal;

bool IsNum(char p);

int Caculate(int left, int right, char c);