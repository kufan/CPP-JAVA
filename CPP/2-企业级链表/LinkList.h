#pragma once
 
// ���������ڵ� -- �����򽻸��û�ȥά��
typedef struct LINKNODE {
	struct LINKNODE* next;  // ָ����
}LinkNode;

// ����������
typedef struct LINKLIST {
	LinkNode head;  // ͷ�ڵ�
	int size;	    // ��¼�����нڵ����
}LinkList;

// ���ô�ӡ������ ����ָ������
typedef void(*PRINTNODE)(LinkNode*);
// void(*PRINTNODE)(LinkNode*) a;
// void(*PRINTNODE)(LinkNode*) ���Լ�дΪ  PRINTNODE
// PRINTNODE a;  --> a ���Ǻ���ָ�����͵ı�������������ָ��
// ���� a ֻ��ָ��û�з���ֵ����ֻ����һ�� LinkNode* �����ĺ���


// ���ñȽϺ����� ����ָ������
typedef int(*COMPARENODE)(LinkNode*, LinkNode*);

// ��ʼ������ -- ��ʼ���ǳ�ʼ�� LinkList
LinkList* Init_LinkList();

// �������
// ������ list �� pos λ�ã�����ڵ� dt
int Insert_LinkList(LinkList* list, int pos, LinkNode* dt);

// ɾ������
int Delete_LinkList(LinkList* list, int pos);

// ��������С
int GetSize_LinkList(LinkList* list);

// ��������
// ��Ϊ���ά���ߣ���֪�������б�����ʲô���͵����ݣ����Բ�֪������δ�ӡ
// �����û�֪������δ�ӡ���ݣ�������Ҫ�û��ṩ��ӡ���������Ƿ������(�ص�)
// ��Ҫ�ر�ָ����ӡ�����ĸ�ʽ -- ������ƺ���ָ�����͵ķ�ʽָ��
// ���ͨ������ָ��ķ�ʽ�����ô�ӡ����
int Print_LinkList(LinkList* list, PRINTNODE print);

// ���Ҳ���
// ������ list �в�����һ��һ���ڵ��ֵ�� dt ���
int Find_LinkList(LinkList* list, LinkNode* dt, COMPARENODE compare);

// ��������
int Destory_LinkList(LinkList* list);