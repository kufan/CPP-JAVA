#include <cstdlib>

#include "LinkList.h"

// 初始化链表
LinkList* Init_LinkList() {
	LinkList* list = NULL;

	list = (LinkList*)malloc(sizeof(LinkList));
	if (NULL == list) {
		perror("malloc");
		return NULL;
	}

	// 初始化堆区空间
	list->head.next = NULL;
	list->size      = 0;

	return list;
}

// 插入操作
// 在链表 list 的 pos 位置，插入节点 dt
int Insert_LinkList(LinkList* list, int pos, LinkNode* dt) {
	if (NULL == list) {
		return -1;
	}
	if (NULL == dt) {
		return -2;
	}
	if (pos < 0 || pos > list->size) {
		return -3;
	}

	// 确定插入点
	LinkNode* pCur = &(list->head);
	for (int i = 0; i < pos; i++) {
		pCur = pCur->next;
	}
	
	// 开始执行插入操作
	dt->next   = pCur->next;
	pCur->next = dt;

	list->size++;

	return 0;
}

// 删除操作
int Delete_LinkList(LinkList* list, int pos) {
	if (NULL == list) {
		return -1;
	}
	if (pos < 0 || pos > list->size) {
		return -2;
	}

	// 确定待删除节点
	LinkNode* pCur = &(list->head);
	for (int i = 0; i < pos; i++) {
		pCur = pCur->next;
	}

	// 此时 pCur 指向的是待删除节点的前驱节点
	pCur->next = pCur->next->next;

	list->size--;

	return 0;
}

// 获得链表大小
int GetSize_LinkList(LinkList* list) {
	if (NULL == list) {
		return -1;
	}
	
	return list->size;
}


// 遍历函数
int Print_LinkList(LinkList* list, PRINTNODE print) {
	if (NULL == list) {
		return -1;
	}

	LinkNode* pCur = list->head.next;
	while (pCur != NULL) {
		print(pCur);
		pCur = pCur->next;
	}

	return 0;
}

// 在链表 list 中查找有一个一个节点的值跟 dt 相等
int Find_LinkList(LinkList* list, LinkNode* dt, COMPARENODE compare) {
	if (NULL == list) {
		return -1;
	}
	if (NULL == dt) {
		return -2;
	}
	if (NULL == compare) {
		return -3;
	}

	LinkNode* pCur = list->head.next;
	int idx = -4;
	for (int i = 0; i < list->size; i++) {
		if (compare(pCur, dt) == 0) {
			idx = i;
			break;
		}

		pCur = pCur->next;
	}

	return idx;
}

// 销毁链表
int Destory_LinkList(LinkList* list) {
	if (NULL == list) {
		return -1;
	}
	
	if (list != NULL) {
		free(list);
		list = NULL;
	}

	return NULL;
}