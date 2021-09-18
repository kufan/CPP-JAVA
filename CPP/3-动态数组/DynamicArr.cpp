#include <cstdlib>
#include <cstring>
#include <cstdio>

#include "DynamicArr.h"


DynamicArr* Init_Arr(int len) {
	DynamicArr* arr = NULL;
	arr = (DynamicArr*)malloc(sizeof(DynamicArr));
	if (NULL == arr) {
		perror("malloc");
		return NULL;
	}

	arr->size     = 0;
	arr->capacity = len;

	arr->pAddr = (int*)malloc(sizeof(int) * len);
	if (arr->pAddr == NULL) {
		perror("malloc");
		return NULL;
	}

	// for (int i = 0; i < len; i++) {
	// 	arr->pAddr[i] = 0;
	// }

	memset(arr->pAddr, 0, sizeof(int)*len);
	
	return arr;
}

// ����Ԫ��
// ������ arr ��pos λ�ò��� val Ԫ��
int Insert_Arr(DynamicArr* arr, int pos, int val) {
	if (NULL == arr) {
		return -1;
	}
	if (pos < 0 || pos > arr->size) {
		return -2;
	}

	// �ж������Ƿ�����
	if (arr->size == arr->capacity) {
		// ��Ҫ����
		// 1������һ�����Ŀռ�
		int* NewSpace = (int*)malloc(sizeof(int*) * arr->capacity * 2);
		if (NULL == NewSpace) {
			perror("malloc");
			return -3;
		}
		
		// 2�����ɿռ��е����ݣ��������¿ռ�
		// void* memcpy(void* dest, const void* src, size_t n);
		memcpy(NewSpace, arr->pAddr, sizeof(int)*arr->capacity);
		
		// 3���ͷžɿռ�
		if (arr->pAddr != NULL) {
			free(arr->pAddr);
			arr->pAddr = NULL;
		}
		
		// 4�����������������¿ռ�
		arr->pAddr = NewSpace;
		arr->capacity = arr->capacity * 2;
	}

	// ִ�в������
	// �Ӳ���㿪ʼ������Ԫ�����κ���һ����λ
	for (int i = arr->size - 1; i >= pos; i--) {
		arr->pAddr[i + 1] = arr->pAddr[i];
	}

	// ִ�в������
	arr->pAddr[pos] = val;
	arr->size++;

	return 0;
}

// �ж������Ƿ�Ϊ��
int IsEmpty_Arr(DynamicArr* arr) {
	if (NULL == arr) {
		return -1;
	}

	// Ϊ�� --> ��
	if (arr->size == 0) {
		return MYARRAY_TRUE;
	}	
	
	// ��Ϊ�� --> ��
	return MYARRAY_FALSE;
}

// ɾ������
// ɾ������ arr �е� pos λ�õ�Ԫ��
int DeleteByPos_Arr(DynamicArr* arr, int pos) {
	if (NULL == arr) {
		return -1;
	}
	if (pos < 0 || pos > arr->size) {
		return -2;
	}

	// ִ��ɾ������
	for (int i = pos; i < arr->size; i++) {
		arr->pAddr[i] = arr->pAddr[i + 1];
	}
	arr->size--;

	return 0;
}

// Ѱ��ָ��Ԫ���������е�λ��
// Ѱ�� val �������е��±�
int Find_Arr(DynamicArr* arr, int val) {
	if (NULL == arr) {
		return -1;
	}

	int pos = -2;
	for (int i = 0; i < arr->size; i++) {
		if (arr->pAddr[i] == val) {
			pos = i;
			break;
		}
	}

	return pos;
}

// ɾ��ָ��Ԫ��
int DeleteByVal_Arr(DynamicArr* arr, int val) {
	if (NULL == arr) {
		return -1;
	}

	int pos = Find_Arr(arr, val);
	if (pos < 0) {
		return pos;
	} else {
		DeleteByPos_Arr(arr, pos);
		return 0;
	}
}

// ���������Ԫ�ظ���
int GetSize_Arr(DynamicArr* arr) {
	if (NULL == arr) {
		return -1;
	}

	return arr->size;
}

// �����������
int GetCapacity_Arr(DynamicArr* arr) {
	if (NULL == arr) {
		return -1;
	}

	return arr->capacity;
}

// �����±���Ԫ��
int At_Arr(DynamicArr* arr, int pos) {
	if (NULL == arr) {
		return -1;
	}
	if (pos < 0 || pos > arr->size) {
		return -2;
	}

	return arr->pAddr[pos];
}

// ��������
int Print_Arr(DynamicArr* arr) {
	if (NULL == arr) {
		return -1;
	}

	for (int i = 0; i < arr->size; i++) {
		printf("%d ", arr->pAddr[i]);
	}
	printf("\n");

	return 0;
}

// ���
int Clear_Arr(DynamicArr* arr) {
	if (NULL == arr) {
		return -1;
	}

	if (arr->pAddr != NULL) {
		memset(arr->pAddr, 0, sizeof(int)*arr->capacity);
	}
	arr->size = 0;

	return 0;
}

// ����
int Destory_Arr(DynamicArr* arr) {
	if (NULL == arr) {
		return -1;
	}

	if (arr->pAddr != NULL) {
		free(arr->pAddr);
		arr->pAddr = NULL;
	}

	if (arr != NULL) {
		free(arr);
		arr = NULL;
	}

	return 0;
}