#include <cstdlib>

#include "LinkList.h"

// ��ʼ������
LinkList* Init_LinkList() {
	LinkList* list = NULL;

	list = (LinkList*)malloc(sizeof(LinkList));
	if (NULL == list) {
		perror("malloc");
		return NULL;
	}

	// ��ʼ�������ռ�
	list->head.next = NULL;
	list->size      = 0;

	return list;
}

// �������
// ������ list �� pos λ�ã�����ڵ� dt
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

	// ȷ�������
	LinkNode* pCur = &(list->head);
	for (int i = 0; i < pos; i++) {
		pCur = pCur->next;
	}
	
	// ��ʼִ�в������
	dt->next   = pCur->next;
	pCur->next = dt;

	list->size++;

	return 0;
}

// ɾ������
int Delete_LinkList(LinkList* list, int pos) {
	if (NULL == list) {
		return -1;
	}
	if (pos < 0 || pos > list->size) {
		return -2;
	}

	// ȷ����ɾ���ڵ�
	LinkNode* pCur = &(list->head);
	for (int i = 0; i < pos; i++) {
		pCur = pCur->next;
	}

	// ��ʱ pCur ָ����Ǵ�ɾ���ڵ��ǰ���ڵ�
	pCur->next = pCur->next->next;

	list->size--;

	return 0;
}

// ��������С
int GetSize_LinkList(LinkList* list) {
	if (NULL == list) {
		return -1;
	}
	
	return list->size;
}


// ��������
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

// ������ list �в�����һ��һ���ڵ��ֵ�� dt ���
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

// ��������
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