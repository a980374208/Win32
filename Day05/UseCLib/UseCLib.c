#pragma comment(lib,"../Day05/Debug/CLib.lib")
#include <stdio.h>

int main() {
	int a, b;
	a = CLib_Add(5, 4);
	b = CLib_Sub(5, 4);
	printf("sum=%d,Sub=%d", a, b);
	return 0;

}
