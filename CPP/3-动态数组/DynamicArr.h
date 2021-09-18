#pragma once

#define MYARRAY_TRUE  1
#define MYARRAY_FALSE 0

// ��ƶ�̬����
typedef struct DYNAMICARR {
	int* pAddr;  // ָ�� pAddr ��ָ����ǿ�ռ䣬�������������������ݵĿռ�
	int capacity;  // ��������
	int size;   // ��¼��ǰ������Ԫ�ظ���
}DynamicArr;

DynamicArr* Init_Arr(int len); 

// ����Ԫ��
// ������ arr ��pos λ�ò��� val Ԫ��
int Insert_Arr(DynamicArr* arr, int pos, int val);

// �ж������Ƿ�Ϊ��
int IsEmpty_Arr(DynamicArr* arr);

// ɾ������
// ɾ������ arr �е� pos λ�õ�Ԫ��
int DeleteByPos_Arr(DynamicArr* arr, int pos);

// Ѱ��ָ��Ԫ���������е�λ��
// Ѱ�� val �������е��±�
int Find_Arr(DynamicArr* arr, int val);

// ɾ��ָ��Ԫ��
int DeleteByVal_Arr(DynamicArr* arr, int val);

// ���������Ԫ�ظ���
int GetSize_Arr(DynamicArr* arr);

// �����������
int GetCapacity_Arr(DynamicArr* arr);

// �����±���Ԫ��
int At_Arr(DynamicArr* arr, int pos);

// ��������
int Print_Arr(DynamicArr* arr);

// ���
int Clear_Arr(DynamicArr* arr);

// ����
int Destory_Arr(DynamicArr* arr);