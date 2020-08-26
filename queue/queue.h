//CIRCULAR QUEUE API
#ifndef QUEUE
#define QUEUE
#define MAX 1000

typedef int queue_type;

typedef struct{
    queue_type v[MAX];
    int front;
    int back;
    int size;   //you can remove this variable by using a sentinel, avoinding that back collides with front when the queue is full
}Queue;


//initializes queue
void initialize(Queue *queue_pointer);
//checks if queue is empty
int is_empty(Queue *queue_pointer);
//checks if queue is full
int is_full(Queue *queue_pointer);
//returns size of queue
int size(Queue *queue_pointer);
//returns the front position of the queue
void front(Queue *queue_pointer, queue_type *data);
//returns the back position of the queue
void back(Queue *queue_pointer, queue_type *data);
//inserts an element at the back of the queue
void push(Queue *queue_pointer, queue_type data);
//removes an element at the front of the queue
void pop(Queue *queue_pointer);

#endif
