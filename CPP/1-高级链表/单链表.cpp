#include <iostream>

#include "LinkList.h"

using namespace std;

// ���һ���ṹ�壬������ṹ���浽������
typedef struct STUDENT {
	char name[50];
	int age;
}Stu;

// ����Ҫ���ṩһ����ӡ����
// typedef void(*PRINTLIST)(void*);
void My_Pinrt(void* data) {
	Stu* p = (Stu*)data;

	cout << "name = " << p->name << ", age = " << p->age << endl;
}

int main()
{
	// ��ʼ������
	// LinkList* Init_LinkList();
	LinkList* list = Init_LinkList();

	// ��������
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

	cout << "�����нڵ����: " << GetSize_LinkList(list) << endl;

	// int Print_LinkList(LinkList* list, PRINTLIST print);
	// 	Print_LinkList(list, My_Pinrt());
	Print_LinkList(list, My_Pinrt);


	// int DeleteByPos_LinkList(LinkList * list, int pos);
	DeleteByPos_LinkList(list, 3);
	cout << "ɾ������֮�������нڵ����: " << GetSize_LinkList(list) << endl;
	Print_LinkList(list, My_Pinrt);
	
	
	Destory_LinkList(list);
	
	return 0;
}