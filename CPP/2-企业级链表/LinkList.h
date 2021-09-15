#pragma once
 
// 先设计链表节点 -- 数据域交给用户去维护
typedef struct LINKNODE {
	struct LINKNODE* next;  // 指针域
}LinkNode;

// 设计链表起点
typedef struct LINKLIST {
	LinkNode head;  // 头节点
	int size;	    // 记录链表中节点个数
}LinkList;

// 设置打印函数的 函数指针类型
typedef void(*PRINTNODE)(LinkNode*);
// void(*PRINTNODE)(LinkNode*) a;
// void(*PRINTNODE)(LinkNode*) 可以简写为  PRINTNODE
// PRINTNODE a;  --> a 就是函数指针类型的变量，且天生是指针
// 而且 a 只能指向没有返回值，且只能有一个 LinkNode* 参数的函数


// 设置比较函数的 函数指针类型
typedef int(*COMPARENODE)(LinkNode*, LinkNode*);

// 初始化链表 -- 起始就是初始化 LinkList
LinkList* Init_LinkList();

// 插入操作
// 在链表 list 的 pos 位置，插入节点 dt
int Insert_LinkList(LinkList* list, int pos, LinkNode* dt);

// 删除操作
int Delete_LinkList(LinkList* list, int pos);

// 获得链表大小
int GetSize_LinkList(LinkList* list);

// 遍历链表
// 作为框架维护者，不知道链表中保存着什么类型的数据，所以不知道该如何打印
// 但是用户知道该如何打印数据，所以需要用户提供打印函数，我们反向调用(回调)
// 需要特别指定打印函数的格式 -- 借助设计函数指针类型的方式指定
// 最后通过函数指针的方式，调用打印函数
int Print_LinkList(LinkList* list, PRINTNODE print);

// 查找操作
// 在链表 list 中查找有一个一个节点的值跟 dt 相等
int Find_LinkList(LinkList* list, LinkNode* dt, COMPARENODE compare);

// 销毁链表
int Destory_LinkList(LinkList* list);