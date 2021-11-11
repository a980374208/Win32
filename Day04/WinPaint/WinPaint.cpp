#include <windows.h>
#include "resource.h"

HINSTANCE g_hInstance;
//
void DrawPit(HDC dc) {
    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 256; ++j) {
            SetPixel(dc, i, j, RGB(i, j, 0));
        }
    }

}
void DrawLine(HDC dc) {
    MoveToEx(dc, 100, 100, nullptr);//移动原点初始位0，0
    LineTo(dc, 300, 300);//画线段结束点调整为为原点
    LineTo(dc, 200, 300);
}
void DrawRect(HDC dc) {
    Rectangle(dc, 100, 100, 300, 300);
}
void DrawEll(HDC dc) {
    Ellipse(dc, 100, 200, 300, 400);
}
void DrawBmp(HDC dc) {
    HBITMAP hBmp = LoadBitmap(g_hInstance, (char*)IDB_BITMAP1);
    HDC hMemDc = CreateCompatibleDC(dc);
    HGDIOBJ hOldMemDC = SelectObject(hMemDc, hBmp);
    BitBlt(dc, 100, 100, 48, 48, hMemDc, 0, 0, SRCCOPY);
    StretchBlt(dc, 200, 200, 24, 24, hMemDc, 0, 0, 48, 48, SRCCOPY);

    SelectObject(hMemDc, hOldMemDC);
    DeleteDC(hMemDc);
    DeleteObject(hBmp);
}

void onPaint(HWND hWnd) {
    PAINTSTRUCT ps;
    HDC dc = BeginPaint(hWnd, &ps);
    

    HPEN hpen = CreatePen(PS_SOLID, 10, RGB(255, 0, 0));
    HGDIOBJ hOldPen = SelectObject(dc, hpen);

    //HBRUSH hBrush = CreateSolidBrush(RGB(0, 255, 0));
    //HBRUSH hBrush = CreateHatchBrush(HS_CROSS,RGB(0 , 255, 0));
    HGDIOBJ hBrush = GetStockObject(NULL_BRUSH);
    HGDIOBJ hOldPenBush = SelectObject(dc, hBrush);//系统仓库画刷无需销毁

    //DrawPit(dc);
    //DrawLine(dc);
    //DrawRect(dc);
    DrawEll(dc);
    DrawBmp(dc);

    SelectObject(dc, hOldPenBush);
    //DeleteObject(hBrush);//系统仓库画刷无需销毁

    SelectObject(dc, hOldPen);
    DeleteObject(hpen);
    EndPaint(hWnd, &ps);
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
    g_hInstance = hInstance;

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
