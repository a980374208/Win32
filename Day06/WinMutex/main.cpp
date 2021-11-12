#include <Windows.h>
#include "iostream"

HANDLE g_hMutex;
using namespace std;


DWORD CALLBACK ThreadPor(LPVOID pParam) {
	while (1) {
		
		//printf("%s\n", (char*)pParam);
		WaitForSingleObject(g_hMutex, INFINITE);
		char* szText = (char*)pParam;
		for (int i = 0; i < strlen(szText); ++i) {
			printf("%c", szText[i]);
		}
		printf("\n");
		ReleaseMutex(g_hMutex);
		Sleep(125);
	}
}

DWORD CALLBACK ThreadPor1(LPVOID pParam) {
	while (1) {
		//printf("%s\n", (char*)pParam);
		WaitForSingleObject(g_hMutex, INFINITE);
		char* szText = (char*)pParam;
		for (int i = 0; i < strlen(szText); ++i) {
			printf("%c", szText[i]);
		}
		printf("\n");
		ReleaseMutex(g_hMutex);
		Sleep(100);
	}
}


int main() {
	g_hMutex = CreateMutex(nullptr, FALSE, nullptr);
	DWORD nId;
	char* szText = (char*)"*********";
	HANDLE hTre = CreateThread(NULL, 1, &ThreadPor, szText, 0, &nId);
	char* szText1 = (char*)"---------";
	HANDLE hTre1 = CreateThread(NULL, 1, &ThreadPor1, szText1, 0, &nId);
	
	getchar();
	CloseHandle(g_hMutex);

	return 0;
}