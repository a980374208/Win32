#include <windows.h>
#include <stdio.h>

long g_lGlobe;

using namespace std;

DWORD CALLBACK ThreadProc1(LPVOID pParam) {
	for (int i = 0; i < 100000000; ++i) {
		//++g_lGlobe;
		InterlockedIncrement(&g_lGlobe);
	}
	printf("Thread1COUNT=%d\n", g_lGlobe);
	return 0;
}

DWORD CALLBACK ThreadProc2(LPVOID pParam) {
	for (int i = 0; i < 100000000; ++i) {
		//++g_lGlobe;
		InterlockedIncrement(&g_lGlobe);
	}
	printf("Thread2COUNT=%d\n", g_lGlobe);
	return 0;
}

int main() {
	DWORD pID = 0;
	HANDLE hThread[2];
	hThread[0] = CreateThread(NULL, 1, ThreadProc1, nullptr, 0, &pID);
	hThread[1] = CreateThread(NULL, 1, ThreadProc2, nullptr, 0, &pID);
	
	WaitForMultipleObjects(2, hThread, TRUE, INFINITE);
	printf("COUNT=%d\n", g_lGlobe);
	return 0;

}