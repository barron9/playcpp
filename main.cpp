#include <cstdio>
//#include <curl/curl.h>
#include <iostream>
#include <cstring>
#include <ctime>
#include <windows.h>
#include <mmsystem.h>
#include <winbase.h>

#include <mmdeviceapi.h>
#include <advpub.h>
#include <aclui.h>
#include <commctrl.h>
#include "employee.h"

/* Return 1 if c is part of string s; 0 otherwise */
int is_in(char *s, char c[]);

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

DWORD VolumeValue(const int percentage) {
    // Clamp percentage value
    int p = std::min(100, std::max(0, percentage));
    // Calculate scaled value for one channel
    const WORD wVol = static_cast<WORD>(::MulDiv(65535, p, 100));
    // Construct return value for both channels
    const DWORD retVal = ((wVol << 16) | wVol);
    return retVal;
}
HWND hwndPB;
int main(void) {
    const CLSID CLSID_MMDeviceEnumerator = __uuidof(MMDeviceEnumerator);
    const IID IID_IMMDeviceEnumerator = __uuidof(IMMDeviceEnumerator);
    void *pEnumerator;
    HRESULT hr = CoCreateInstance(
            CLSID_MMDeviceEnumerator, NULL,
            CLSCTX_ALL, IID_IMMDeviceEnumerator,
            (void **) &pEnumerator);

    std::cout << "%p " << &pEnumerator;
    EDataFlow dataFlow;
    DWORD dwStateMask = DEVICE_STATE_ACTIVE;
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"Sample Window Class";
    HBRUSH windowBackgroundBrush;
    COLORREF windowBackgroundColor;
    windowBackgroundBrush = CreateSolidBrush(windowBackgroundColor);
    WNDCLASS wc = {};
    HINSTANCE hInstance;
    HINSTANCE hPrevInstance;
    LPWSTR lpCmdLine;
    hInstance = GetModuleHandle(NULL);
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = (LPSTR) CLASS_NAME;
    wc.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));;
    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
            0,                              // Optional window styles.
            (LPSTR) CLASS_NAME,                     // Window class
            (LPSTR) "",    // Window text
            (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU),            // Window style

            // Size and position
            CW_USEDEFAULT, CW_USEDEFAULT, 450, 100,

            NULL,       // Parent window
            NULL,       // Menu
            hInstance,  // Instance handle
            NULL        // Additional application datav
    );
   // HWND textbox = CreateWindow("STATIC", "ACTIVATE PRODUCT", WS_VISIBLE | WS_CHILD, 10, 0, 420, 20, hwnd,
                              //  NULL, NULL, NULL);
   // CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 10, 40, 420, 20, hwnd, NULL, NULL, NULL);
   // CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_PASSWORD, 10, 70, 420, 20, hwnd, NULL, NULL, NULL);
    // SendMessageA( textbox,WM_CTLCOLORSTATIC ,0,0);
     hwndPB =CreateWindowEx(0,PROGRESS_CLASS,(LPTSTR) NULL, WS_VISIBLE | WS_CHILD | WS_BORDER, 10, 0, 420, 20, hwnd, (HMENU)10000, NULL,NULL);
    CreateWindow("BUTTON", "Format Card", WS_VISIBLE | WS_CHILD | WS_BORDER, 10, 40, 420, 20, hwnd, (HMENU)10000, NULL,NULL);
    if (hwnd == NULL) {
        return 0;
    }
    ShowWindow(hwnd, 1);
    UpdateWindow(hwnd);
    MSG msg;
    static TCHAR szAppName[] = TEXT("error");
   // MessageBox(NULL, TEXT("Sending Failure. Please retry"), szAppName, MB_ICONERROR);
    while (GetMessageW(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return msg.wParam;

    /* IMMDeviceEnumerator *a =new IMMDeviceEnumerator() ;
     HRESULT hrr=  IMMDeviceEnumerator::EnumAudioEndpoints( dataFlow, dwStateMask, pEnumerator );*/
    //  waveOutSetVolume(NULL, VolumeValue(100));
    // mxcd.paDetails = &mxcdVolume;

    //  PlaySoundA((LPCSTR) "D:\\pp.wav", NULL, SND_FILENAME | SND_ASYNC);
    //  getchar();


    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    static HBRUSH hbrush = NULL;
    HDC hdcStatic = (HDC) wParam;
    switch (message) {
        default: {

            return DefWindowProc(hWnd, message, wParam, lParam);
        }
        case WM_COMMAND: {

            if (LOWORD(wParam) == 10000) {
                SendMessage(hwndPB, PBM_STEPIT, 0, 0);
               // MessageBox(hWnd, TEXT("no account found"), TEXT("AA"), 0);
                SendMessage(hwndPB, PBM_STEPIT, 0, 0);

            }
            break;
        }
        case WM_CREATE: {

        }

        case WM_CTLCOLORSTATIC: {

            SetTextColor(hdcStatic, RGB(0, 0, 0));
            SetBkColor(hdcStatic, RGB(255, 255, 255));

            if (!hbrush)
                hbrush = CreateSolidBrush(RGB(255, 255, 255));
            return (LRESULT) hbrush;
        }

    }

}


int is_in(char *s, char c[]) {
    std::cout << " -~~ " << *s;
    while (*s)
        if (*s == c[0]) return 1;
        else s++;
    return 0;
}