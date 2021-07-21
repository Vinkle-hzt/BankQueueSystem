#pragma once

typedef struct node
{
    void* data;
    struct node* pre;
    struct node* next;
} queue_node;

typedef struct
{
    queue_node* head;
    int size;
} queue;

queue* queue_create();