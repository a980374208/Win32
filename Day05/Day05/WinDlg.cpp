#include <windows.h>
#include "resource.h"

HINSTANCE g_hInstance;

int CALLBACK DlgPrc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_SYSCOMMAND:
        if (wParam == SC_CLOSE) {
            EndDialog(hWnd, 100);
        }
        break;
    }
    return FALSE;
}

int CALLBACK Dlg2Prc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_SYSCOMMAND:
        if (wParam == SC_CLOSE) {
            DestroyWindow(hWnd);
        }
        break;
    }
    return FALSE;
}
//
void onCommand(HWND hWnd, WPARAM wParam) {
    switch (LOWORD(wParam)) {
    case ID_MODEL:
        /*int nRet = */DialogBox(g_hInstance, (char*)IDD_DIALOG1, hWnd, DlgPrc);
        //if (nRet == 100)//nRect接收EndDialog返回的值
           // MessageBox(hWnd, "Successed", "Info", MB_OK);
    case ID_NONMODAL:
        HWND hDiaWnd = CreateDialog(g_hInstance, (char*)IDD_DIALOG2, hWnd, Dlg2Prc);
        ShowWindow(hDiaWnd, SW_SHOW);
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
        onCommand(hWnd, wParam);
        break;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}

int CALLBACK WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR    lpCmdLine,
    int       nCmdShow)
{
    g_hInstance = hInstance;

    WNDCLASS wc = { 0 };
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = NULL;
    wc.hIcon = NULL;
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

    while (GetMessage(&nMsg, nullptr, 0, 0))
    {
        TranslateMessage(&nMsg);
        DispatchMessage(&nMsg); //派发消息
    }

    return 0;
}