#include <iostream>
#include <cstring>

using namespace std;

int main() {
	
	// void* memset(void* s, int c, size_t n);
	// 把指针 s 所指向的，n 个字节的空间，按照字节的方式，全部初始化为 c
	// 按照字节的方式初始化
	// 经常用来初始化数组
	// 如果是 char 数组，则随意
	// 如果是 非char 数组，则只能初始化为 0/-1
	
	// char a[5] = {'a', 'b', 'c', 'd', 'e'}; --> 不是字符串，仅仅普通是char数组
	// char a[5] = {'a', 'b', 'c', 'd', '\0'}; --> 是字符串，等价于 "abcd"
	// 字符串一定是 char 数组，但 char 数组不一定是字符串
	//  
	
	/* 
	char a[5];
	memset(a, 'P', sizeof(a)); 
	 
	cout << "a = " << a << endl;  // 只有字符串可以直接 cout 打印 
	*/
	
	
	int a[5];
	
	// for(int i = 0; i < 5; i++) {
	//	cin >> a[i];
	//}
	
	// 数组 a 中的每个字节，全部初始化为 1 
	memset(a, 1, sizeof(a));
	
	for(int i = 0; i < 5; i++) {
		cout << a[i] << " ";
	}
	
	return 0;
}
