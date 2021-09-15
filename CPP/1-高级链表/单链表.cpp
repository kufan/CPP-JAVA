#include <iostream>

#include "LinkList.h"

using namespace std;

// 设计一个结构体，把这个结构保存到链表中
typedef struct STUDENT {
	char name[50];
	int age;
}Stu;

// 按照要求，提供一个打印函数
// typedef void(*PRINTLIST)(void*);
void My_Pinrt(void* data) {
	Stu* p = (Stu*)data;

	cout << "name = " << p->name << ", age = " << p->age << endl;
}

int main()
{
	// 初始化链表
	// LinkList* Init_LinkList();
	LinkList* list = Init_LinkList();

	// 创造数据
	Stu s1 = {"aaa", 12};
	Stu s2 = { "bbb", 13 };
	Stu s3 = { "ccc", 14 };
	Stu s4 = { "ddd", 15 };
	Stu s5 = { "eee", 16 };
	
	// int Insert_LinkList(LinkList* list, int pos, void* dt);
	Insert_LinkList(list, 0, &s1);
	Insert_LinkList(list, 1, &s2);
	Insert_LinkList(list, 2, &s3);
	Insert_LinkList(list, 3, &s4);
	Insert_LinkList(list, 4, &s5);

	cout << "链表中节点个数: " << GetSize_LinkList(list) << endl;

	// int Print_LinkList(LinkList* list, PRINTLIST print);
	// 	Print_LinkList(list, My_Pinrt());
	Print_LinkList(list, My_Pinrt);


	// int DeleteByPos_LinkList(LinkList * list, int pos);
	DeleteByPos_LinkList(list, 3);
	cout << "删除操作之后，链表中节点个数: " << GetSize_LinkList(list) << endl;
	Print_LinkList(list, My_Pinrt);
	
	
	Destory_LinkList(list);
	
	return 0;
}