#pragma comment(lib,"../Day05/Debug/CppLib.lib")
//���ϸ�������
#include <stdio.h>
int CppLib_Add(int a, int b);
int CppLib_Mul(int a, int b);
//���ϸ�������

#pragma comment(lib,"../Day05/Debug/CLib.lib")
extern "C" int CLib_Add(int a, int b);//C++�ڱ���ʱ�������ȡ����C�������Ե���C��̬��ʱ���extern "C" 
extern "C" int CLib_Sub(int a, int b);

using namespace std;
int main() {
	int a, b;
	a = CppLib_Add(5, 4);
	b = CppLib_Mul(5, 4);
	printf("sum=%d,Sub=%d", a, b);
	a = CLib_Add(5, 4);//?CLib_Add@@YAHHH@Z   
	b = CLib_Sub(5, 4);//?CLib_Sub@@YAHHH@Z
	printf("sum=%d,Sub=%d", a, b);
	return 0;
}