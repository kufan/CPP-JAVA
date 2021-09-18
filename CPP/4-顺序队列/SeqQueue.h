#pragma once

#define MAX_SIZE 1024

// 顺序队列
typedef struct SEQQUEUE {
	// 指针数组，数组 data 中只能保存 void* 类型的指针
	void* data[MAX_SIZE];
	
	int size;  // 记录数组中元素个数
}SeqQueue;

// 初始化队列
SeqQueue* Init_SeqQueue();

// 入队操作
int Push_SeqQueue(SeqQueue* queue, void* dt);

// 返回队首元素
void* Front_SeqQueue(SeqQueue* queue);

// 出队
int Pop_SeqQueue(SeqQueue* queue);

// 返回队列尾元素
void* Back_SeqQueue(SeqQueue* queue);

// 队列大小
int GetSize_SeqQueue(SeqQueue* queue);

// 清空队列
int Clear_SeqQueue(SeqQueue* queue);

// 销毁
int Destroy_SeqQueue(SeqQueue* queue);