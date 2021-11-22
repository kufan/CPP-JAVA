#pragma once

#include <iostream>
#include <cstdlib>
#include "LinkStack.h"

// 需要对入栈元素做封装
typedef struct MYCHAR {
	StackNode node;

	char* pAddr;  // 只想将要入栈的 '('
	int index;    // 记录待入栈的 '(' 的下标
}MyChar;

// 把待入栈的 '(' 封装为一个 结构体
MyChar* CreateMyChar(char* p, int pos);

// 识别 (
bool IsLeft(char c);

// 识别 )
bool IsRight(char c);

// 指出失配点所在
void ShowErr(char* str, int pos);