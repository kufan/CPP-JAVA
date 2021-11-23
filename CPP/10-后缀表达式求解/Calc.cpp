#include "Calc.h"

bool IsNum(char p) {
	// && --> 逻辑运算符，其运算结果，要么真，要么假
	// && 的优先级小于 >= 和 <=
	// if 判断到底是真，还是假
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