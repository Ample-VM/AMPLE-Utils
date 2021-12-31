#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

#define Library void*

Library* AMPLE_Utils_LibraryLoader_LoadOPCodeVersion(uint32_t Version);
Library* AMPLE_Utils_LibraryLoader_LoadLib(const char* LibraryName);
void* AMPLE_Utils_LibraryLoader_GetFuncFromLib(Library* Lib, const char* FunctionName);
void AMPLE_Utils_LibraryLoader_UnloadLib(Library* Lib);

#ifdef __cplusplus
}
#endif