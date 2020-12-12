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

#include "employee.h"

/* Return 1 if c is part of string s; 0 otherwise */
int is_in(char *s, char c[]);

DWORD VolumeValue(const int percentage) {
    // Clamp percentage value
    int p = std::min(100, std::max(0, percentage));
    // Calculate scaled value for one channel
    const WORD wVol = static_cast<WORD>(::MulDiv(65535, p, 100));
    // Construct return value for both channels
    const DWORD retVal = ((wVol << 16) | wVol);
    return retVal;
}

int main(void) {
    const CLSID CLSID_MMDeviceEnumerator = __uuidof(MMDeviceEnumerator);
    const IID IID_IMMDeviceEnumerator = __uuidof(IMMDeviceEnumerator);
    void* pEnumerator;
    HRESULT hr = CoCreateInstance(
            CLSID_MMDeviceEnumerator, NULL,
            CLSCTX_ALL, IID_IMMDeviceEnumerator,
            (void**)&pEnumerator);

    std::cout<<"%p "<<&pEnumerator;
    EDataFlow dataFlow;
    DWORD dwStateMask = DEVICE_STATE_ACTIVE;
    // Register the window class.
    const wchar_t CLASS_NAME[]  = L"Sample Window Class";

    WNDCLASS wc = { };
    HINSTANCE hInstance;
    HINSTANCE hPrevInstance;
    LPWSTR lpCmdLine;
    hInstance = GetModuleHandle(NULL);
    wc.lpfnWndProc   = DefWindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = (LPSTR)CLASS_NAME;
    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
            0,                              // Optional window styles.
            (LPSTR)CLASS_NAME,                     // Window class
            (LPSTR)"Speculation INS.",    // Window text
            WS_OVERLAPPEDWINDOW,            // Window style

            // Size and position
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

            NULL,       // Parent window
            NULL,       // Menu
            hInstance,  // Instance handle
            NULL        // Additional application data
    );

    if (hwnd == NULL)
    {
        return 0;
    }
    ShowWindow(hwnd, 1); UpdateWindow(hwnd);
    MSG msg;
    while (GetMessageW(&msg, NULL, 0, 0))
    {
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

int is_in(char *s, char c[]) {
    std::cout << " -~~ " << *s;
    while (*s)
        if (*s == c[0]) return 1;
        else s++;
    return 0;
}