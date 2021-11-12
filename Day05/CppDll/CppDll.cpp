
/*_declspec(dllexport) */int CppDll_Add(int a, int b) {
	return a + b;
}

/*_declspec(dllexport) */int CppDll_Mul(int a, int b) {
	return a * b;
}

_declspec(dllexport) int CppDll_Sul(int a, int b) {
	return a - b;
}