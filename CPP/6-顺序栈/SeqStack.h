#pragma once

#define MAX_SIZE 1024
#define SEQSTACK_TRUE  1
#define SEQSTACK_FALSE 0

// 设计栈
typedef struct SEQSTACK {
	// 指针数组,数组中元素必须指针，且数组中可以保存任意类型指针
	void* data[MAX_SIZE];
	int size;  // 记录数组中当前的元素个数
}SeqStack;

// 初始化栈
SeqStack* Init_Stack();

// 入栈
int Push_SeqStack(SeqStack* stack, void* dt);

// 获得栈顶元素
void* Front_SeqStack(SeqStack* stack);

// 出栈操作
int Pop_SeqStack(SeqStack* stack);

// 判断栈是否为空
int IsEmpty(SeqStack* stack);

// 获得栈中元素个数
int GetSize_SeqStack(SeqStack* stack);

// 清空栈
int Clear_SeqStack(SeqStack* stack);

// 销毁栈
int Destroy_SeqStack(SeqStack* stack);