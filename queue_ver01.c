// Data Structures Part 2: Queues
// Array Implementation of Queue in C programming language - 7/19/2020

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Create Queue structure
struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int* array;
};

//Function to create queue with given capacity
struct Queue* createQueue(unsigned capacity)
{
    //Create the queue
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));

    //Assign the given capacity to the queue
    queue->capacity = capacity;

    //Initialize size of queue as 0
    queue->front = queue->size = 0;

    //Initialize the rear
    queue->rear = capacity - 1;

    //Create the array
    queue->array = (int*)malloc(queue->capacity * sizeof(int));

    return queue;
};

//Function to check if queue is full
int isFull(struct Queue* queue)
{
    //Queue is full when size is equal to the capacity
    return( queue->size == queue->capacity);
}

//Function to check if queue is empty
int isEmpty(struct Queue* queue)
{
    //Queue is empty when size is equal to 0
    return (queue->size == 0);
}

//Function to add an item to the queue
void enqueue(struct Queue* queue, int item)
{
    //Check if queue is full
    if(isFull(queue))
        return;

    //Add the item to the rear of the queue
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;

    //Update the size of the queue
    queue->size = queue->size + 1;

    //Print status to user
    printf("%d enqueued to queue\n", item);
}

//Function to remove an item from the queue
int dequeue(struct Queue* queue)
{
    //Check if queue is empty
    if (isEmpty(queue))
        return INT_MIN;

    //Set the front item to the next item
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;

    //Update the size of the queue
    queue->size = queue->size - 1;

    return item;
}

//Function to return the current front of queue
int front(struct Queue* queue)
{
    //Check if queue is empty
    if (isEmpty(queue))
        return INT_MIN;

    return queue->array[queue->front];
}

//Function to return the current rear of queue
int rear(struct Queue* queue)
{
    //Check if queue is empty
    if (isEmpty(queue))
        return INT_MIN;

    return queue->array[queue->rear];
}

//Main Function
int main()
{
    //Create the Queue
    struct Queue* queue = createQueue(1000);

    //Add items to the queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("%d dequeued from queue\n\n", dequeue(queue));
    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));

    return 0;
}
