#include "safe_free.h"

void safe_free(void* p)
{
    if (p)
    {
        free(p);
        p = NULL;
    }
}