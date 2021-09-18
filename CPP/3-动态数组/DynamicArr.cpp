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

// 插入元素
// 给数组 arr 的pos 位置插入 val 元素
int Insert_Arr(DynamicArr* arr, int pos, int val) {
	if (NULL == arr) {
		return -1;
	}
	if (pos < 0 || pos > arr->size) {
		return -2;
	}

	// 判断数组是否满了
	if (arr->size == arr->capacity) {
		// 需要扩容
		// 1、开辟一块更大的空间
		int* NewSpace = (int*)malloc(sizeof(int*) * arr->capacity * 2);
		if (NULL == NewSpace) {
			perror("malloc");
			return -3;
		}
		
		// 2、将旧空间中的数据，拷贝到新空间
		// void* memcpy(void* dest, const void* src, size_t n);
		memcpy(NewSpace, arr->pAddr, sizeof(int)*arr->capacity);
		
		// 3、释放旧空间
		if (arr->pAddr != NULL) {
			free(arr->pAddr);
			arr->pAddr = NULL;
		}
		
		// 4、更新容量、链接新空间
		arr->pAddr = NewSpace;
		arr->capacity = arr->capacity * 2;
	}

	// 执行插入操作
	// 从插入点开始，所有元素依次后移一个单位
	for (int i = arr->size - 1; i >= pos; i--) {
		arr->pAddr[i + 1] = arr->pAddr[i];
	}

	// 执行插入操作
	arr->pAddr[pos] = val;
	arr->size++;

	return 0;
}

// 判断数组是否为空
int IsEmpty_Arr(DynamicArr* arr) {
	if (NULL == arr) {
		return -1;
	}

	// 为空 --> 真
	if (arr->size == 0) {
		return MYARRAY_TRUE;
	}	
	
	// 不为空 --> 假
	return MYARRAY_FALSE;
}

// 删除操作
// 删除数组 arr 中第 pos 位置的元素
int DeleteByPos_Arr(DynamicArr* arr, int pos) {
	if (NULL == arr) {
		return -1;
	}
	if (pos < 0 || pos > arr->size) {
		return -2;
	}

	// 执行删除操作
	for (int i = pos; i < arr->size; i++) {
		arr->pAddr[i] = arr->pAddr[i + 1];
	}
	arr->size--;

	return 0;
}

// 寻找指定元素在数组中的位置
// 寻找 val 在数组中的下标
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

// 删除指定元素
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

// 获得数组中元素个数
int GetSize_Arr(DynamicArr* arr) {
	if (NULL == arr) {
		return -1;
	}

	return arr->size;
}

// 获得数组容量
int GetCapacity_Arr(DynamicArr* arr) {
	if (NULL == arr) {
		return -1;
	}

	return arr->capacity;
}

// 根据下标获得元素
int At_Arr(DynamicArr* arr, int pos) {
	if (NULL == arr) {
		return -1;
	}
	if (pos < 0 || pos > arr->size) {
		return -2;
	}

	return arr->pAddr[pos];
}

// 遍历数组
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

// 清空
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

// 销毁
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