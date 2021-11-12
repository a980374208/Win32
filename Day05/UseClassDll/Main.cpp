#include <iostream>
#include "../ClassDll/MyMath.h"
#pragma comment (lib,"../Day05/Debug/ClassDll.lib")

using namespace std;

int main() {
	MyMath myMath;
	int a, b, c;
	a = myMath.Add(4, 5);
	cout << "Add=" << a << endl;
	b= myMath.Mul(4, 5);
	cout << "Mul=" << b << endl;
	c = myMath.Sub(4, 5);
	cout << "Sub=" << c << endl;
	return 0;
}