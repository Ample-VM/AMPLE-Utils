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
    void** ptrs;
    uint32_t size;
    uint32_t used;
    bool initialized;
    bool capacityLocked;
} ListP;

#define CList void*

CList AMPLE_Utils_List_Initialize(uint32_t initialSize);

bool AMPLE_Utils_List_InsertElement(CList list, void* element);

void* AMPLE_Utils_List_GetElement(CList list, uint32_t position);
INLINE void* AMPLE_Utils_List_FastGetElement(CList list, uint32_t position)
{
    if (((ListP*)list)->used <= position)
        return NULL;

    return (((ListP*)list)->ptrs)[position];
}

bool AMPLE_Utils_List_Resize(CList list, uint32_t newSize);

uint32_t AMPLE_Utils_List_GetCapacity(CList list);
uint32_t AMPLE_Utils_List_GetSize(CList list);

bool AMPLE_Utils_List_ContainsValue(CList list, void* element, bool (*comparer)(void*, void*));

void AMPLE_Utils_List_LockCapacity(CList list);

void AMPLE_Utils_List_Free(CList list);

#ifdef __cplusplus
}
#endif