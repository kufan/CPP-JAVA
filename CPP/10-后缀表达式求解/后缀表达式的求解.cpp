#include <iostream>

#include "Calc.h"
#include "LinkStack.h"

using namespace std;

int main()
{
	char str[] = "831-5*+";
	char* p = str;

	LinkStack* stack = Init_Stack();
	while (*p != '\0') {
		if (IsNum(*p)) {
			// 如果是数字，则直接入栈
			MyVal* val = (MyVal*)malloc(sizeof(MyVal));
			if (NULL == val) {
				perror("malloc");
				return 0;
			}
			val->val = *p - '0';
			Push_LinkStack(stack, (StackNode*)val);
		} else {
			// 如果是运算符
			// 先取出栈顶元素，作为右操作数
			MyVal* right = (MyVal*)Front_LinkStack(stack);
			int RightNum = right->val;
			Pop_LinkStack(stack);
			if (right != NULL) {
				free(right);
				right = NULL;
			}

			// 然后取出栈顶元素，作为左操作数
			MyVal* left = (MyVal*)Front_LinkStack(stack);
			int LeftNum = left->val;
			Pop_LinkStack(stack);
			if (left != NULL) {
				free(left);
				left = NULL;
			}

			int res = Caculate(LeftNum, RightNum, *p);

			// 计算结果，也要入栈
			MyVal* RES = (MyVal*)malloc(sizeof(MyVal));
			if (NULL == RES) {
				perror("malloc");
				return 0;
			}
			RES->val = res;
			Push_LinkStack(stack, (StackNode*)RES);
		}

		p++;
	}

	if (GetSize_LinkStack(stack) == 1) {
		MyVal* ans = (MyVal*)Front_LinkStack(stack);
		cout << "计算结果: " << ans->val << endl;

		Pop_LinkStack(stack);
		if (ans != NULL) {
			free(ans);
			ans = NULL;
		}
	}

	Destroy_LinkStack(stack);
	
	return 0;
}