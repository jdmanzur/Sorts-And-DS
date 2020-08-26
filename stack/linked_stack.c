
void create(LStack *stack){
    //inicializa os valores de stack
    stack->n_elementos = 0;
    stack->node_pointer = NULL;
}

void destroy(LStack *stack){
    while(!is_empty(stack)){
        pop(stack);
    }
}

void push(LStack *stack, list_type data){
    //insere um novo nó e reatribui o ponteiro para o primeiro elemento
    Node *new_node = (Node *)malloc(sizeof(Node)); //aloca um nó na memoria para inserir um elemento
    new_node->data = data;                          //insere o elemento
    new_node->next = stack->node_pointer;           //passa para o ponteiro proximo do nó o primeiro anterior
    stack->node_pointer = new_node;    //recebe o endereço do novo nó
    stack->n_elementos++;
}

void pop(LStack *stack){
    //se não está vazia, remove o elemento do topo
    if(!is_empty(stack)){
        Node *top = stack->node_pointer;    //recebe o pointeiro para o primeiro elemento, cria por cópia
        stack->node_pointer = top->next;    //coloca no primeiro o valor e pointeiro do segundo
        free(top);                      //libera o primeiro
        stack->n_elementos--;                 //diminui o numero de elementos
    }


}

void front(LStack *stack, list_type *data){
    *data = stack->node_pointer->data; //atribui o valor do primeiro elemento para a variavel data

}

int is_empty(LStack *stack){
    return stack->node_pointer == NULL;
}

int size(LStack *stack){
    return stack->n_elementos;
}