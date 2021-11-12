#include <iostream>
#include <Windows.h>

typedef int(*Count)(int a,int b);
typedef int(*Mul)(int a, int b);
typedef int(*Sul)(int a, int b);

using namespace std;

int main() {
	int a, b, c;
	HINSTANCE hDll = LoadLibrary("CppDll.dll");
	cout << "hDll=" << hDll << endl;
	Count myAdd = (Count)GetProcAddress(hDll, "CppDll_Add");
	cout << "myAdd=" << myAdd << endl;
	a = myAdd(4, 5);
	cout << "sum=" << a << endl;
	Count mySul = (Count)GetProcAddress(hDll, "?CppDll_Sul@@YAHHH@Z");
	cout <<"mySul="<< mySul << endl;
	b = mySul(4, 5);
	cout << "Sul=" << b << endl;
	Count myMul = (Count)GetProcAddress(hDll, "CppDll_Mul");
	cout << "myMul=" << myMul << endl;
	c = myMul(4, 5);
	cout <<"Mul="<< c << endl;
	FreeLibrary(hDll);
	return 0;
}