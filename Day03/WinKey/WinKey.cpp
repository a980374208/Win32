#include <windows.h>
#include <stdio.h>
HANDLE g_hOutput = 0;
void OnKeyDown(HWND hWnd,WPARAM wParam) {
    char pszText[256] = { 0 };
    sprintf_s(pszText, "WM_KEYDOWN:键码值=%d\n", wParam);
    WriteConsole(g_hOutput, pszText, strlen(pszText), nullptr, nullptr);
}

void OnKeyUp(HWND hWnd, WPARAM wParam) {
    char pszText[256] = { 0 };
    sprintf_s(pszText, "WM_KEYUP:键码值=%d\n", wParam);
    WriteConsole(g_hOutput, pszText, strlen(pszText), nullptr, nullptr);
}

//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message) {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_KEYUP:
        OnKeyUp(hWnd, wParam);
        break;
    case WM_KEYDOWN:
        OnKeyDown(hWnd, wParam);
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