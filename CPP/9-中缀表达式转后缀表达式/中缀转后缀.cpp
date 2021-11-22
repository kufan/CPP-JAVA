#include <iostream>

#include "LinkStack.h"
#include "Expression.h"

using namespace std;

/*
	1、把中缀表表达式当作字符串去看待，然后从头到尾的扫描
	2、如果遇到数字，则直接打印
	3、如果遇到 '('，则直接入栈，且 '(' 的优先级最低
	4、如果遇到 ')'，则栈顶元素依次出栈，并打印
		直到匹配到 '('，停止出栈
	5、如果遇到运算符
		跟当前栈顶符号做优先级比较
			如果栈顶符号优先级低，则直接入栈
			如果栈顶符号有限不低(>=)
				栈顶符号直接出栈并打印
				然后比较下一个，直到栈顶符号优先级低
	
 
*/


int main()
{
	char str[] = "8+(3-1)*5";
	char* p = str;

	LinkStack* stack = Init_Stack();

	while (*p != '\0') {
		// 如果是数字
		if (IsNum(*p)) {
			NumOperator(p);
		}

		// 如果是 '('
		if (IsLeft(*p)) {
			LeftOperator(stack, p);
		}

		// 如果是 ')'
		if (IsRight(*p)) {
			RightOperator(stack);
		}

		// 如果是运算符
		if (IsOperator(*p)) {
			OO(stack, p);
		}
		
		p++;
	}

	// 字符串扫描结束，栈中剩余元素直接弹出并打印
	while (GetSize_LinkStack(stack) > 0) {
		MyChar* my = (MyChar*)Front_LinkStack(stack);

		cout << *(my->pAddr);
		Pop_LinkStack(stack);
		if (my != NULL) {
			free(my);
			my = NULL;
		}
	}
	
	cout << endl;
	Destroy_LinkStack(stack);
	
	return 0;
}