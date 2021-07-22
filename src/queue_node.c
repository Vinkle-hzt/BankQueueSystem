#include "queue_node.h"

queue_node* queue_node_create(void* val, queue_node* pre, queue_node* next)
{
    queue_node* qn = malloc(sizeof(queue_node));
    qn->data = val;
    qn->pre = pre;
    qn->next = next;
    return qn;
}

void queue_node_free(queue_node* qn)
{
    safe_free(qn->data);
    safe_free(qn);
}