#include "match.h"

// using namespace std;

MyChar* CreateMyChar(char* p, int pos) {
	MyChar* mychar = NULL;
	mychar = (MyChar*)malloc(sizeof(MyChar));
	if (mychar == NULL) {
		perror("malloc: ");
		return NULL;
	}

	mychar->pAddr = p;
	mychar->index = pos;

	return mychar;
}

// ʶ�� (
bool IsLeft(char c) {

	return c == '(';
}

// ʶ�� )
bool IsRight(char c) {
	return c == ')';
}

// ָ��ʧ�������
void ShowErr(char* str, int pos) {
	// :: ���������ָ��ĳ�����������ĸ������ռ�
	int a = 24;
	std::cout << str << std::endl;
	for (int i = 0; i < pos; i++) {
		std::cout << " ";
	}
	std::cout << (char)a << std::endl;
}