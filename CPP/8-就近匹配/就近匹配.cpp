#include <iostream>

#include "match.h"
#include "LinkStack.h"

using namespace std;   // �� std �������ռ�

/*
	1���Ѵ��жϵ�ʽ�ӣ������ַ���ȥɨ��
	2������ '('  ֱ����ջ
	3������ ')' ��ջ��Ԫ��('(')ֱ�ӳ�ջ
		�뵱ǰ������ ')' ƥ��

	4���ַ���ɨ�����,���� ջ�ǿգ���ƥ��ʧ��
	5��ɨ�赽 ')'������ջΪ�գ���ƥ��ʧ��
*/

int main()
{
	char str[] = "1+2+3(dsfd(sfd))fsd(fd)f(d)sfd(4+5)";
	char* p = str;

	LinkStack* stack = Init_Stack();
	int idx = 0;
	int flag = 1;   // ��ʼʱ���������ƥ��ɹ�

	while (*p != '\0') {
		if (IsLeft(*p)) {
			// ����� �����ţ���ֱ����ջ
			// int Push_LinkStack(LinkStack* stack, StackNode* dt);
			// MyChar* CreateMyChar(char* p, int pos);
			MyChar* ch = CreateMyChar(p, idx);
			Push_LinkStack(stack, (StackNode*)ch);
		}

		if (IsRight(*p)) {
			// ȡ��ջ���� '('����֮ƥ��
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
				cout << "������ƥ��ʧ��" << endl;
				ShowErr(str, idx);
				break;
			}
		}

		p++;
		idx++;
	}


	while (GetSize_LinkStack(stack) > 0) {
		flag = 0;
		cout << "������ƥ��ʧ��" << endl;

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
		cout << "ƥ��ɹ�" << endl;
	}
	
	Destroy_LinkStack(stack);
	
	return 0;
}