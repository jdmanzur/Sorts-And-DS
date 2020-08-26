#include "queue.h"

void initialize(Queue *queue_pointer){
    //initializes front, back and size as 0;
    queue_pointer->front = 0;
    queue_pointer->size = 0;
    queue_pointer->back = 0;
}

int is_empty(Queue *queue_pointer){
    //checks if queue is empty
    return queue_pointer->size == 0;
}

int is_full(Queue *queue_pointer){
    //checks if queue is full
    return queue_pointer->size == MAX;
}

int size(Queue *queue_pointer){
    //returns queue size
    return queue_pointer->size;
}

void front(Queue *queue_pointer, queue_type *data){
    //assigns to data the value on the first position of the queue without removing it
    if(!is_empty(queue_pointer)){
        *data = queue_pointer->v[queue_pointer->front];
    }
}

void back(Queue *queue_pointer, queue_type *data){
    //assigns to data the value on the first position of the queue without removing it
    if(!is_empty(queue_pointer)){
        *data = queue_pointer->v[ (queue_pointer->back + (MAX - 1) % MAX) ]; //arithmetic manipulation due to the circular queue attirbute
    }
}

void push(Queue *queue_pointer, queue_type data){
    //inserts an element at the end of the queue
    if (!is_full(queue_pointer)){
        queue_pointer->v[queue_pointer->back] = data;
        queue_pointer->back++;
        queue_pointer->back = queue_pointer->back % MAX; //returns to the beggining if it passes the end position    
        queue_pointer->size++; //increments size
    }
    
}

void pop(Queue *queue_pointer){
    //removes an element at the begginning of the queue
    if(!is_empty(queue_pointer)){

        queue_pointer->front++;
        queue_pointer->front = queue_pointer->front % MAX; //returns to the beggining if it passes the end position    
        queue_pointer->size--; //decrements size
    }
}