#include <iostream>

#include "DynamicArr.h"

using namespace std;

int main()
{
	DynamicArr* arr = Init_Arr(20);

	// ��ʼ������Ԫ�ش�С
	cout << "����: " << GetCapacity_Arr(arr) << endl;
	cout << "��С: " << GetSize_Arr(arr) << endl;

	// ִ�в������
	for (int i = 0; i < 30; i++) {
		Insert_Arr(arr, i, i + 1);
	}

	Print_Arr(arr);

	cout << "�������֮������: " << GetCapacity_Arr(arr) << endl;
	cout << "�������֮���С: " << GetSize_Arr(arr) << endl;

	Destory_Arr(arr);
	
	return 0;
}