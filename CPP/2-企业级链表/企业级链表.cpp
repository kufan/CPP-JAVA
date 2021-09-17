#include <iostream>
#include <cstring>


#include "LinkList.h"

using namespace std;

// �������
typedef struct STUDENT {
	LinkNode node;  // ����ҹ�
	char name[100];
	int age;
}Stu;


// ��ӡ�ص�����
void MyPrint(LinkNode* dt) {
	Stu* s = (Stu*)dt;
	cout << "name = " << s->name << ", age = " << s->age << endl;
}

// �Ƚϻص�����
int MyCompare(LinkNode* dt1, LinkNode* dt2) {
	Stu* s1 = (Stu*)dt1;
	Stu* s2 = (Stu*)dt2;

	if (strcmp(s1->name, s2->name)==0 && s1->age == s2->age) {
		return 0;
	}
	
	return -1;
}

int main()
{
	LinkList* list = Init_LinkList();

	Stu s1 = {NULL, "aaa", 13};
	Stu s2 = { NULL, "bbb", 14 };
	Stu s3 = { NULL, "ccc", 15 };
	Stu s4 = { NULL, "ddd", 16 };
	Stu s5 = { NULL, "eee", 17 };

	// �������
	// Insert_LinkList(LinkList* list, int pos, LinkNode* dt);
	Insert_LinkList(list, 0, (LinkNode*)&s1);
	Insert_LinkList(list, 1, (LinkNode*)&s2);
	Insert_LinkList(list, 2, (LinkNode*)&s3);
	Insert_LinkList(list, 3, (LinkNode*)&s4);
	Insert_LinkList(list, 4, (LinkNode*)&s5);


	Print_LinkList(list, MyPrint);

	// int Find_LinkList(LinkList* list, LinkNode* dt, COMPARENODE compare)
	int pos = Find_LinkList(list, (LinkNode*)&s5, MyCompare);
	if (pos < 0) {
		cout << "�����ڸýڵ�" << endl;
	} else {
		cout << "�ýڵ��һ�γ��ֵ�λ�ã� " << pos << endl;
	}
	
	Destory_LinkList(list);
	
	return 0;
}