#include "Calc.h"

bool IsNum(char p) {
	// && --> �߼������������������Ҫô�棬Ҫô��
	// && �����ȼ�С�� >= �� <=
	// if �жϵ������棬���Ǽ�
	/*
	if(p >= '0' && p <= '9') {
		return true;
	} else {
		return false;
	}
	*/
	return p >= '0' && p <= '9';
}

int Caculate(int left, int right, char c) {
	int ans = 0;

	switch (c) {
	case '+':
		ans = left + right;
		break;
	case '-':
		ans = left - right;
		break;
	case '*':
		ans = left * right;
		break;
	case '/':
		ans = left / right;
		break;

	default:
		break;
	}

	return ans;
}