#include "deck.h"
void initialize(Deck *deck_pointer, int max){
    //initializes front, back and size as 0;
    deck_pointer->def_max = max;
    deck_pointer->front = 0;
    deck_pointer->size = 0;
    deck_pointer->back = 0;
}

int is_empty(Deck *deck_pointer){
    //checks if deck is empty
    return deck_pointer->size == 0;
}

int is_full(Deck *deck_pointer){
    //checks if deck is full
    return deck_pointer->size == deck_pointer->def_max;
}

int size(Deck *deck_pointer){
    //returns deck size
    return deck_pointer->size;
}

void front(Deck *deck_pointer, deck_type *data){
    //assigns to data the value on the first position of the deck without removing it
    if(!is_empty(deck_pointer)){
        *data = deck_pointer->v[deck_pointer->front];
    }
}

void back(Deck *deck_pointer, deck_type *data){
    //assigns to data the value on the first position of the deck without removing it
    if(!is_empty(deck_pointer)){
        *data = deck_pointer->v [ (deck_pointer->back + (deck_pointer->def_max - 1)) % deck_pointer->def_max ]; //arithmetic manipulation due to the circular deck attirbute
    }
}

int push_back(Deck *deck_pointer, deck_type data){
    //inserts an element at the end of the deck
    if (!is_full(deck_pointer)){
        deck_pointer->v[deck_pointer->back] = data;
        deck_pointer->back++;
        deck_pointer->back = deck_pointer->back % deck_pointer->def_max; //returns to the beggining if it passes the end position    
        deck_pointer->size++; //increments size
        return(0);
    }
    
    return(1);
}

int push_front(Deck *deck_pointer, deck_type data){
    //inserts an element at the front of the deck
    if (!is_full(deck_pointer)){
        deck_pointer->front = (deck_pointer->front + deck_pointer->def_max - 1)%deck_pointer->def_max;
        deck_pointer->v[deck_pointer->front] = data; //returns to the beggining if it passes the end position    
        deck_pointer->size++; //increments size
        return(0);
    }
    
    return(1);
}

int pop_front(Deck *deck_pointer){
    //removes an element at the begginning of the deck
    if(!is_empty(deck_pointer)){
        deck_pointer->front++;
        deck_pointer->front = deck_pointer->front % deck_pointer->def_max; //returns to the beggining if it passes the end position    
        deck_pointer->size--; //decrements size
        return(0);
    }
    return(1);
}

int pop_back(Deck *deck_pointer){
    //removes element at the end position
    if(!is_empty(deck_pointer)){
        deck_pointer->back = (deck_pointer->back + deck_pointer->def_max - 1)%deck_pointer->def_max;//returns to the beggining if it passes the end position    
        deck_pointer->size--; //decrements size
        return(0);
    }
    return(1);

}
