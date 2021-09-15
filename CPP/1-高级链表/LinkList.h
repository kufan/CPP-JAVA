#pragma once
// ��ֹ�ظ�����

// �Զ���ͷ�ļ���:
// 1����������
// 2����������

// ��ƽڵ�
// �ṹ��ȫ��: struct LINKNODE
// void* --> ����ָ�룬����ָ���������͵�����
typedef struct LINKNODE {
	void* data;  // ������
	
	struct LINKNODE* next;   // ָ����
}LinkNode;
// ��ʱ LinkNode ����  struct LINKNODE �ı���

// �������� -- ��ͷ�ڵ�ļ򵥰�װ
typedef struct LINKLIST {
	LinkNode* head;  // ָ��ͷ�ڵ��ָ��

	int size;   // ��¼�����нڵ����
}LinkList;


// ��ƺ���ָ������
typedef void(*PRINTLIST)(void*);
// void(*PRINTLIST)(void*) �������ͣ��� ����ָ������
// void(*PRINTLIST)(void*) a; ����һ������ a �� void(*PRINTLIST)(void*) ���͵ı���
// void(*PRINTLIST)(void*) ���Լ�дΪ PRINTLIST
// PRINTLIST a;  --> ������һ������  a �� ����ָ�����͵ı���
// ��ʱ a ������һ��ָ��
// �� a ֻ��ָ��û�з���ֵ��ֻ��һ��  void* ���Ͳ����� ����


// ��ʼ������: ��ʵ��������һ�� LinkList ���͵ı���
LinkList* Init_LinkList();

// �������в���һ��Ԫ��
// �� list ��ָ�������еĵ� pos λ�ò���һ�� dt ָ��Ľڵ�
int Insert_LinkList(LinkList* list, int pos, void* dt);

// ɾ��������ָ��λ�õĽڵ�
// ɾ������ list �е� pos λ�õĽڵ�
int DeleteByPos_LinkList(LinkList* list, int pos);	 

// ��ȡ������
int GetSize_LinkList(LinkList* list);

// �ҳ�ָ��Ԫ���������е�λ��
// �ҳ� dt �������е�λ��
int Find_LinkList(LinkList* list, void* dt);

// ���������е�һ���ڵ�ĵ�ַ
void* Front_LinkList(LinkList* list);

// ��ӡ������ÿ���ڵ��б�������� -- ��������
// ��Ϊ��������һ������ָ�룬��������������У����Ա����������͵�����
// ��֪�������лᱣ��ʲô���͵����ݣ�������Ϊ����ṩ�ߣ����ǲ�֪������δ�ӡ��Щ����
// �����û�֪����δ�ӡ���ݣ���������Ҫ���û��ṩһ�� ��ӡ���������Ƿ������(�ص�)
// Ϊ����˳�����������ӡ���������Ǳ���涨��ӡ�����ĸ�ʽ
// �������  ����ָ������ �ķ�ʽ��ָ����ӡ�����ĸ�ʽ
// ͬʱ������ ����ָ�����͵ı�����������ô�ӡ����
int Print_LinkList(LinkList* list, PRINTLIST print);

// ��������
int Destory_LinkList(LinkList* list);