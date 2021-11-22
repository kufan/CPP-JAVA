#include "Expression.h"

// ��װ����ջԪ��
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

// ʶ������
bool IsNum(char c) {
	return c >= '0' && c <= '9';
}

// ʶ�� '('
bool IsLeft(char c) {
	return c == '(';
}

// ʶ�� ')'
bool IsRight(char c) {
	return c == ')';
}

// ʶ�������
bool IsOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

// ȷ������������ȼ�
int GetPriority(char c) {
	if (c == '+' || c == '-') {
		return 1;
	}
	if (c == '*' || c == '/') {
		return 2;
	}

	return 0;
}


// ���ֵĲ���
int NumOperator(char* p) {
	if (NULL == p) {
		return -1;
	}
	
	std::cout << *p;
	return 0;
}

// '(' �Ĳ���
int LeftOperator(LinkStack* stack, char* p) {
	if (NULL == stack) {
		return -1;
	}
	if (NULL == p) {
		return -2;
	}

	// �Ȱ�ָ�� p ָ��ģ���Ҫ��ջ��Ԫ�أ���װ
	MyChar* my = CreateMyChar(p);

	// int Push_LinkStack(LinkStack* stack, StackNode* dt);
	Push_LinkStack(stack, (StackNode*)my);

	return 0;
}

// ')' �Ĳ���
// 4��������� ')'����ջ��Ԫ�����γ�ջ������ӡ
// ֱ��ƥ�䵽 '('��ֹͣ��ջ
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

		// ������� (�� ֱ�����
		std::cout << *(my->pAddr);
		Pop_LinkStack(stack);
		if (my != NULL) {
			free(my);
			my = NULL;
		}
	}

	return 0;
}

// ������Ĳ���
/*
	������������
		����ǰջ�����������ȼ��Ƚ�
			���ջ���������ȼ��ͣ���ֱ����ջ
			���ջ���������޲���(>=)
				ջ������ֱ�ӳ�ջ����ӡ
				Ȼ��Ƚ���һ����ֱ��ջ���������ȼ���
*/
int OO(LinkStack* stack, char* p) {
	if (NULL == stack) {
		return -1;
	}
	if (NULL == p) {
		return -2;
	}

	// p ָ��ķ�����Ҫ��ջ
	// ��ջ֮ǰ����Ҫ�Ƚ� p ָ��ķ��� �� ջ�����ŵ����ȼ�
	MyChar* my = (MyChar*)Front_LinkStack(stack);
	// ���ջΪ�գ���ֱ����ջ
	if (my == NULL) {
		// �Ȱ�ָ�� p ָ��ģ���Ҫ��ջ��Ԫ�أ���װ
		MyChar* mychar = CreateMyChar(p);

		// int Push_LinkStack(LinkStack* stack, StackNode* dt);
		Push_LinkStack(stack, (StackNode*)mychar);
		return 0;
	}

	// �Ƚ� p ��ջ��Ԫ�ص����ȼ�
	// int GetPriority(char c);
	if (GetPriority(*p) > GetPriority(*(my->pAddr))) {
		// ���ջ���������ȼ���,�� p ֱ����ջ
		// �Ȱ�ָ�� p ָ��ģ���Ҫ��ջ��Ԫ�أ���װ
		MyChar* mychar = CreateMyChar(p);

		// int Push_LinkStack(LinkStack* stack, StackNode* dt);
		Push_LinkStack(stack, (StackNode*)mychar);
	} else {
		// ���ջ���������޲���  >=
		while (GetSize_LinkStack(stack) > 0) {
			MyChar* my2 = (MyChar*)Front_LinkStack(stack);

			// �õ�ǰջ���� p ���Ƚ�
			if (GetPriority(*(my2->pAddr)) < GetPriority(*p)) {
				// �� p ֱ����ջ
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