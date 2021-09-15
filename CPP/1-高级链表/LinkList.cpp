#include <cstdlib>

#include "LinkList.h"


// ���Զ���ͷ�ļ�����Ӧ�� cpp �ļ��У�ʵ�������ĺ���
// ��ʼ������: ��ʵ��������һ�� LinkList ���͵ı���
// Ϊ�˿���������������ڣ�����������ڶ���
LinkList* Init_LinkList() {
	// ��ʼ������
	LinkList* list = NULL;
	list = (LinkList*)malloc(sizeof(LinkList));
	if (NULL == list) {
		// �����ռ俪��ʧ�ܣ�ϵͳ���Զ�����һ��������Ϣ
		// ���������Ϣ�ᱻ perror() �������񣬴�ӡ����
		perror("malloc ");
		return NULL;
	}

	// ��ʼ���������ռ�
	list->head = (LinkNode*)malloc(sizeof(LinkNode));
	if (NULL == list->head) {
		perror("malloc ");
		return NULL;
	}

	// ͷ�ڵ㣬���洢��Ч���ݣ�����ͷ�ڵ㲻������Ч�ڵ�ȥ����
	list->size = 0;

	// ��ʼ��ͷ�ڵ�
	list->head->data = NULL;  // ͷ�ڵ��в��洢��Ч����
	list->head->next = NULL;  // ��ǰ������û����Ч����
	
	return list;
}

// �� list ��ָ�������еĵ� pos λ�ò���һ�� dt ָ��Ľڵ�
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

	// ������ void* ���͵� dt ���ܽ������������� LinkNode ���ܽ�������
	// �� dt ��װΪһ�� LinkNode ����  -- ʵ�ʾ����ڶ����ٿ���һ��ռ�
	LinkNode* NewNode = (LinkNode*)malloc(sizeof(LinkNode));
	if (NULL == NewNode) {
		perror("malloc");
		return -4;
	}

	// �� dt ��װȥ
	NewNode->data = dt;
	NewNode->next = NULL;
	

	// ��Ҫִ�в������
	// 1��ȷ�������
	LinkNode* pCur = list->head;
	for (int i = 0; i < pos; i++) {
		pCur = pCur->next;
	}

	// 2�������Ĳ������
	NewNode->next = pCur->next;
	pCur->next    = NewNode;

	// �ڵ��һ����size++
	list->size++;  
	
	return 0;
}

// ɾ��������ָ��λ�õĽڵ�
// ɾ������ list �е� pos λ�õĽڵ�
int DeleteByPos_LinkList(LinkList* list, int pos) {
	if (NULL == list) {
		return -1;
	}
	if (pos < 0 || pos > list->size) {
		return -2;
	}

	// ��һ����ȷ��ɾ����
	LinkNode* pCur = list->head;
	for (int i = 0; i < pos; i++) {
		pCur = pCur->next;
	}

	// ��ʼִ��ɾ������
	LinkNode* pDel = pCur->next;
	pCur->next = pDel->next;
	pDel->next = NULL;   // ���п���

	// �ǵ��ͷŶ������ռ�
	if (pDel != NULL) {
		free(pDel);
		pDel = NULL;
	}

	list->size--;

	return 0;
}

// ��ȡ������
int GetSize_LinkList(LinkList* list) {
	if (NULL == list) {
		return -1;
	}

	return list->size;
}

// �ҳ�ָ��Ԫ���������е�λ��
// �ҳ� dt �������е�λ��,����ж�������ص�һ�� dt ��λ��
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

// ���������е�һ���ڵ�ĵ�ַ
void* Front_LinkList(LinkList* list) {
	if (NULL == list) {
		return NULL;
	}

	return list->head->next->data;
}

// print ��һ��ָ�룬��ֻ��ָ��һ���ض��ĺ���
// ʵ���� print ָ���б������ ĳ���ض������� ��ַ
// �����������Ǹú������ڴ��еĵ�ַ(�����ַ�ռ䣬PE�ṹ/ELF�ṹ)
int Print_LinkList(LinkList* list, PRINTLIST print) {
	if (NULL == list) {
		return -1;
	}
	if (NULL == print) {
		return -2;
	}

	LinkNode* pCur = list->head->next;
	while (pCur != NULL) {
		print(pCur->data);  // Զ�̵����û�ʵ�ֵĴ�ӡ����
		pCur = pCur->next;
	}

	return 0;
}

// ��������
int Destory_LinkList(LinkList* list) {
	if (NULL == list) {
		return -1;
	}

	// ���������нڵ�
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