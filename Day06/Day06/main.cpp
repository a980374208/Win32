#include <Windows.h>
#include "iostream"

using namespace std;


DWORD CALLBACK ThreadPor(LPVOID pParam) {
	while (1) {
		printf("%s\n", (char*)pParam);
		Sleep(1000);
	}
}

DWORD CALLBACK ThreadPor1(LPVOID pParam) {
	while (1) {
		printf("%s\n", (char*)pParam);
		Sleep(1000);
	}
}


int main() {
	DWORD nId;
	char* szText = (char*)"*********";
	HANDLE hTre = CreateThread(NULL, 1, &ThreadPor, szText, 0, &nId);

	WaitForSingleObject(hTre, INFINITE);

	char* szText1 = (char*)"------------";
	HANDLE hTre1 = CreateThread(NULL, 1, &ThreadPor1, szText1, CREATE_SUSPENDED, &nId);
	getchar();
	
	SuspendThread(hTre);
	ResumeThread(hTre1);
	getchar();

	return 0;
}