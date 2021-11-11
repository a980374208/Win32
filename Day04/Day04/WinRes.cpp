#include <windows.h>
#include "resource.h"

//
void onCommand(HWND hWnd, WPARAM wParam) {
    switch (LOWORD(wParam)) {
    case ID_New:
        MessageBox(hWnd, "新建被单机了", "Infor", MB_OK);
        break;
    case ID_Set:
        MessageBox(hWnd, "CTRL+N被单机了", "Infor", MB_OK);
        break;
    }

}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message) {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_COMMAND:
        onCommand(hWnd,  wParam);
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}

int CALLBACK WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR    lpCmdLine,
    int       nCmdShow)
{
    WNDCLASS wc = { 0 };
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = LoadCursor(hInstance, (char*)IDC_CURSOR1);
    wc.hIcon = LoadIcon(hInstance, (char*)IDI_ICON1);
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WndProc;
    wc.lpszClassName = "Main";
    wc.lpszMenuName = (char*)IDR_MENU1;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&wc);

    HWND hWnd = CreateWindowW(L"Main", L"window", WS_OVERLAPPEDWINDOW,
        100, 100, 500, 500, nullptr, nullptr, hInstance, nullptr);
    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);
    MSG nMsg = { 0 };
    
    HACCEL hAcctable = LoadAccelerators(hInstance, (char*)IDR_ACCELERATOR1);

    while (GetMessage(&nMsg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(hWnd, hAcctable, &nMsg)){
            TranslateMessage(&nMsg);
            DispatchMessage(&nMsg); //派发消息
        }
    }

    return 0;
}