#include <iostream>

#include "DynamicArr.h"

using namespace std;

int main()
{
	DynamicArr* arr = Init_Arr(20);

	// 初始容量和元素大小
	cout << "容量: " << GetCapacity_Arr(arr) << endl;
	cout << "大小: " << GetSize_Arr(arr) << endl;

	// 执行插入操作
	for (int i = 0; i < 30; i++) {
		Insert_Arr(arr, i, i + 1);
	}

	Print_Arr(arr);

	cout << "插入操作之后容量: " << GetCapacity_Arr(arr) << endl;
	cout << "插入操作之后大小: " << GetSize_Arr(arr) << endl;

	Destory_Arr(arr);
	
	return 0;
}