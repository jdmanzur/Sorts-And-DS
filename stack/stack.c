#include "stack.h"

void initialize(Stack *stack_pointer){
    //initiliazes the stack, setting top as the first valid position
    stack_pointer->top = 0;
}
void push(Stack *stack_pointer, stack_type data){

    if(!is_full(stack_pointer)){
        //inserts an element at the stack
        stack_pointer->v[stack_pointer->top] = data;
        //increments the top position
        stack_pointer->top++;
    }
}
void pop(Stack *stack_pointer){
    //removes an element from the stack
    if(!is_empty(stack_pointer)){
        stack_pointer->top--;
    }
}
void top(Stack *stack_pointer, stack_type *data){
    //sets data as the top of the stack without removing it
    if(!is_empty(stack_pointer)){
        *data = stack_pointer->v[stack_pointer->top];
    }
}
int is_empty(Stack *stack_pointer){
    //checks if stack is empty
    return stack_pointer->top == 0;
}
int is_full(Stack *stack_pointer){
    //checks if stack is full
    return stack_pointer->top == MAX;
}
int size(Stack *stack_pointer){
    //returns current size of the stack
    return stack_pointer->top;
}