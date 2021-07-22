#include "queue.h"

queue* queue_create()
{
    queue* q = malloc(sizeof(queue));
    q->head = malloc(sizeof(queue_node));
    q->head->pre = q->head;
    q->head->next = q->head;
    q->size = 0;
    return q;
}

void queue_push(queue*q, void* val)
{
    queue_node* cur = queue_node_create(val, q->head->pre, q->head);
    q->head->pre->next = cur;
    q->head->pre = cur;
    q->size++;
}

void* queue_pop(queue*q)
{
    if (q->size == 0)
        return NULL;

    queue_node* cur = q->head->next;
    q->head->next = cur->next;
    cur->next->pre = q->head;

    q->size--;

    return cur;
}

void queue_free(queue*q)
{
    while(q->size)
    {
        void* val = queue_pop(q);
        safe_free(val);
    }
    safe_free(q->head);
    safe_free(q);
}