#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "CStack.h"

CStack AMPLE_Utils_Stack_Initialize()
{
    StackP* stackToBeReturned = (StackP*)malloc(sizeof(StackP*));
    if (!stackToBeReturned)
        return NULL;

    stackToBeReturned->ptrs = (void**)malloc(sizeof(void*));
    if (!stackToBeReturned->ptrs)
    {
        free(stackToBeReturned->ptrs);
        return NULL;
    }
    stackToBeReturned->size = 1;
    stackToBeReturned->top = 0;
    stackToBeReturned->ptrs[0] = NULL;

    return (CStack)stackToBeReturned;
}

bool AMPLE_Utils_Stack_InsertElement(CStack stack, void* element)
{
    if (!stack)
        return false;

    StackP* stck = (StackP*)stack;
    if (stck->top >= stck->size)
    {
        stck->ptrs = (void**)realloc(stck->ptrs, stck->size * 2 * sizeof(void*));
        if (!stck->ptrs)
            return false;
        stck->size *= 2;
    }

    stck->ptrs[stck->top++] = element;
    return true;
}

bool AMPLE_Utils_Stack_RemoveElement(CStack stack)
{
    if (!stack)
        return false;

    StackP* stck = (StackP*)stack;
    stck->top--;
    return true;
}

void* AMPLE_Utils_Stack_GetElement(CStack stack)
{
    if (!stack)
        return NULL;

    StackP* stck = (StackP*)stack;
    return stck->ptrs[stck->top - 1];
}

void AMPLE_Utils_Stack_Free(CStack stack)
{
    if (!stack)
        return;

    StackP* stck = (StackP*)stack;
    if (stck->ptrs)
    {
        free(stck->ptrs);
        stck->ptrs = NULL;
    }
    free(stck);
}
