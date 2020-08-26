//Stack API
#define MAX 1000
typedef int stack_type;

typedef struct{
    stack_type v[MAX];
    unsigned int top;
}Stack;

//initiliazes the stack, setting top as the first valid position
void initialize(Stack *stack_pointer);
//inserts an element at the stack
void push(Stack *stack_pointer, stack_type data);
//removes an element from the stack
void pop(Stack *stack_pointer);
//sets data as the top of the stack
void top(Stack *stack_pointer, stack_type *data);
//checks if stack is empty/full
int is_empty(Stack *stack_pointer);
int is_full(Stack *stack_pointer);
//returns current size of the stack
int size(Stack *stack_pointer);