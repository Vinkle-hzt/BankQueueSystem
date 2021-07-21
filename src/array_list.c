#include "array_list.h"
#include <stdlib.h>
#include <string.h>

array_list* al_create(int(*CompFunc)(const void*,const void*))
{
    array_list* al = malloc(sizeof(array_list));
    al->data = malloc(sizeof(void*) * AL_DEFAULT_SIZE);
    al->curSize = 0;
    al->maxSize = AL_DEFAULT_SIZE;
    return al;
}

void* al_at(array_list* al, int idx)
{
    return al->data[idx];
}

void al_push(array_list* al, void* val)
{
    if (al->curSize == al->maxSize)
        al_resize(al);
    al->data[al->curSize] = val;    
    al->curSize++;
}

void al_free(array_list* al)
{
    free(al->data);
    free(al);
}

void al_resize(array_list* al)
{
    void** tmp = al->data;
    al->data = malloc(sizeof(void*) * al->maxSize * 2);
    memcpy(al->data, tmp, sizeof(void*) * al->maxSize);
    al->maxSize *= 2;
    free(tmp);
}

void* al_pop(array_list* al, int idx)
{
    void* ret = al->data[idx];
    for (int i = idx + 1; i < al->curSize; i++)
        al->data[i-1] = al->data[i];
    al->curSize--;
    return ret;
}

void al_clean(array_list* al)
{
    al->curSize = 0;
}