//Lista duplamente encadeada

void create(LDeck *deck){    
    //inicializa os valores de stack
    deck->n_elementos = 0;
    deck->front = NULL;
    deck->back = NULL;
}

void destroy(LDeck *deck){
    //muahaha destroy it all
    while(!is_empty(deck)){
        pop_front(deck);
    }
}

void push_back(LDeck *deck, list_type data){

    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;

    if(!is_empty(deck)){
        
        deck->back->next = new_node;        //o ultimo passa a apontar para o ultimo elemento inserido
        
        new_node->prev = deck->back;        //o anterior ao ultimo inserido passa a ser o ultimo
        new_node->next = NULL;

        deck->back = new_node;              //seta como ultimo o ultimo atual (elemento inserido)
           

    }else{

        new_node->prev = NULL;              //o elemento inserido nao tem anterior e nem prox
        new_node->prox = NULL;
        
        deck->front = new_node;             //o ponteiro para o primeiro aponta para o inserido
        deck->back = new_node;              //o ponteiro para o ultimo aponta para o inserido
    }
    
    deck->n_elementos++;


}

void push_front(LDeck *deck, list_type data){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;

    if(!is_empty(deck)){

        deck->front->prev = new_node;  //o primeiro passa a apontar para o inserido na frente que agora é o primeiro

        new_node->next = deck->front;       //o proximo do inserido passa a ser o antigo ultimo
        new_node->prev = NULL;

        deck->front = new_node;         //seta como primeiro o primeiro de verdade

    }else{

        new_node->prev = NULL;
        new_node->prox = NULL;

        deck->front = new_node;
        deck->back = new_node;

    }

    deck->n_elementos++;
}


void pop_front(LDeck *deck){
    //se não está vazia, remove o elemento do topo
    if(!is_empty(deck) && (size(deck) != 1)){
    
        Node *top = deck->front;    //recebe o pointeiro para o primeiro elemento, cria por cópia
        deck->front = top->next;    //coloca no primeiro o valor e pointeiro do segundo
        deck->front->prev = NULL;   //seta como nulo o anterior ao primeiro elemento
        free(top);                  //libera o primeiro
        deck->n_elementos--;        //diminui o numero de elementos
    
    }else if(size(deck) == 1){

        //back e front apontam para o mesmo elemento
        Node *top = deck->front;
        top->next = NULL;
        top->prev = NULL;
        
        //seta como nulo o ponteiro para o primeiro elemento, seu prox e seu anterior
        deck->front = top->next;
        //seta como nulo o ponteiro para o ultimo elemento, seu prox e seu anterior
        deck->back = top->next;
        
        free(top);
        deck->n_elementos--;
    }
}

void pop_back(LDeck *deck){
    //se não está vazia, remove o elemento do final
    if(!is_empty(deck) && (size(deck) != 1)){
    
        Node *top = deck->back;    //recebe o pointeiro para o ultimo elemento, cria por cópia
        deck->back = top->prev;    
        deck->back->next = NULL;   //seta como nulo o proximo ao ultimo elemento
        free(top);                  //libera o removido
        deck->n_elementos--;        //diminui o numero de elementos
    
    }else if(size(deck) == 1){

        //back e front apontam para o mesmo elemento
        Node *top = deck->back;

        top->prev = NULL;
        top->next = NULL;
        
        //seta como nulo o ponteiro para o primeiro elemento, seu prox e seu anterior
        deck->front = top->next;
        //seta como nulo o ponteiro para o ultimo elemento, seu prox e seu anterior
        deck->back = top->next;

        free(top);
        deck->n_elementos--;
    }
}

void front(LDeck *deck, list_type *data){    
    *data = deck->front->data; //atribui o valor do primeiro elemento para a variavel data
}

void back(LDeck *deck, list_type *data){
    *data = deck->back->data; //atribui o valor do ultimo elemento para a variavel data
}

int is_empty(LDeck *deck){
    return (deck->front == NULL) && (deck->back == NULL);
}

int size(LDeck *deck){
    return deck->n_elementos;
}