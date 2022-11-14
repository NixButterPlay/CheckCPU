// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <cryptopp/cpu.h>
using namespace CryptoPP;
#define dllexport __declspec(dllexport)
EXTERN_C
{
    dllexport bool CheckSSE42()
    {
            if (CryptoPP::g_hasSSE42)
            {
                return true;
            }

         else
         {
            return false;
         }

    }

   dllexport int CPUIDCheck()
   {
       int cpuid = 0;
       word32 cpuid_1{};
       word32 cpuid_2{};
       bool cpuid_checked = CpuId(cpuid_1, cpuid_2, 0);
       cpuid = (int)cpuid_checked;
       return cpuid;
   }
   dllexport bool DetectSSE41()
   {
       if (CryptoPP::HasSSE41()) {
           return true;
       }
       else {
        return false;
       }

   }

}
   


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

