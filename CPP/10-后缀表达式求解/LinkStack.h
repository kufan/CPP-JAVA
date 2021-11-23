#pragma once

#define LINKSTACK_TRUE  1
#define LINKSTACK_FALSE 0

// 链表节点
typedef struct STACKNODE {
	struct STACKNODE* next;
}StackNode;

// 链表的起点
typedef struct LINKSTACK {
	StackNode head;  // 链表的头
	int size;   // 标记链表大小
}LinkStack;

LinkStack* Init_Stack();

// 入栈操作：就是把 dt 这个元素，插入到链表的头部
int Push_LinkStack(LinkStack* stack, StackNode* dt);

// 返回栈顶元素
StackNode* Front_LinkStack(LinkStack* stack);

// 出栈操作 -- 删除第一个节点
int Pop_LinkStack(LinkStack* stack);

// 判断栈是否为空
int IsEmpty(LinkStack* stack);

// 获得栈中元素个数
int GetSize_LinkStack(LinkStack* stack);

// 清空
int Clear_LinkStack(LinkStack* stack);

// 销毁
int Destroy_LinkStack(LinkStack* stack);