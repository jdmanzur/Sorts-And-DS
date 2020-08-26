#ifndef LSTACK
#define LSTACK

typedef int list_type

typedef struct node{

    list_type data;
    struct node *next;

}node;

typedef node* Node;

typedef struct{

    int n_elementos;
    Node *node_pointer;

}LStack;


void create(LStack *stack);
void destroy(LStack *stack);
void push(LStack *stack, list_type *data);
void pop(LStack *stack);
void front(LStack *stack, list_type *data);
int is_empty(LStack *stack);
int size(LStack *stack);

#endif