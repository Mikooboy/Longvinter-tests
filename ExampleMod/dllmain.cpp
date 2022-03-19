#include <windows.h>
#include "ExampleMod.h"
#include <thread>
//Mod* CoreMod;

ExampleMod* CoreMod;

void CreateMod()
{
    CoreMod = new ExampleMod();
}

DWORD WINAPI HookFunctions(LPVOID)
{
    bool health = false;
    while (1)
    {
        if (GetAsyncKeyState(VK_F4) & 1)
        {
            CoreMod->Test2();
        }
        else if (GetAsyncKeyState(VK_F3) & 1)
        {
            CoreMod->Test3();
        }
    }
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateMod();
        CreateThread(0, 0, HookFunctions, 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}