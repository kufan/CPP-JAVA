#include <iostream>

#include "match.h"
#include "LinkStack.h"

using namespace std;   // 打开 std 的命名空间

/*
	1、把待判断的式子，当作字符串去扫描
	2、遇到 '('  直接入栈
	3、遇到 ')' ，栈顶元素('(')直接出栈
		与当前遇到的 ')' 匹配

	4、字符串扫描结束,但是 栈非空，则匹配失败
	5、扫描到 ')'，但是栈为空，则匹配失败
*/

int main()
{
	char str[] = "1+2+3(dsfd(sfd))fsd(fd)f(d)sfd(4+5)";
	char* p = str;

	LinkStack* stack = Init_Stack();
	int idx = 0;
	int flag = 1;   // 起始时，假设可以匹配成功

	while (*p != '\0') {
		if (IsLeft(*p)) {
			// 如果是 左括号，则直接入栈
			// int Push_LinkStack(LinkStack* stack, StackNode* dt);
			// MyChar* CreateMyChar(char* p, int pos);
			MyChar* ch = CreateMyChar(p, idx);
			Push_LinkStack(stack, (StackNode*)ch);
		}

		if (IsRight(*p)) {
			// 取出栈顶的 '('，与之匹配
			if (GetSize_LinkStack(stack) > 0) {
				// StackNode* Front_LinkStack(LinkStack* stack);
				MyChar* ch = (MyChar*)Front_LinkStack(stack);
				if (IsLeft(*(ch->pAddr))) {
					Pop_LinkStack(stack);
					if (ch != NULL) {
						free(ch);
						ch = NULL;
					}
				}
				
			} else {
				flag = 0;
				cout << "右括号匹配失败" << endl;
				ShowErr(str, idx);
				break;
			}
		}

		p++;
		idx++;
	}


	while (GetSize_LinkStack(stack) > 0) {
		flag = 0;
		cout << "左括号匹配失败" << endl;

		MyChar* ch = (MyChar*)Front_LinkStack(stack);
		ShowErr(str, ch->index);
		Pop_LinkStack(stack);

		if (ch != NULL) {
			free(ch);
			ch = NULL;
		}
	}
	cout << endl;

	if (flag == 1) {
		cout << "匹配成功" << endl;
	}
	
	Destroy_LinkStack(stack);
	
	return 0;
}