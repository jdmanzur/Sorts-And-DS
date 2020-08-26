
#ifndef LDECK
#define LDECK

typedef int list_type

typedef struct node{

    list_type data;
    struct node *next;
    struct node *prev;

}Node;

typedef struct{

    int n_elementos;
    Node *front;
    Node *back;

}LDeck;

void create(LDeck *deck);
void destroy(LDeck *deck);
push_front(LDeck *deck, list_type data);
void push_back(LDeck *deck, list_type data);
void pop_back(LDeck *deck);
void pop_front(LDeck *deck);
void front(LDeck *deck, list_type *data);
void back(LDeck *deck, list_type *data);
int is_empty(LDeck *deck);
int size(LDeck *deck);
#endif