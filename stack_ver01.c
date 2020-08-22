// Data Structures Part 2: Stacks
// Implementing Simple Stack using an array in C programming language - 7/12/2020

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Create stack structure
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};

//Function to create a stack
//Initializes size of stack as 0
struct Stack* createStack(unsigned capacity)
{
    //Create the new stack
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));

    //Set the capacity to the given capacity
    stack->capacity = capacity;

    //Signal stack is empty
    stack->top = -1;

    //Create the array
    stack->array = (int*)malloc(stack->capacity * sizeof(int));

    return stack;
}

//Function to check if stack is full
int isFull(struct Stack* stack)
{
    //Stack is full when top is equal to the last index
    return stack->top == stack->capacity - 1;
}

//Function to check if stack is empty
int isEmpty(struct Stack* stack)
{
    //Stack is empty when top is equal to -1
    return stack->top == -1;
}

//Function to add an item to stack
void push(struct Stack* stack, int item)
{
    //Check if stack is full
    if (isFull(stack))
        return;

    //Increase top by 1,and assign the new item to the new place
    stack->array[++stack->top] = item;

    printf("%d pushed to stack\n", item);
}

//Function to remove an item from stack
int pop(struct Stack* stack)
{
    //Check if stack is empty
    if (isEmpty(stack))
        return INT_MIN;

    //Decrease top by 1
    return stack->array[stack->top--];
}

//Function to return the top from stack without removing it
int peek(struct Stack* stack)
{
    //Check if stack is empty
    if (isEmpty(stack))
        return INT_MIN;

    //Return the top from stack
    return stack->array[stack->top--];
}

//Main function
int main()
{
    //Create the stack
    struct Stack* stack = createStack(100);

    //Add items to the stack
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("%d popped from stack\n", pop(stack));

    return 0;
}
