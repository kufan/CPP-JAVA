#include "Expression.h"

// 封装待入栈元素
MyChar* CreateMyChar(char* p) {
	MyChar* mychar = NULL;

	mychar = (MyChar*)malloc(sizeof(MyChar));
	if (NULL == mychar) {
		perror("malloc");
		return NULL;
	}

	mychar->pAddr = p;

	return mychar;
}

// 识别数组
bool IsNum(char c) {
	return c >= '0' && c <= '9';
}

// 识别 '('
bool IsLeft(char c) {
	return c == '(';
}

// 识别 ')'
bool IsRight(char c) {
	return c == ')';
}

// 识别运算符
bool IsOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

// 确定运算符的优先级
int GetPriority(char c) {
	if (c == '+' || c == '-') {
		return 1;
	}
	if (c == '*' || c == '/') {
		return 2;
	}

	return 0;
}


// 数字的操作
int NumOperator(char* p) {
	if (NULL == p) {
		return -1;
	}
	
	std::cout << *p;
	return 0;
}

// '(' 的操作
int LeftOperator(LinkStack* stack, char* p) {
	if (NULL == stack) {
		return -1;
	}
	if (NULL == p) {
		return -2;
	}

	// 先把指针 p 指向的，需要入栈的元素，封装
	MyChar* my = CreateMyChar(p);

	// int Push_LinkStack(LinkStack* stack, StackNode* dt);
	Push_LinkStack(stack, (StackNode*)my);

	return 0;
}

// ')' 的操作
// 4、如果遇到 ')'，则栈顶元素依次出栈，并打印
// 直到匹配到 '('，停止出栈
int RightOperator(LinkStack* stack) {
	if (NULL == stack) {
		return -1;
	}

	//StackNode* Front_LinkStack(LinkStack* stack);
	while (GetSize_LinkStack(stack) > 0) {
		MyChar* my = (MyChar*)Front_LinkStack(stack);

		if (IsLeft(*(my->pAddr))) {
			Pop_LinkStack(stack);
			if (my != NULL) {
				free(my);
				my = NULL;
				break;
			}
		}

		// 如果不是 (， 直接输出
		std::cout << *(my->pAddr);
		Pop_LinkStack(stack);
		if (my != NULL) {
			free(my);
			my = NULL;
		}
	}

	return 0;
}

// 运算符的操作
/*
	如果遇到运算符
		跟当前栈顶符号做优先级比较
			如果栈顶符号优先级低，则直接入栈
			如果栈顶符号有限不低(>=)
				栈顶符号直接出栈并打印
				然后比较下一个，直到栈顶符号优先级低
*/
int OO(LinkStack* stack, char* p) {
	if (NULL == stack) {
		return -1;
	}
	if (NULL == p) {
		return -2;
	}

	// p 指向的符号需要入栈
	// 入栈之前，需要比较 p 指向的符号 和 栈顶符号的优先级
	MyChar* my = (MyChar*)Front_LinkStack(stack);
	// 如果栈为空，则直接入栈
	if (my == NULL) {
		// 先把指针 p 指向的，需要入栈的元素，封装
		MyChar* mychar = CreateMyChar(p);

		// int Push_LinkStack(LinkStack* stack, StackNode* dt);
		Push_LinkStack(stack, (StackNode*)mychar);
		return 0;
	}

	// 比较 p 和栈顶元素的优先级
	// int GetPriority(char c);
	if (GetPriority(*p) > GetPriority(*(my->pAddr))) {
		// 如果栈顶符号优先级低,则 p 直接入栈
		// 先把指针 p 指向的，需要入栈的元素，封装
		MyChar* mychar = CreateMyChar(p);

		// int Push_LinkStack(LinkStack* stack, StackNode* dt);
		Push_LinkStack(stack, (StackNode*)mychar);
	} else {
		// 如果栈顶符号有限不低  >=
		while (GetSize_LinkStack(stack) > 0) {
			MyChar* my2 = (MyChar*)Front_LinkStack(stack);

			// 用当前栈顶和 p 做比较
			if (GetPriority(*(my2->pAddr)) < GetPriority(*p)) {
				// 则 p 直接入栈
				MyChar* mychar = CreateMyChar(p);

				// int Push_LinkStack(LinkStack* stack, StackNode* dt);
				Push_LinkStack(stack, (StackNode*)mychar);
				return 0;
			}

			std::cout << *(my2->pAddr);
			Pop_LinkStack(stack);
			if (my2 != NULL) {
				free(my2);
				my2 = NULL;
			}	
		}
	}

	return 0;
}