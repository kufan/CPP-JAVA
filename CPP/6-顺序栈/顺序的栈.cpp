#include <iostream>
#include "SeqStack.h"

using namespace std;

/*
1、数据结构中的栈，是模拟内存中的栈的特性的
	内存中的栈，特性很多，只会模拟: 先进后出，后进先出这一个特性
	因为只能操作 栈顶，所以:  先进后出，后进先出

2、数据结构中栈的特点:
	数据一旦进入栈，就会固定
		内容无法被修改
		无法进行排序
		无法被遍历
	这个性质，跟 队列 的性质一样
		内容无法被修改
		无法进行排序
		无法被遍历

3、模拟方式：
	1、顺序栈
		就是用数组，模拟栈
		
	2、链式栈
		就是用链表，模拟栈
 
*/


typedef struct STUDENT {
	char name[100];
	int age;
}Stu;

int main()
{
	SeqStack* stack = Init_Stack();

	// 创建数据
	Stu s1 = { "aaa", 14 };
	Stu s2 = { "bbb", 15 };
	Stu s3 = { "ccc", 16 };
	Stu s4 = { "ddd", 17 };
	Stu s5 = { "eee", 18 };

	// 入栈
	// int Push_SeqStack(SeqStack * stack, void* dt);
	Push_SeqStack(stack, &s1);
	Push_SeqStack(stack, &s2);
	Push_SeqStack(stack, &s3);
	Push_SeqStack(stack, &s4);
	Push_SeqStack(stack, &s5);


	Stu* s = (Stu*)Front_SeqStack(stack);
	cout << "起始时，栈顶元素: name = " << s->name << ", age = " << s->age << endl;

	while (GetSize_SeqStack(stack) > 0) {
		Stu* ss = (Stu*)Front_SeqStack(stack);
		cout << "当前栈顶是: name = " << ss->name << ", age = " << ss->age << endl;

		Pop_SeqStack(stack);
	}
	
	if (IsEmpty(stack)) {
		cout << "此时栈为空" << endl;
	} else {
		cout << "此时栈非空" << endl;
	}

	
	Destroy_SeqStack(stack);
	
	
	return 0;
}