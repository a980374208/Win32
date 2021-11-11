#include <windows.h>
#include <stdio.h>
#include "resource.h"

HINSTANCE g_hINstance = 0;

void onCreate(HWND hWnd) {
    HMENU hMenu = LoadMenu(g_hINstance, (char*)IDR_MENU1);
    SetMenu(hWnd, hMenu);
}
void onCommand(HWND hWnd, WPARAM wParam) {
    switch (LOWORD(wParam)) {
    case ID_NEW:
        MessageBox(hWnd, "新建被单击", "Infor", MB_OK);
        break;
    case ID_Exit:
        MessageBox(hWnd, "退出被单击", "Infor", MB_OK);
        break;
    case ID_About:
        MessageBox(hWnd, "关于被单击", "Infor", MB_OK);
        break;
    }
}

//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message) {
    
    case WM_DESTROY:
        PostQuitMessage(0);
        //ONBUTTONDOWN(hWnd, wParam, lParam);
        break;
    case WM_CREATE:
        onCreate(hWnd);
        break;
    case WM_COMMAND:
        onCommand( hWnd,  wParam);
    }
    
    return DefWindowProc(hWnd, message, wParam, lParam);
}

int CALLBACK WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR    lpCmdLine,
    int       nCmdShow)
{
    g_hINstance = hInstance;

    WNDCLASS wc = { 0 };
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = NULL;
    wc.hIcon = NULL;
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WndProc;
    wc.lpszClassName = "Main";
    wc.lpszMenuName = nullptr/*(char*)IDR_MENU1*/;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&wc);

    //HMENU hMenu= LoadMenu(hInstance, (char*)IDR_MENU1);
    HWND hWnd = CreateWindowW(L"Main", L"window", WS_OVERLAPPEDWINDOW,
        100, 100, 500, 500, nullptr, nullptr/*hMenu*/, hInstance, nullptr);
    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);
    MSG nMsg = { 0 };

    while (GetMessage(&nMsg, nullptr, 0, 0))
    {
        TranslateMessage(&nMsg);
        DispatchMessage(&nMsg); //派发消息
    }

    return 0;
}