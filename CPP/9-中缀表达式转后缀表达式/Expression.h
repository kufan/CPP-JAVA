#pragma once

#include <iostream>
#include <cstdlib>
#include "LinkStack.h"

// 还要对待入栈的元素，进行封装
typedef struct MYCHAR {
	StackNode node;

	char* pAddr;  // 指针 p 所指向的元素，需要入栈
}MyChar;

// 解耦 --> 降低耦合
// 封装待入栈元素
MyChar* CreateMyChar(char* p);

// 识别数组
bool IsNum(char c);

// 识别 '('
bool IsLeft(char c);

// 识别 ')'
bool IsRight(char c);

// 识别运算符
bool IsOperator(char c);

// 确定运算符的优先级
int GetPriority(char c);

// 数字的操作
int NumOperator(char* p);

// '(' 的操作
int LeftOperator(LinkStack* stack, char* p);

// ')' 的操作
int RightOperator(LinkStack* stack);

// 运算符的操作
int OO(LinkStack* stack, char* p);