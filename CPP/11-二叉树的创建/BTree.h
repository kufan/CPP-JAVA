#pragma once
 
#include <cstdlib>
#include <cstdio>

#define BT_LEFT  0
#define BT_RIGHT 1

// 涉及二叉树的节点
typedef struct _TAG_BTREENODE {
	// 指针域
	struct _TAG_BTREENODE* left;   // 指向左子树的指针
	struct _TAG_BTREENODE* right;  // 指向右子树的指针
}BTreeNode;

// 涉及二叉树的起点
typedef struct _TAG_BTREE {
	BTreeNode* root;   // 始终指向根节点
	int size;    // 记录二叉树中节点个数
}TBTree;


// 指定打印函数的格式 -- 其实就是涉及 函数指针类型 的过程
typedef void(*BTREEPRINT)(BTreeNode*);
// void(*BTREEPRINT)(BTreeNode*) 当作整体，就是函数指针类型
// void(*BTREEPRINT)(BTreeNode*) a; 此时 a 就是一个 函数指针类型的变量,且 a 天生是指针
// void(*BTREEPRINT)(BTreeNode*) 可以简写为 BTREEPRINT
// BTREEPRINT a;
// a 只能指向没有返回值，且只有一个 BTreeNode* 类型的参数的函数


// 创建二叉树
TBTree* Init_BTree();

// 插入操作 在 tree 这棵树中，插入一个 dt 的节点
// pos 标记路径(二进制形式标记)，  cnt 走几步    flag 左/右
int Insert_BTree(TBTree* tree, BTreeNode* dt, unsigned int pos, int cnt, int flag); 

// 删除操作: 删除被 pos 和 cnt 确定出来的那个节点
BTreeNode* Delete_BTree(TBTree* tree, unsigned int pos, int cnt);

// 得到指定位置的节点
BTreeNode* GetNode_BTree(TBTree* tree, unsigned int pos, int cnt);

// 获得根节点
BTreeNode* Root_BTree(TBTree* tree);

// 获得树中节点个数
int GetSize_BTree(TBTree* tree);

// 计算树的高度
int Height_BTree(TBTree* tree);

// 计算树的度
int Degree_BTree(TBTree* tree);

// 二叉树的打印
// 不知道数据会是什么样子的，也就无法打印
// 因此此时需要用户提供一个打印函数供我们调用，这个函数就叫做 回调函数
// 为了可以顺利回调用户实现的打印函数，我们必须手动指定打印函数的格式
// 借助指定 函数指针类型 的方式指定的
int Display_BTree(TBTree* tree, BTREEPRINT pFunc, int gap, char div);

// 清空树
int Clear_BTree(TBTree* tree);

// 销毁树
int Destroy_BTree(TBTree* tree);