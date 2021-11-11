#include <windows.h>

//
void onPaint(HWND hWnd) {
    PAINTSTRUCT sPs;
    HDC hDc = BeginPaint(hWnd, &sPs);
    char szText[] = "Hello Text";
    SetTextColor(hDc, RGB(12, 68, 195));
    SetBkMode(hDc, TRANSPARENT);
    HFONT hFont = CreateFont(30,0,45,0,900,0,0,0,GB2312_CHARSET,0,0,0,0,"等线");
    HGDIOBJ hOldFont = SelectObject(hDc, hFont);


    TextOut(hDc, 100, 100, "Hello Text", strlen(szText));
    RECT rc;
    rc.left = 100;
    rc.top = 150;
    rc.right = 500;
    rc.bottom = 500;
    DrawText(hDc, szText, strlen(szText), &rc, DT_CENTER | DT_SINGLELINE);

    SelectObject(hDc, hOldFont);
    DeleteObject(hOldFont);
    EndPaint(hWnd, &sPs);
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message) {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_PAINT:
        onPaint(hWnd);
        break;
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
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
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
