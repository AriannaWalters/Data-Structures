// Data Structures Part 2: Queues
// Linked List Implementation of Queue in C programming language

#include <stdio.h>
#include <stdlib.h>

//Structure for a linked list node to store a queue entry
struct QNode
{
    int key;
    struct QNode* next;
};

//Structure for queue front and rear nodes
struct Queue
{
    struct QNode *front, *rear;
};

//Function to create a new linked list node
struct QNode* newNode(int k)
{
    //Create temporary node
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));

    //Assign the new data to the new node
    temp->key = k;

    //Set the next node to NULL
    temp->next = NULL;

    return temp;
};

//Function to create a empty queue
struct Queue* createQueue()
{
    //Create the queue
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));

    //Set the front and rear to NULL since the queue is empty
    q->front = q->rear = NULL;

    return q;
};

//Function to add a key to the queue
void enqueue(struct Queue* q, int k)
{
    //Create new node with the key
    struct QNode* temp = newNode(k);

    //If queue is empty, then new node is front and rear
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }

    //Add the new node at the end of the queue and change rear node
    q->rear->next = temp;
    q->rear = temp;
}

//Function to remove a key from the queue
void dequeue(struct Queue* q)
{
    //Check if queue is empty
    if (q->front == NULL)
        return;

    //Store previous front node and move front node one ahead
    struct QNode* temp = q->front;
    q->front = q->front->next;

    //If front becomes NULL, then change rear to NULL
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

//Main Function
int main()
{
    //Create a new queue
    struct Queue* q = createQueue();

    //Manipulate data in the queue
    enqueue(q, 10);
    enqueue(q, 20);
    dequeue(q);
    dequeue(q);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    dequeue(q);

    printf("Queue Front : %d \n", q->front->key);
    printf("Queue Rear : %d", q->rear->key);

    return 0;
}
