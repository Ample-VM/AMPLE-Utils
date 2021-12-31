#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

#include "AMPLE.h"

typedef struct
{
    uint32_t size;
    void** ptrs;
    uint32_t top;
} StackP;

#define CStack void*

CStack AMPLE_Utils_Stack_Initialize();

bool AMPLE_Utils_Stack_InsertElement(CStack stack, void* element);
bool AMPLE_Utils_Stack_RemoveElement(CStack stack);

void* AMPLE_Utils_Stack_GetElement(CStack stack);
INLINE void* AMPLE_Utils_Stack_FastGetElement(CStack stack)
{
    return ((StackP*)stack)->ptrs[((StackP*)stack)->top - 1];
}

void AMPLE_Utils_Stack_Free(CStack stack);


#ifdef __cplusplus
}
#endif