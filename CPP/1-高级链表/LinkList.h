#pragma once
// 防止重复编译

// 自定义头文件中:
// 1、类型声明
// 2、函数声明

// 设计节点
// 结构体全名: struct LINKNODE
// void* --> 万能指针，可以指向任意类型的数据
typedef struct LINKNODE {
	void* data;  // 数据域
	
	struct LINKNODE* next;   // 指针域
}LinkNode;
// 此时 LinkNode 就是  struct LINKNODE 的别名

// 链表的起点 -- 对头节点的简单包装
typedef struct LINKLIST {
	LinkNode* head;  // 指向头节点的指针

	int size;   // 记录链表中节点个数
}LinkList;


// 设计函数指针类型
typedef void(*PRINTLIST)(void*);
// void(*PRINTLIST)(void*) 就是类型，即 函数指针类型
// void(*PRINTLIST)(void*) a; 声明一个叫做 a 的 void(*PRINTLIST)(void*) 类型的变量
// void(*PRINTLIST)(void*) 可以简写为 PRINTLIST
// PRINTLIST a;  --> 声明了一个叫做  a 的 函数指针类型的变量
// 此时 a 天生是一个指针
// 且 a 只能指向没有返回值，只有一个  void* 类型参数的 函数


// 初始化链表: 其实就是声明一个 LinkList 类型的变量
LinkList* Init_LinkList();

// 在链表中插入一个元素
// 在 list 所指向链表中的第 pos 位置插入一个 dt 指向的节点
int Insert_LinkList(LinkList* list, int pos, void* dt);

// 删除链表中指定位置的节点
// 删除链表 list 中第 pos 位置的节点
int DeleteByPos_LinkList(LinkList* list, int pos);	 

// 获取链表长度
int GetSize_LinkList(LinkList* list);

// 找出指定元素在链表中的位置
// 找出 dt 在链表中的位置
int Find_LinkList(LinkList* list, void* dt);

// 返回链表中第一个节点的地址
void* Front_LinkList(LinkList* list);

// 打印链表中每个节点中保存的数据 -- 遍历链表
// 因为数据域是一个万能指针，所以在这个链表中，可以保存任意类型的数据
// 不知道链表中会保存什么类型的数据，所以作为框架提供者，我们不知道该如何打印这些数据
// 但是用户知道如何打印数据，所以我们要求用户提供一个 打印函数，我们反向调用(回调)
// 为了能顺利调用这个打印函数，我们必须规定打印函数的格式
// 借助设计  函数指针类型 的方式，指定打印函数的格式
// 同时，借助 函数指针类型的变量，反向调用打印函数
int Print_LinkList(LinkList* list, PRINTLIST print);

// 销毁链表
int Destory_LinkList(LinkList* list);