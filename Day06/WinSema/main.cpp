#include <Windows.h>
#include <stdio.h>
HANDLE g_hSema;


DWORD CALLBACK ThreadProc(LPVOID lpParameter) {
	while (1) {
		WaitForSingleObject(g_hSema, INFINITE);
		printf("********************\n");
	}
	return 0;
}





using namespace std;
int main() {

	g_hSema = CreateSemaphore(nullptr, 3, 10, nullptr);

	DWORD ThID;
	HANDLE hThread = CreateThread(NULL, 0, ThreadProc, nullptr, 0, &ThID);
	getchar();
	ReleaseSemaphore(g_hSema, 9, nullptr);

	WaitForSingleObject(hThread, INFINITE);
	CloseHandle(g_hSema);
	return 0;



}