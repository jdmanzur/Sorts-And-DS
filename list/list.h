//implementação de uma lista simples encadeada

#ifndef LIST
#define LIST

typedef int list_type

typedef struct node{

    list_type data;
    struct node *next;

}Node;

void create(Node *node_pointer);
void destroy(Node *node_pointer);
void push(Node *node_pointer, list_type *data);
void pop(Node *node_pointer);
void front(Node *node_pointer, list_type *data);
int is_empty(Node *node_pointer);
int search(Node *node_pointer, list_type data_to_search);

#endif