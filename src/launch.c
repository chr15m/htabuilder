#define NOMINMAX
#define UNICODE
#include <windows.h>
#include <stdio.h>
#include <shlobj.h>
// #include "hta.h"

int main(void) {
    TCHAR cwd[MAX_PATH+1] = L"";
    DWORD len = GetCurrentDirectory(MAX_PATH, cwd);

    /*TCHAR homedir[MAX_PATH];
    SHGetFolderPath(NULL, CSIDL_PERSONAL | CSIDL_FLAG_CREATE, NULL, 0, homedir);*/

    // char* main_hta
    // int main_hta_len

    // buffer overflow here lol
    char cmd[len + 128];
    sprintf(cmd, "C:\\Windows\\System32\\mshta.exe %S\\src\\main.hta", cwd);

    return WinExec(cmd, 0);
}
