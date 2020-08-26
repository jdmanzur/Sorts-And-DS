
//iniciar
void inicializa( Lista* l, int (*compara)( Item i1, Item i2)){
    No* no = (No *)malloc(sizeof(No));
    l->sentinela = no;
    l->compara = compara;

}
//destruir
void destroi(Lista* l){
    while(!vazia(l)){
        remove(l);
    }
    
    free(l->sentinela);
    
}
//ve se ta vazia 
int vazia(Lista* l){
    return l->sentinela->ant == l->sentinela;
}
//item do comeco 
Item inicio(Lista* l){
    if(!vazia(l)){
        return l->sentinela->prox->item;
    }
}
//item do final
Item final(Lista* l){
    if(!vazia(l)){
        return l->sentinela->ant->item;
    }
}
//inserir ordenado
void insere(Lista* l, Item i){
    
    No *search = l->sentinela->prox;
    //sentinel receives the data that the user wants to insert
    l->sentinela->item = i;
    //searches for a place to insert the data

    //now that sentinel has the actual value of data, we
    //are certain that the while has a stop condition and that
    //in the worst case, we will insert at the end of the list
    while(compara(search->item, l->sentinela->item) == -1){
        search = search->prox;
    }

    //inserts new node before the searched one
    No *new = (No *)malloc(sizeof(No));
    

    new->prox = search;
    new->ant = search->ant;

    search->ant->prox = new;
    search->ant = new; 

    new->item = item;
}
//remove todos os iguais
void retira(Lista* l, Item i){ 
    
    if(!vazia(l)){

        //searches for a place to remove the data
        No *search = l->sentinela->prox;


        while(search != l->sentinela){

            if(compara(search->item, i) == 0 ){
                //now that sentinel has the actual value of data, we
                //are certain that the while has a stop condition and that
                //in the worst case, we will remove from the end of the list
            
                //removes the node it found
                No *remove = search;
                

                //reassings pointers so that it removes the searched node
                search->prox->ant = search->ant;
                search->ant->prox = search->prox;

                search = search->prox;
                free(remove);
                

            }else{
                search = search->prox;

            }

        }

    }
}

void remove(Lista* l){
    
    if(!vazia(deck)){
        
        No *remove = l->sentinela->ant;

        l->sentinela->ant = remove->ant;
        l->sentinela->ant->prox = l->sentinela;
    }

}
//seta o primeiro
Iterador primeiro(Lista* l){
    Iterador it = l->sentinela->prox;
    it->l = l;
    return it;
}
//seta o ultimo
Iterador ultimo(Lista* l){
    Iterador it = l->sentinela->ant;
    it->l = l;
    return it;
} 



int elementov(Iterador it, Item* i){
    if(!acabou(it)){
        *i = it->no->item;
        return 1;
    }
    return 0;
}
Item elemento(Iterador it){
    if(!acabou(it)){
        return it->no->item;
    }
}
//faz o iterador ir pro proximo
int proximo(Iterador* it){
    if(it->prox != it->l){
        it = it->no->prox;
    }else{
        it->no = NULL;
    }
}
//faz o iterador ir pro anterior
int anterior(Iterador* it){
    if(it->ant != it->l){
        it = it->no->ant;
    }else{
        it->no = NULL;
    }
}
//ve se o iterador acabou
int acabou(Iterador it){
    return it->no == NULL;
}
