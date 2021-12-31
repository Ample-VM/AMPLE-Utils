#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "CList.h"



CList AMPLE_Utils_List_Initialize(uint32_t initialSize)
{
    if (initialSize == 0)
        return NULL;

    ListP* listToBeReturned = (ListP*)malloc(sizeof(ListP));
    if (!listToBeReturned)
        return NULL;

    listToBeReturned->ptrs = (void**)malloc(initialSize * sizeof(void*));
    if (!listToBeReturned->ptrs)
    {
        free(listToBeReturned);
        return NULL;
    }
    listToBeReturned->size = initialSize;
    listToBeReturned->used = 0;
    listToBeReturned->initialized = true;
    listToBeReturned->capacityLocked = false;

    return listToBeReturned;
}

bool AMPLE_Utils_List_InsertElement(CList list, void* element)
{
    if (!list)
        return false;

    ListP* lst = (ListP*)list;

    if (!lst->initialized)
        return false;

    if (lst->used >= lst->size)
    {
        if (lst->capacityLocked)
            return false;
        if (!AMPLE_Utils_List_Resize(lst, lst->size * 2))
            return false;
    }

    memcpy(&(lst->ptrs[lst->used]), &element, sizeof(void*));
    lst->used++;

    return true;
}

void* AMPLE_Utils_List_GetElement(CList list, uint32_t position)
{
    if (!list)
        return 0;

    ListP* lst = (ListP*)list;

    if (!lst->initialized)
        return 0;

    if (lst->used <= position)
        return NULL;

    return (lst->ptrs)[position];
}

bool AMPLE_Utils_List_Resize(CList list, uint32_t newSize)
{
    if (!list)
        return false;

    ListP* lst = (ListP*)list;

    if (!lst->initialized || lst->capacityLocked)
        return false;

    void** oldPtrs = lst->ptrs;
    lst->ptrs = (void**)realloc(lst->ptrs, newSize * sizeof(void*));
    if (!lst->ptrs)
    {
        lst->ptrs = oldPtrs;
        return false;
    }
    lst->size = newSize;

    return true;
}

uint32_t AMPLE_Utils_List_GetCapacity(CList list)
{
    if (!list)
        return 0;

    ListP* lst = (ListP*)list;

    if (!lst->initialized)
        return 0;

    return lst->size;
}

uint32_t AMPLE_Utils_List_GetSize(CList list)
{
    if (!list)
        return 0;

    ListP* lst = (ListP*)list;

    if (!lst->initialized)
        return 0;

    return lst->used;
}

bool AMPLE_Utils_List_ContainsValue(CList list, void* element, bool (*comparer)(void*, void*))
{
    if (!list)
        return false;

    ListP* lst = (ListP*)list;

    if (!lst->initialized)
        return false;

    uint32_t size = AMPLE_Utils_List_GetSize(list);

    for (int i = 0; i < size; i++)
    {
        if (comparer((lst->ptrs)[i], element))
            return true;
    }
    return false;
}

void AMPLE_Utils_List_LockCapacity(CList list)
{
    if (!list)
        return;

    ListP* lst = (ListP*)list;

    if (!lst->initialized)
        return;

    lst->capacityLocked = true;
}

void AMPLE_Utils_List_Free(CList list)
{
    if (!list)
        return;

    ListP* lst = (ListP*)list;

    if (!lst->initialized)
        return;

    if (lst->ptrs)
    {
        free(lst->ptrs);
        lst->ptrs = NULL;
    }

    lst->size = lst->used = 0;
    lst->initialized = lst->capacityLocked = false;
}