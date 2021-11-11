#include <windows.h>
int WinMain(HINSTANCE hins, HINSTANCE hPreIne, LPSTR IpCmdLine, 
                       int nCmdShow){
           MessageBox(NULL,"hello world", "Information",
                                  MB_YESNOVANCEL|MB_ICONERROR);
          return 0;
}