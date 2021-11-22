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

// 识别 (
bool IsLeft(char c) {

	return c == '(';
}

// 识别 )
bool IsRight(char c) {
	return c == ')';
}

// 指出失配点所在
void ShowErr(char* str, int pos) {
	// :: 域运算符，指明某个工具属于哪个命名空间
	int a = 24;
	std::cout << str << std::endl;
	for (int i = 0; i < pos; i++) {
		std::cout << " ";
	}
	std::cout << (char)a << std::endl;
}