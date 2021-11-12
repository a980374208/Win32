#include <iostream>
#pragma comment(lib,"../Day05/Debug/CppDll.lib")

_declspec(dllimport) int CppDll_Add(int a, int b);
_declspec(dllimport) int CppDll_Mul(int a, int b);
_declspec(dllimport) int CppDll_Sul(int a, int b);


using namespace std;
int main() {
	int a, b, c;
	a = CppDll_Add(5, 4);
	b = CppDll_Mul(5, 4);
	c = CppDll_Sul(5, 4);
	printf("sum=%d,Sub=%d\n", a, b);

	return 0;
}