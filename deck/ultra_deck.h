//Lista ordenada, dinâmicamente alocada, duplamente encadeada e circular com sentinela

#ifndef LORD
#define LORD

typedef int list_type

typedef struct node{

    list_type data;
    struct node *next;
    struct node *prev;

}Node;

typedef struct{

    int n_elementos;
    Node *sentinel; 

}LOrd;

void create(LOrd *deck);
void destroy(LOrd *deck);
void display(LOrd *deck);
void push_and_order(LOrd *deck, list_type data);
void search_and_pop(LOrd *deck, list_type data);
void front(LOrd *deck, list_type *data);
void back(LOrd *deck, list_type *data);
int is_empty(LOrd *deck);
int size(LOrd *deck);

#endif