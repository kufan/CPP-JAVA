#include <iostream>

#include "LinkQueue.h"

using namespace std;

/*
队列特性
	1、是一种线性结构
	2、只能从队尾入队，只能从对头出队
		先进先出，后进后出
	3、队列中的数据
		无法修改
		无法排序 -- 数据一旦进入队列，就会固定

链式队列
	1、使用链表，模拟队列
	2、使用链表的头，模拟对头；使用链表的尾， 模拟队尾
	3、为了快速到达链表的尾部
		特意维护一个指针，该指针始终指向链表的尾部
*/

typedef struct STUDENT {
	QueueNode node;  // 为了维护链表中的节点

	char name[100];
	int age;
}Stu;

int main()
{
	LinkQueue* queue = Init_LinkQueue();

	Stu s1 = {NULL, "aaa", 18};
	Stu s2 = {NULL, "bbb", 19};
	Stu s3 = {NULL, "ccc", 20};
	Stu s4 = {NULL, "ddd", 21};
	Stu s5 = {NULL, "eee", 22};

	// 入队操作: 把指针 dt 所指向的节点，插入到链表末尾(数据只能从队尾入队)
	// int Push_LinkQueue(LinkQueue* queue, QueueNode* dt);
	Push_LinkQueue(queue, (QueueNode*)&s1);
	Push_LinkQueue(queue, (QueueNode*)&s2);
	Push_LinkQueue(queue, (QueueNode*)&s3);
	Push_LinkQueue(queue, (QueueNode*)&s4);
	Push_LinkQueue(queue, (QueueNode*)&s5);


	// 获得队头元素
	// QueueNode* Front_LinkQueue(LinkQueue * queue);
	// QueueNode* Back_LinkQueue(LinkQueue * queue);
	Stu* head = (Stu*)Front_LinkQueue(queue);
	cout << "起始时队首元素: name = " << head->name << ", age = " << head->age << endl;

	// 获得队尾元素
	Stu* R = (Stu*)Back_LinkQueue(queue);
	cout << "起始时队尾元素: name = " << R->name << ", age = " << R->age << endl;

	cout << "\n依次出队测试:\n";
	while (GetSize_LinkQueue(queue) != 0) {
		Stu* h = (Stu*)Front_LinkQueue(queue);
		cout << "当前队头: name = " << h->name << ", age = " << h->age << endl;

		Pop_LinkQueue(queue); 
	}

	Destroy_LinkQueue(queue);
	
	return 0;
}