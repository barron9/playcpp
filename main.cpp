#include <cstdio>
//#include <curl/curl.h>
#include <iostream>
#include <cstring>
#include <ctime>
#include <windows.h>
#include <mmsystem.h>
#include <winbase.h>
#include <initguid.h>
#include <mmdeviceapi.h>
#include "combaseapi.h"
#include <advpub.h>
#include <aclui.h>
#include <commctrl.h>
#include <functiondiscoverykeys_devpkey.h>
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
    int deviceCount=3;
    LPWSTR wstrID = NULL;
  //  DWORD state = NULL;
    const CLSID CLSID_MMDeviceEnumerator = __uuidof(MMDeviceEnumerator);
    const IID IID_IMMDeviceEnumerator = __uuidof(IMMDeviceEnumerator);
    void *pEnumerator;
    IMMDeviceCollection *pDevices;
    IMMDeviceEnumerator *pEnum = NULL;
    IMMDevice *pDevice;
    CoInitialize(NULL);
    HRESULT hr0 = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator),(void **) &pEnum);
    if(hr0 != 0){
        std::cout<< hr0 ;
    }else{
        std::cout << "S_OK";
    }

    HRESULT hrr = pEnum->EnumAudioEndpoints(eAll, DEVICE_STATE_ACTIVE, &pDevices);
    if(hrr != 0){
        std::cout << "error";
    }else{
        std::cout << "S_OK";
    }

    IPropertyStore *pProps = NULL;
    pDevices->Item(deviceCount, &pDevice);
    pDevice->GetId(&wstrID);
  //  pDevice->GetState(&state);
    hrr = pDevice->OpenPropertyStore(STGM_READ, &pProps);
    PROPVARIANT varName;
    // Initialize container for property value.
    PropVariantInit(&varName);

    static PROPERTYKEY key;


    // Get the endpoint's friendly-name property.

    hrr = pProps->GetValue(
            PKEY_Device_FriendlyName, &varName);
    if(hrr==0){
        std::wcout << varName.pwszVal;
    }

    return 0;
}


int is_in(char *s, char c[]) {
    std::cout << " -~~ " << *s;
    while (*s)
        if (*s == c[0]) return 1;
        else s++;
    return 0;
}