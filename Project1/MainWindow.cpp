#include <windows.h>
#include <stdio.h>

//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    MessageBox(hWnd, "WM_SYSCOMMAND", "Infor", MB_OK);
    switch (message) {
    case WM_DESTROY:
        MessageBox(hWnd, "WM_SYSCOMMAND", "Infor", MB_OK);
        PostQuitMessage(0);
        printf("Hello");
        break;
    case WM_COMMAND:
        printf("Hello");
        MessageBox(hWnd, "WM_SYSCOMMAND", "Infor", MB_OK);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}

int CALLBACK WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR    lpCmdLine,
    int       nCmdShow)
{
    WNDCLASS wc = { 0 };

    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = DefWindowProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = NULL;
    wc.hCursor = NULL;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "Main";
    RegisterClass(&wc);
    HWND hWnd = CreateWindowW(L"Main", L"window", WS_OVERLAPPEDWINDOW, 
        100, 100, 500, 500, nullptr, nullptr, NULL, nullptr);



   /* WNDCLASS wcex = { 0 };

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = DefWindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = NULL;
    wcex.hCursor = NULL;
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName =NULL;
    wcex.lpszClassName = "Child";
    RegisterClass(&wcex);

    HWND hChild1 = CreateWindowEx(0,"Child", "c1", WS_CHILD|WS_VISIBLE|WS_OVERLAPPEDWINDOW,
        0, 0, 200, 200, hWnd, nullptr, hInstance, nullptr);
    HWND hChild2 = CreateWindowEx(0, "Child", "c1", WS_CHILD | WS_VISIBLE | WS_OVERLAPPEDWINDOW,
        200, 0, 200, 200, hWnd, nullptr, hInstance, nullptr);*/

    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);
    MSG nMsg = { 0 };

    while (GetMessage(&nMsg, nullptr, 0, 0))
    {
        printf("Hello");
        TranslateMessage(&nMsg);
        DispatchMessage(&nMsg); //≈…∑¢œ˚œ¢
    }

    return 0;
}
