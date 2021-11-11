#include <iostream>

#include "LinkQueue.h"

using namespace std;

/*
��������
	1����һ�����Խṹ
	2��ֻ�ܴӶ�β��ӣ�ֻ�ܴӶ�ͷ����
		�Ƚ��ȳ���������
	3�������е�����
		�޷��޸�
		�޷����� -- ����һ��������У��ͻ�̶�

��ʽ����
	1��ʹ������ģ�����
	2��ʹ�������ͷ��ģ���ͷ��ʹ�������β�� ģ���β
	3��Ϊ�˿��ٵ��������β��
		����ά��һ��ָ�룬��ָ��ʼ��ָ�������β��
*/

typedef struct STUDENT {
	QueueNode node;  // Ϊ��ά�������еĽڵ�

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

	// ��Ӳ���: ��ָ�� dt ��ָ��Ľڵ㣬���뵽����ĩβ(����ֻ�ܴӶ�β���)
	// int Push_LinkQueue(LinkQueue* queue, QueueNode* dt);
	Push_LinkQueue(queue, (QueueNode*)&s1);
	Push_LinkQueue(queue, (QueueNode*)&s2);
	Push_LinkQueue(queue, (QueueNode*)&s3);
	Push_LinkQueue(queue, (QueueNode*)&s4);
	Push_LinkQueue(queue, (QueueNode*)&s5);


	// ��ö�ͷԪ��
	// QueueNode* Front_LinkQueue(LinkQueue * queue);
	// QueueNode* Back_LinkQueue(LinkQueue * queue);
	Stu* head = (Stu*)Front_LinkQueue(queue);
	cout << "��ʼʱ����Ԫ��: name = " << head->name << ", age = " << head->age << endl;

	// ��ö�βԪ��
	Stu* R = (Stu*)Back_LinkQueue(queue);
	cout << "��ʼʱ��βԪ��: name = " << R->name << ", age = " << R->age << endl;

	cout << "\n���γ��Ӳ���:\n";
	while (GetSize_LinkQueue(queue) != 0) {
		Stu* h = (Stu*)Front_LinkQueue(queue);
		cout << "��ǰ��ͷ: name = " << h->name << ", age = " << h->age << endl;

		Pop_LinkQueue(queue); 
	}

	Destroy_LinkQueue(queue);
	
	return 0;
}