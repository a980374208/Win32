#include <Windows.h>
#include <stdio.h>
HANDLE g_hEvent;


DWORD CALLBACK ThreadProc(LPVOID lpParameter) {
	while (1) {
		WaitForSingleObject(g_hEvent,INFINITE);
		ResetEvent(g_hEvent);
		printf("********************\n");
	}
	return 0;
}  

DWORD CALLBACK ThreadProc1(LPVOID lpParameter) {
	while (1) {
		Sleep(500);
		SetEvent(g_hEvent);
	}
	return 0;
}




using namespace std;
int main() {

	g_hEvent = CreateEvent(nullptr, TRUE, FALSE, nullptr);
	HANDLE hThread[2];
	DWORD ThID;
	hThread[0] = CreateThread(NULL, 0, ThreadProc, nullptr, 0, &ThID);
	hThread[1] = CreateThread(NULL, 0, ThreadProc1, nullptr, 0, &ThID);
	WaitForMultipleObjects(2, hThread, TRUE, INFINITE);
	return 0;



}