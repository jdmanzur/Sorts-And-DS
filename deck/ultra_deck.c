void create(LOrd *deck){
    //allocs mem for sentinel
    Node *space = (Node *)malloc(sizeof(Node));
    //saves address for sentinel node
    deck->sentinel = space;
    deck->n_elementos = 0;
    //empty list condition
    deck->sentinel->next = deck->sentinel;
    deck->sentinel->prev = deck->sentinel;
}

void destroy(LOrd *deck){

    //pop each and every element including sentinel out of the list
    while(!is_empty(deck)){
        generic_pop(deck);
    }

    free(deck->sentinel);
    deck->n_elementos = 0;

}

void display(LOrd *deck){
    //displays the whole list by iterating through it using the sentinel
    if(!is_empty(deck)){

        Node *display = deck->sentinel->next;

        for(int i = 0; i < deck->n_elementos; i++){

            if(i){
                printf(" ");
            }

            printf("%d", display->data);

            display = display->next;

        }

        printf("\n");

    }

}

void push_and_order(LOrd *deck, list_type data){

    //sentinel receives the data that the user wants to insert
    deck->sentinel->data = data;

    //searches for a place to insert the data
    Node *search = deck->sentinel->next;

    //now that sentinel has the actual value of data, we
    //are certain that the while has a stop condition and that
    //in the worst case, we will insert at the end of the list
    while(search->data < deck->sentinel->data){
        search = search->next;
    }

    //inserts new node before the searched one
    Node *new = (Node *)malloc(sizeof(Node));

    new->next = search;
    new->prev = search->prev;

    search->prev->next = new;
    search->prev = new; 

    deck->n_elementos++;

}

void search_and_pop(LOrd *deck, list_type data){

    if(!is_empty(deck)){
        //sentinel receives the data that the user wants to insert
        deck->sentinel->data = data;

        //searches for a place to remove the data
        Node *search = deck->sentinel->next;

        do{


            //now that sentinel has the actual value of data, we
            //are certain that the while has a stop condition and that
            //in the worst case, we will remove from the end of the list
            while(search->data != deck->sentinel->data && search != deck->sentinel){
                search = search->next;
            }

            //removes the node it found
            Node *remove = search;
            //reassings pointers so that it removes the searched node
            search->prev->next = search->next;
            search->next->prev = search->prev;

            free(search);
            free(remove);

            deck->n_elementos--;

        }while(search->next->data == deck->sentinel->data && search != deck->sentinel);


    }

}

void generic_pop(LOrd *deck){
    //removes using the sentinel
    if(!is_empty(deck)){
        
        Node *remove = deck->sentinel->prev;

        deck->sentinel->prev = remove->prev;
        deck->sentinel->prev->next = deck->sentinel;

    }

    deck->n_elementos--;    


}
void front(LOrd *deck, list_type *data){
    *data = deck->sentinel->next->data;
}
void back(LOrd *deck, list_type *data){
    *data = deck->sentinel->prev->data;
}

int is_empty(LOrd *deck){
    return deck->sentinel->prev == deck->sentinel && deck->sentinel->next == deck->sentinel;
}

int size(LOrd *deck){
    return deck->n_elementos;
}