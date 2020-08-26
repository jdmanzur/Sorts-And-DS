typedef struct{
    list_type data;
}Item;

typedef struct {
    Item item;
    struct node *prox;
    struct node *ant;

}No;

typedef struct{

    No *sentinela;
    int (*compara)(Item i1, Item i2);

}Lista;

typedef struct{
    No* no;
    Lista* l;

}Iterador;



//iniciar
void inicializa( Lista* l, int (*compara)( Item i1, Item i2)); 
//destruir
void destroi(Lista* l);
//ve se ta vazia 
int vazia(Lista* l);
//item do comeco 
Item inicio(Lista* l);
//item do final
Item final(Lista* l); 
//inserir ordenado
void insere(Lista* l, Item i);
//remove todos os iguais
void retira(Lista* l, Item i);
//seta o primeiro? 
Iterador primeiro(Lista* l); 
//seta o ultimo?
Iterador ultimo(Lista* l); 
//escreve em i oq ta em interador
int elementov(Iterador it, Item* i);
//retorna o elemento pra qual o iterador aponta
Item elemento(Iterador it); 
//faz o iterador ir pro proximo
int proximo(Iterador* it); 
//faz o iterador ir pro anterior
int anterior(Iterador* it); 
//ve se o iterador acabou
int acabou(Iterador it);
