#include <iostream>

#include "LinkStack.h"

using namespace std;

// 链表的头，模拟栈顶

typedef struct STUDENT {
	StackNode node;

	char name[100];
	int age;
}Stu;

int main()
{
	LinkStack* stack = Init_Stack();

	// 创建数据
	Stu s1 = {NULL, "aaa", 13};
	Stu s2 = {NULL, "bbb", 14};
	Stu s3 = {NULL, "ccc", 15};
	Stu s4 = {NULL, "ddd", 16};
	Stu s5 = {NULL, "eee", 17};

	// 入栈操作：就是把 dt 这个元素，插入到链表的头部
	// int Push_LinkStack(LinkStack * stack, StackNode * dt);
	Push_LinkStack(stack, ( StackNode*)&s1);
	Push_LinkStack(stack, ( StackNode*)&s2);
	Push_LinkStack(stack, ( StackNode*)&s3);
	Push_LinkStack(stack, ( StackNode*)&s4);
	Push_LinkStack(stack, ( StackNode*)&s5);

	Stu* s = (Stu*)Front_LinkStack(stack);
	cout << "起始时，栈顶元素: name = " << s->name << ", age = " << s->age << endl;

	while (GetSize_LinkStack(stack) > 0) {
		Stu* ss = (Stu*)Front_LinkStack(stack);
		cout << "当前栈顶是: name = " << ss->name << ", age = " << ss->age << endl;

		Pop_LinkStack(stack);
	}

	if (IsEmpty(stack)) {
		cout << "此时栈为空" << endl;
	}
	else {
		cout << "此时栈非空" << endl;
	}


	Destroy_LinkStack(stack);

	
	return 0;
}