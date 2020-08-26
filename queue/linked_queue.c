void create(LQueue *queue){    
    //inicializa os valores de stack
    queue->n_elementos = 0;
    queue->front = NULL;
    queue->back = NULL;
}

void destroy(LQueue *queue){
    //muahaha destroy it all
    while(!is_empty(queue)){
        pop(queue);
    }
}

void push(LQueue *queue, list_type data){

    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;

    if(!is_empty(queue)){

        queue->back->next = new_node;
        queue->back = new_node;
        queue->back->next = NULL;
        queue->n_elementos++;

    }else{
        queue->front = new_node;
        queue->back = new_node;
        queue->back->next = NULL;
        queue->n_elementos++;

    }


}


void pop(LQueue *queue){
    //se não está vazia, remove o elemento do topo
    if(!is_empty(queue) && (size(queue) != 1)){
    
        Node *top = queue->front;    //recebe o pointeiro para o primeiro elemento, cria por cópia
        queue->front = top->next;    //coloca no primeiro o valor e pointeiro do segundo
        free(top);                      //libera o primeiro
        queue->n_elementos--;                 //diminui o numero de elementos
    
    }else if(size(queue) == 1){

        //back e front apontam para o mesmo elemento
        Node *top = queue->front;
        queue->front = top->next;
        queue->back = top->next;
        free(top);
        queue->n_elementos--;
    }
}


void front(LQueue *queue, list_type *data){    
    *data = queue->front->data; //atribui o valor do primeiro elemento para a variavel data
}

int is_empty(LQueue *queue){
    return (queue->front == NULL) && (queue->back == NULL);
}

int size(LQueue *queue){
    return queue->n_elementos;
}