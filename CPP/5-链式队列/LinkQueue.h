#pragma once

// 设计链表节点
typedef struct QUEUENODE {
	struct QUEUENODE* next;  // 指针域，始终直线下一个节点的指针
}QueueNode;

// 设计链表的起点
typedef struct LINKQUEUE {
	QueueNode head;  // 链表的头节点
	int size;  // 记录链表中节点个数 -- 队列中元素个数
	QueueNode* rear;  // 该指针会始终指向链表尾节点 -- 始终指向队列尾部
}LinkQueue;

// 初始化队列
LinkQueue* Init_LinkQueue();

// 入队操作: 把指针 dt 所指向的节点，插入到链表末尾(数据只能从队尾入队)
int Push_LinkQueue(LinkQueue* queue, QueueNode* dt);

// 获得队头元素
QueueNode* Front_LinkQueue(LinkQueue* queue);

// 获得队尾元素
QueueNode* Back_LinkQueue(LinkQueue* queue);

// 出队操作: 删除队列中第一个节点(区别于头节点)
int Pop_LinkQueue(LinkQueue* queue);

// 获得队列大小
int GetSize_LinkQueue(LinkQueue* queue);

// 清空队列
int Clear_LinkQueue(LinkQueue* queue);

// 销毁队列
int Destroy_LinkQueue(LinkQueue* queue);