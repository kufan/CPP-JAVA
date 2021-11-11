#include <iostream>

#include "SeqQueue.h"

using namespace std;

/*
队列的概念:
	队列是一种线性表
	数据只能从队尾入队，只能从队头出队
		先进先出，后进后出的一种结构

队列的实现:
	1、借助数组实现，就是所谓的 顺序结构
		用数组头当作队头，数组尾当作队尾
		入队的操作很快速，但是出队的操作，效率就会不稳定
	2、借助链表实现，就是所谓的 链式结构
	
*/

typedef struct STIDENT {
	char name[100];
	int age;
}Stu;

int main()
{
	SeqQueue* queue = Init_SeqQueue();

	Stu s1 = {"aaa", 16};
	Stu s2 = { "bbb", 17 };
	Stu s3 = { "ccc", 18 };
	Stu s4 = { "ddd", 19 };
	Stu s5 = { "eee", 20 };

	// int Push_SeqQueue(SeqQueue* queue, void* dt);
	Push_SeqQueue(queue, &s1);
	Push_SeqQueue(queue, &s2);
	Push_SeqQueue(queue, &s3);
	Push_SeqQueue(queue, &s4);
	Push_SeqQueue(queue, &s5);

	Stu* H = (Stu*)Front_SeqQueue(queue);
	cout << "队首: name = " << H->name << ", age = " << H->age << endl;

	Stu* T = (Stu*)Back_SeqQueue(queue);
	cout << "队尾: name = " << T->name << ", age = " << T->age << endl;

	cout << "\n依次出队测试:\n";
	while (queue->size != 0) {
		Stu* head = (Stu*)Front_SeqQueue(queue);
		cout << "当前队头: name = " << head->name << ", age = " << head->age << endl;

		Pop_SeqQueue(queue);
	}

	
	Destroy_SeqQueue(queue);
	
	return 0;
}