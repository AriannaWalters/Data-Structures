// Data Structures Part 2: Stacks
// Implementing Simple Stack using a linked list in C programming language - 7/12/2020

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Create stack structure
struct StackNode
{
    int data;
    struct StackNode* next;
};

//Create structure for a new node added to the stack
struct StackNode* newNode(int data)
{
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
};

//Function to check if stack is empty
int isEmpty(struct StackNode* root)
{
    return !root;
}

//Function to add item to stack
void push(struct StackNode** root, int data)
{
    //Create new node
    struct StackNode* stackNode = newNode(data);

    //Set the next of the new node
    stackNode->next = *root;

    //Set the new node as the root of the stack
    *root = stackNode;

    printf("%d pushed to stack\n", data);
}

//Function to remove item from stack
int pop(struct StackNode** root)
{
    //Check if stack is empty
    if (isEmpty(*root))
        return INT_MIN;

    //Create temporary node that holds the node to be removed
    struct StackNode* temp = *root;

    //Assign the new root node
    *root = (*root)->next;

    //Save data from popped node
    int popped = temp->data;

    //Free the temporary node
    free(temp);

    return popped;
}

//Function to peek at the top of the stack
int peek(struct StackNode* root)
{
    //Check if stack is empty
    if(isEmpty(root))
        return INT_MIN;

    return root->data;
}

//Main Function
int main()
{
    //Create stack
    struct StackNode* root = NULL;

    //Add data to the stack
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    printf("\n");
    printf("%d popped from stack\n", pop(&root));
    printf("Top element is %d\n", peek(root));

    return 0;
}
