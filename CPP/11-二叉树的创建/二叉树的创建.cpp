#include <iostream>
#include <cstdio>

#include "BTree.h"

using namespace std;

typedef struct NODE {
	BTreeNode head;

	char v;
}Node;

// typedef void(*BTREEPRINT)(BTreeNode*);
void Print_Node(BTreeNode* dt) {
	Node* n = (Node*)dt;

	printf("%c", n->v);
}

int main()
{
	TBTree* tree = Init_BTree();

	// 创建节点
	Node s1 = {{NULL, NULL}, 'A'};
	Node s2 = {{NULL, NULL}, 'B'};
	Node s3 = {{NULL, NULL}, 'C'};
	Node s4 = {{NULL, NULL}, 'D'};
	Node s5 = {{NULL, NULL}, 'E'};
	Node s6 = {{NULL, NULL}, 'F'};


	// 插入树中
	// int Insert_BTree(TBTree* tree, BTreeNode* dt, unsigned int pos, int cnt, int flag); 
	Insert_BTree(tree, (BTreeNode*)&s1, 0, 0, 0);
	Insert_BTree(tree, (BTreeNode*)&s2, 0x00, 1, 0);
	Insert_BTree(tree, (BTreeNode*)&s3, 0x01, 1, 1);
	Insert_BTree(tree, (BTreeNode*)&s4, 0x00, 2, 0);
	Insert_BTree(tree, (BTreeNode*)&s5, 0x02, 2, 1);
	Insert_BTree(tree, (BTreeNode*)&s6, 0x02, 3, 0);

	// int Display_BTree(TBTree* tree, BTREEPRINT pFunc, int gap, char div);
	Display_BTree(tree, Print_Node, 4, '-');

	cout << "节点个数: " << GetSize_BTree(tree) << endl;
	cout << "树的高: " << Height_BTree(tree) << endl;
	cout << "树的度: " << Degree_BTree(tree) << endl;


	// BTreeNode* Delete_BTree(TBTree* tree, unsigned int pos, int cnt);
	cout << "\n删除 E 节点：\n";
	Delete_BTree(tree, 0x02, 2);

	Display_BTree(tree, Print_Node, 4, '-');
	
	cout << "节点个数: " << GetSize_BTree(tree) << endl;
	cout << "树的高: " << Height_BTree(tree) << endl;
	cout << "树的度: " << Degree_BTree(tree) << endl;


	
	Destroy_BTree(tree);
	
	return 0;
}