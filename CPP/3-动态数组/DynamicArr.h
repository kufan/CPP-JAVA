#pragma once

#define MYARRAY_TRUE  1
#define MYARRAY_FALSE 0

// 设计动态数组
typedef struct DYNAMICARR {
	int* pAddr;  // 指针 pAddr 所指向的那块空间，就是真正用来保存数据的空间
	int capacity;  // 保存容量
	int size;   // 记录当前数组中元素个数
}DynamicArr;

DynamicArr* Init_Arr(int len); 

// 插入元素
// 给数组 arr 的pos 位置插入 val 元素
int Insert_Arr(DynamicArr* arr, int pos, int val);

// 判断数组是否为空
int IsEmpty_Arr(DynamicArr* arr);

// 删除操作
// 删除数组 arr 中第 pos 位置的元素
int DeleteByPos_Arr(DynamicArr* arr, int pos);

// 寻找指定元素在数组中的位置
// 寻找 val 在数组中的下标
int Find_Arr(DynamicArr* arr, int val);

// 删除指定元素
int DeleteByVal_Arr(DynamicArr* arr, int val);

// 获得数组中元素个数
int GetSize_Arr(DynamicArr* arr);

// 获得数组容量
int GetCapacity_Arr(DynamicArr* arr);

// 根据下标获得元素
int At_Arr(DynamicArr* arr, int pos);

// 遍历数组
int Print_Arr(DynamicArr* arr);

// 清空
int Clear_Arr(DynamicArr* arr);

// 销毁
int Destory_Arr(DynamicArr* arr);