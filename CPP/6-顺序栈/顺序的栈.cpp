#include <iostream>
#include "SeqStack.h"

using namespace std;

/*
1�����ݽṹ�е�ջ����ģ���ڴ��е�ջ�����Ե�
	�ڴ��е�ջ�����Ժֻܶ࣬��ģ��: �Ƚ����������ȳ���һ������
	��Ϊֻ�ܲ��� ջ��������:  �Ƚ����������ȳ�

2�����ݽṹ��ջ���ص�:
	����һ������ջ���ͻ�̶�
		�����޷����޸�
		�޷���������
		�޷�������
	������ʣ��� ���� ������һ��
		�����޷����޸�
		�޷���������
		�޷�������

3��ģ�ⷽʽ��
	1��˳��ջ
		���������飬ģ��ջ
		
	2����ʽջ
		����������ģ��ջ
 
*/


typedef struct STUDENT {
	char name[100];
	int age;
}Stu;

int main()
{
	SeqStack* stack = Init_Stack();

	// ��������
	Stu s1 = { "aaa", 14 };
	Stu s2 = { "bbb", 15 };
	Stu s3 = { "ccc", 16 };
	Stu s4 = { "ddd", 17 };
	Stu s5 = { "eee", 18 };

	// ��ջ
	// int Push_SeqStack(SeqStack * stack, void* dt);
	Push_SeqStack(stack, &s1);
	Push_SeqStack(stack, &s2);
	Push_SeqStack(stack, &s3);
	Push_SeqStack(stack, &s4);
	Push_SeqStack(stack, &s5);


	Stu* s = (Stu*)Front_SeqStack(stack);
	cout << "��ʼʱ��ջ��Ԫ��: name = " << s->name << ", age = " << s->age << endl;

	while (GetSize_SeqStack(stack) > 0) {
		Stu* ss = (Stu*)Front_SeqStack(stack);
		cout << "��ǰջ����: name = " << ss->name << ", age = " << ss->age << endl;

		Pop_SeqStack(stack);
	}
	
	if (IsEmpty(stack)) {
		cout << "��ʱջΪ��" << endl;
	} else {
		cout << "��ʱջ�ǿ�" << endl;
	}

	
	Destroy_SeqStack(stack);
	
	
	return 0;
}