#include <iostream>
#include <cstring>

using namespace std;

int main() {
	
	// void* memset(void* s, int c, size_t n);
	// ��ָ�� s ��ָ��ģ�n ���ֽڵĿռ䣬�����ֽڵķ�ʽ��ȫ����ʼ��Ϊ c
	// �����ֽڵķ�ʽ��ʼ��
	// ����������ʼ������
	// ����� char ���飬������
	// ����� ��char ���飬��ֻ�ܳ�ʼ��Ϊ 0/-1
	
	// char a[5] = {'a', 'b', 'c', 'd', 'e'}; --> �����ַ�����������ͨ��char����
	// char a[5] = {'a', 'b', 'c', 'd', '\0'}; --> ���ַ������ȼ��� "abcd"
	// �ַ���һ���� char ���飬�� char ���鲻һ�����ַ���
	//  
	
	/* 
	char a[5];
	memset(a, 'P', sizeof(a)); 
	 
	cout << "a = " << a << endl;  // ֻ���ַ�������ֱ�� cout ��ӡ 
	*/
	
	
	int a[5];
	
	// for(int i = 0; i < 5; i++) {
	//	cin >> a[i];
	//}
	
	// ���� a �е�ÿ���ֽڣ�ȫ����ʼ��Ϊ 1 
	memset(a, 1, sizeof(a));
	
	for(int i = 0; i < 5; i++) {
		cout << a[i] << " ";
	}
	
	return 0;
}
