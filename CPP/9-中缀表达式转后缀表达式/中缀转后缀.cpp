#include <iostream>

#include "LinkStack.h"
#include "Expression.h"

using namespace std;

/*
	1������׺����ʽ�����ַ���ȥ������Ȼ���ͷ��β��ɨ��
	2������������֣���ֱ�Ӵ�ӡ
	3��������� '('����ֱ����ջ���� '(' �����ȼ����
	4��������� ')'����ջ��Ԫ�����γ�ջ������ӡ
		ֱ��ƥ�䵽 '('��ֹͣ��ջ
	5��������������
		����ǰջ�����������ȼ��Ƚ�
			���ջ���������ȼ��ͣ���ֱ����ջ
			���ջ���������޲���(>=)
				ջ������ֱ�ӳ�ջ����ӡ
				Ȼ��Ƚ���һ����ֱ��ջ���������ȼ���
	
 
*/


int main()
{
	char str[] = "8+(3-1)*5";
	char* p = str;

	LinkStack* stack = Init_Stack();

	while (*p != '\0') {
		// ���������
		if (IsNum(*p)) {
			NumOperator(p);
		}

		// ����� '('
		if (IsLeft(*p)) {
			LeftOperator(stack, p);
		}

		// ����� ')'
		if (IsRight(*p)) {
			RightOperator(stack);
		}

		// ����������
		if (IsOperator(*p)) {
			OO(stack, p);
		}
		
		p++;
	}

	// �ַ���ɨ�������ջ��ʣ��Ԫ��ֱ�ӵ�������ӡ
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