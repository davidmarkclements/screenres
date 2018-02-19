#ifdef WIN32
#include "headers.h"
#include "wtypes.h"

Resolution fetchRes() {
    Resolution r;
    RECT desktop;
    const HWND hDesktop = GetDesktopWindow();
    GetWindowRect(hDesktop, &desktop);
    r.width = desktop.right;
    r.height = desktop.bottom;
    return r;
}

int __cdecl changeRes(int horizontal, int vertical) {
    if (!horizontal || !vertical) {
        return ERR_MISSING_H_OR_V;
    }

    DEVMODE mode;
    ZeroMemory(&mode, sizeof(mode));
    mode.dmSize = sizeof(DEVMODE);
    mode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
    mode.dmPelsWidth = horizontal;
    mode.dmPelsHeight = vertical;
    long status = ChangeDisplaySettings(&mode, 0);
    return status;
}

#endif