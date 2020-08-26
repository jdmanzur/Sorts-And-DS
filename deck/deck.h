//DOUBLE ENDED QUEUE -DECK-  API
#ifndef DECK
#define DECK
#define MAX 1000

typedef int deck_type;

typedef struct{
    deck_type v[MAX];
    int def_max;
    int front;
    int back;
    int size;   //you can remove this variable by using a sentinel, avoinding that back collides with front when the queue is full
}Deck;

//initializes front, back and size as 0
void initialize(Deck *deck_pointer, int max);
//checks if deck is empty
int is_empty(Deck *deck_pointer);
//checks if deck is full
int is_full(Deck *deck_pointer);
//returns deck size
int size(Deck *deck_pointer);
//assigns to data the value on the first position of the deck without removing it
void front(Deck *deck_pointer, deck_type *data);
//assigns to data the value on the first position of the deck without removing it
void back(Deck *deck_pointer, deck_type *data);
//inserts an element at the end of the deck
int push_back(Deck *deck_pointer, deck_type data);
//inserts an element at the front of the deck
int push_front(Deck *deck_pointer, deck_type data);
//removes element at front position
int pop_front(Deck *deck_pointer);
//removes element at the end position
int pop_back(Deck *deck_pointer);

#endif
