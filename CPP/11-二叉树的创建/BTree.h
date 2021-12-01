#pragma once
 
#include <cstdlib>
#include <cstdio>

#define BT_LEFT  0
#define BT_RIGHT 1

// �漰�������Ľڵ�
typedef struct _TAG_BTREENODE {
	// ָ����
	struct _TAG_BTREENODE* left;   // ָ����������ָ��
	struct _TAG_BTREENODE* right;  // ָ����������ָ��
}BTreeNode;

// �漰�����������
typedef struct _TAG_BTREE {
	BTreeNode* root;   // ʼ��ָ����ڵ�
	int size;    // ��¼�������нڵ����
}TBTree;


// ָ����ӡ�����ĸ�ʽ -- ��ʵ�����漰 ����ָ������ �Ĺ���
typedef void(*BTREEPRINT)(BTreeNode*);
// void(*BTREEPRINT)(BTreeNode*) �������壬���Ǻ���ָ������
// void(*BTREEPRINT)(BTreeNode*) a; ��ʱ a ����һ�� ����ָ�����͵ı���,�� a ������ָ��
// void(*BTREEPRINT)(BTreeNode*) ���Լ�дΪ BTREEPRINT
// BTREEPRINT a;
// a ֻ��ָ��û�з���ֵ����ֻ��һ�� BTreeNode* ���͵Ĳ����ĺ���


// ����������
TBTree* Init_BTree();

// ������� �� tree ������У�����һ�� dt �Ľڵ�
// pos ���·��(��������ʽ���)��  cnt �߼���    flag ��/��
int Insert_BTree(TBTree* tree, BTreeNode* dt, unsigned int pos, int cnt, int flag); 

// ɾ������: ɾ���� pos �� cnt ȷ���������Ǹ��ڵ�
BTreeNode* Delete_BTree(TBTree* tree, unsigned int pos, int cnt);

// �õ�ָ��λ�õĽڵ�
BTreeNode* GetNode_BTree(TBTree* tree, unsigned int pos, int cnt);

// ��ø��ڵ�
BTreeNode* Root_BTree(TBTree* tree);

// ������нڵ����
int GetSize_BTree(TBTree* tree);

// �������ĸ߶�
int Height_BTree(TBTree* tree);

// �������Ķ�
int Degree_BTree(TBTree* tree);

// �������Ĵ�ӡ
// ��֪�����ݻ���ʲô���ӵģ�Ҳ���޷���ӡ
// ��˴�ʱ��Ҫ�û��ṩһ����ӡ���������ǵ��ã���������ͽ��� �ص�����
// Ϊ�˿���˳���ص��û�ʵ�ֵĴ�ӡ���������Ǳ����ֶ�ָ����ӡ�����ĸ�ʽ
// ����ָ�� ����ָ������ �ķ�ʽָ����
int Display_BTree(TBTree* tree, BTREEPRINT pFunc, int gap, char div);

// �����
int Clear_BTree(TBTree* tree);

// ������
int Destroy_BTree(TBTree* tree);