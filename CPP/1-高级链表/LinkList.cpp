#include <cstdlib>

#include "LinkList.h"


// 跟自定义头文件所对应的 cpp 文件中，实现声明的函数
// 初始化链表: 其实就是声明一个 LinkList 类型的变量
// 为了控制链表的生命周期，会把链表开辟在堆区
LinkList* Init_LinkList() {
	// 初始化链表
	LinkList* list = NULL;
	list = (LinkList*)malloc(sizeof(LinkList));
	if (NULL == list) {
		// 堆区空间开辟失败，系统会自动产生一个错误信息
		// 这个错误信息会被 perror() 函数捕获，打印出来
		perror("malloc ");
		return NULL;
	}

	// 初始化堆区这块空间
	list->head = (LinkNode*)malloc(sizeof(LinkNode));
	if (NULL == list->head) {
		perror("malloc ");
		return NULL;
	}

	// 头节点，不存储有效数据，所以头节点不当作有效节点去看待
	list->size = 0;

	// 初始化头节点
	list->head->data = NULL;  // 头节点中不存储有效数据
	list->head->next = NULL;  // 当前链表中没有有效数据
	
	return list;
}

// 在 list 所指向链表中的第 pos 位置插入一个 dt 指向的节点
int Insert_LinkList(LinkList* list, int pos, void* dt) {
	if (NULL == list) {
		return -1;
	}
	if (NULL == dt) {
		return -2;
	}
	if (pos < 0 || pos > list->size) {
		return -3;
	}

	// 单纯的 void* 类型的 dt 不能进入链表，必须是 LinkNode 才能进入链表
	// 把 dt 封装为一个 LinkNode 就行  -- 实际就是在堆区再开辟一块空间
	LinkNode* NewNode = (LinkNode*)malloc(sizeof(LinkNode));
	if (NULL == NewNode) {
		perror("malloc");
		return -4;
	}

	// 把 dt 封装去
	NewNode->data = dt;
	NewNode->next = NULL;
	

	// 将要执行插入操作
	// 1、确定插入点
	LinkNode* pCur = list->head;
	for (int i = 0; i < pos; i++) {
		pCur = pCur->next;
	}

	// 2、真正的插入操作
	NewNode->next = pCur->next;
	pCur->next    = NewNode;

	// 节点多一个，size++
	list->size++;  
	
	return 0;
}

// 删除链表中指定位置的节点
// 删除链表 list 中第 pos 位置的节点
int DeleteByPos_LinkList(LinkList* list, int pos) {
	if (NULL == list) {
		return -1;
	}
	if (pos < 0 || pos > list->size) {
		return -2;
	}

	// 第一步，确定删除点
	LinkNode* pCur = list->head;
	for (int i = 0; i < pos; i++) {
		pCur = pCur->next;
	}

	// 开始执行删除操作
	LinkNode* pDel = pCur->next;
	pCur->next = pDel->next;
	pDel->next = NULL;   // 可有可无

	// 记得释放堆区这块空间
	if (pDel != NULL) {
		free(pDel);
		pDel = NULL;
	}

	list->size--;

	return 0;
}

// 获取链表长度
int GetSize_LinkList(LinkList* list) {
	if (NULL == list) {
		return -1;
	}

	return list->size;
}

// 找出指定元素在链表中的位置
// 找出 dt 在链表中的位置,如果有多个，返回第一个 dt 的位置
int Find_LinkList(LinkList* list, void* dt) {
	if (NULL == list) {
		return -1;
	}
	if (NULL == dt) {
		return -2;
	}

	int idx = -3;
	LinkNode* pCur = list->head->next;
	for (int i = 0; i < list->size; i++) {
		if (pCur->data == dt) {
			idx = i;
			break;
		}

		pCur = pCur->next;
	}

	return idx;
}

// 返回链表中第一个节点的地址
void* Front_LinkList(LinkList* list) {
	if (NULL == list) {
		return NULL;
	}

	return list->head->next->data;
}

// print 是一个指针，且只能指向一个特定的函数
// 实际上 print 指针中保存的是 某个特定函数的 地址
// 函数名，就是该函数在内存中的地址(虚拟地址空间，PE结构/ELF结构)
int Print_LinkList(LinkList* list, PRINTLIST print) {
	if (NULL == list) {
		return -1;
	}
	if (NULL == print) {
		return -2;
	}

	LinkNode* pCur = list->head->next;
	while (pCur != NULL) {
		print(pCur->data);  // 远程调用用户实现的打印函数
		pCur = pCur->next;
	}

	return 0;
}

// 销毁链表
int Destory_LinkList(LinkList* list) {
	if (NULL == list) {
		return -1;
	}

	// 先销毁所有节点
	LinkNode* pCur  = list->head;
	LinkNode* pNext = NULL;

	while (pCur != NULL) {
		pNext = pCur->next;

		if (pCur != NULL) {
			free(pCur);
			pCur = NULL;
		}

		pCur = pNext;
	}

	list->size = 0;
	if (list != NULL) {
		free(list);
		list = NULL;
	}
	
	return 0;
}