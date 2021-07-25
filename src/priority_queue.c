/**
 * @file priority_queue.c
 * @brief 优先队列类
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "priority_queue.h"

priority_queue *pq_create(int (*CompFunc)(const void *, const void *))
{
    priority_queue *pq = malloc(sizeof(priority_queue));
    pq->curSize = 0;
    pq->maxSize = PQ_DEFAULT_SIZE;
    pq->data = malloc(sizeof(void *) * PQ_DEFAULT_SIZE);
    pq->CompFunc = CompFunc;
    return pq;
}

void pq_resize(priority_queue *pq)
{
    void **tmp = pq->data;
    pq->data = malloc(sizeof(void*) * pq->maxSize * 2);
    memcpy(pq->data, tmp, sizeof(void *) * (pq->maxSize));
    pq->maxSize *= 2;
    free(tmp);
}

void pq_heapify(priority_queue *pq, int i)
{
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int largest = i;
    if (left < pq->curSize && pq->CompFunc(pq->data[left], pq->data[i]) > 0)
        largest = left;
    if (right < pq->curSize && pq->CompFunc(pq->data[right], pq->data[largest]) > 0)
        largest = right;
    if (largest != i)
    {
        swap(&pq->data[i], &pq->data[largest], sizeof(void *));
        pq_heapify(pq, largest);
    }
}

void pq_push(priority_queue *pq, void *elem)
{
    if (pq->curSize == pq->maxSize)
    {
        pq_resize(pq);
    }

    int i = pq->curSize;
    int fa = (i - 1) / 2;

    pq->data[i] = elem;

    while (i && pq->CompFunc(pq->data[fa], pq->data[i]) < 0)
    {
        swap(&pq->data[i], &pq->data[fa], sizeof(void *));
        i = fa;
        fa = (i - 1) / 2;
    }
    pq->curSize++;
}

void pq_pop(priority_queue *pq)
{
    pq->data[0] = pq->data[pq->curSize - 1];
    pq->curSize--;
    pq_heapify(pq, 0);
}

void *pq_top(priority_queue *pq)
{
    return pq->data[0];
}

void pq_free(priority_queue *pq)
{
    pq_clear(pq);
    safe_free(pq->data);
    safe_free(pq);
}

void pq_clear(priority_queue *pq)
{
    while(pq->curSize)
    {
        void* cur = pq_top(pq);
        pq_pop(pq);
        safe_free(cur);
    }
}