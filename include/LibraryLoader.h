#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

#define Library void*

Library* LoadOPCodeVersion(uint32_t Version);
Library* LoadLib(const char* LibraryName);
void* GetFuncFromLib(Library* Lib, const char* FunctionName);
void UnloadLib(Library* Lib);

#ifdef __cplusplus
}
#endif