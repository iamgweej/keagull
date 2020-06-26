#include "include/keagull/new.h"

void *__cdecl operator new(size_t size, void *ptr)
{
    size = size;
    return ptr;
}
