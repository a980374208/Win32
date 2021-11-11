#include <windows.h>
#include <stdio.h>

HANDLE g_hOutput = 0;
//
void OnTimer(HWND hWnd, WPARAM wParam) {
    char szText[256] = { 0 };
    sprintf_s(szText, "WM_TIMER:定时器ID=%d\n", wParam);
    WriteConsole(g_hOutput, szText, strlen(szText),nullptr,nullptr);
}



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message) {
    case WM_CREATE:
        SetTimer(hWnd, 1, 1000, NULL);
        SetTimer(hWnd, 2, 2000, NULL);
    case WM_TIMER:
        OnTimer(hWnd, wParam);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}

int CALLBACK WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR    lpCmdLine,
    int       nCmdShow)
{
    AllocConsole();
    g_hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    WNDCLASS wc = { 0 };
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = NULL;
    wc.hIcon = NULL;
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WndProc;
    wc.lpszClassName = "Main";
    wc.lpszMenuName = nullptr;
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