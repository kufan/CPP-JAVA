#pragma once

#include <cstdlib>
#include "LinkStack.h"

// 需要对入栈元素进行封装
// 封装为一个结构体
typedef struct MYVAL {
	StackNode node;
	
	int val;   // 需要入栈的整数
}MyVal;

bool IsNum(char p);

int Caculate(int left, int right, char c);