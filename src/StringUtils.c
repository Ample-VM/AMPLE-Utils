#include "StringUtils.h"

#include <string.h>


bool AMPLE_Utils_StringUtils_Equal(void* str1, void* str2)
{
    return strcmp((const char*)str1, (const char*)str2) == 0;
}