#include <iostream>

#include "LinkStack.h"

using namespace std;

// �����ͷ��ģ��ջ��

typedef struct STUDENT {
	StackNode node;

	char name[100];
	int age;
}Stu;

int main()
{
	LinkStack* stack = Init_Stack();

	// ��������
	Stu s1 = {NULL, "aaa", 13};
	Stu s2 = {NULL, "bbb", 14};
	Stu s3 = {NULL, "ccc", 15};
	Stu s4 = {NULL, "ddd", 16};
	Stu s5 = {NULL, "eee", 17};

	// ��ջ���������ǰ� dt ���Ԫ�أ����뵽�����ͷ��
	// int Push_LinkStack(LinkStack * stack, StackNode * dt);
	Push_LinkStack(stack, ( StackNode*)&s1);
	Push_LinkStack(stack, ( StackNode*)&s2);
	Push_LinkStack(stack, ( StackNode*)&s3);
	Push_LinkStack(stack, ( StackNode*)&s4);
	Push_LinkStack(stack, ( StackNode*)&s5);

	Stu* s = (Stu*)Front_LinkStack(stack);
	cout << "��ʼʱ��ջ��Ԫ��: name = " << s->name << ", age = " << s->age << endl;

	while (GetSize_LinkStack(stack) > 0) {
		Stu* ss = (Stu*)Front_LinkStack(stack);
		cout << "��ǰջ����: name = " << ss->name << ", age = " << ss->age << endl;

		Pop_LinkStack(stack);
	}

	if (IsEmpty(stack)) {
		cout << "��ʱջΪ��" << endl;
	}
	else {
		cout << "��ʱջ�ǿ�" << endl;
	}


	Destroy_LinkStack(stack);

	
	return 0;
}