
#ifndef LQUEUE
#define LQUEUE

typedef int list_type

typedef struct node{

    list_type data;
    struct node *next;

}Node;

typedef struct{

    int n_elementos;
    Node *front;
    Node *back;

}LQueue;

void create(LQueue *queue);
void destroy(LQueue *queue);
void push(LQueue *queue, list_type data);
void pop(LQueue *queue);
void front(LQueue *queue, list_type *data);
int is_empty(LQueue *queue);
int size(LQueue *queue);
#endif