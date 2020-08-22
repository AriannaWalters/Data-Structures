// Data Structures Part 1: Linked Lists
// Implementing Insertion capabilities to the linked list - 7/9/2020

#include <stdio.h>
#include <stdlib.h>

//Create Node Structure
struct Node
{
    int data;
    struct Node *next;
};

//Function to print linked List
void printList(struct Node* n)
{
    while (n != NULL){
        printf("  %d  \n", n->data);
        n = n->next;
    }
}

//Function to insert node at the front of the linked list
void insertFront(struct Node** head_ref, int new_data)
{
    //Create new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    //Place the new data in the new node
    new_node->data = new_data;

    //Make the head node the next of new node
    new_node->next = (*head_ref);

    //Move the head reference to point to the new head node
    (*head_ref) = new_node;
}

//Function to insert a new node after a given node
void insertAfter(struct Node* previous, int new_data)
{
    //Check if previous node is NULL
    if (previous == NULL){
        printf("The given previous node cannot be NULL");
        return;
    }

    //Create a new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    //Place the new data in the new node
    new_node->data = new_data;

    //Make the next new node the next of previous node
    new_node->next = previous->next;

    //Set next of the previous node to the new node
    previous->next = new_node;
}

//Function to insert a node at the end of the linked list
void insertEnd(struct Node** head_ref, int new_data)
{
    //Create the new node with the new data
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    //Create temporary pointer to help find the last node
    struct Node *last = *head_ref;

    //Place the new data into the new node
    new_node->data = new_data;

    //The new node should be the last node so it should point to NULL
    new_node->next = NULL;

    //If the link list is empty, then the new node is the head
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    //Else go through the list until the last node is found
    while (last->next != NULL)
    {
        last = last->next;
    }

    //Change the next of the last node
    last->next = new_node;

    return;
}

//Main function
int main()
{
    //Start with a empty list
    struct Node* head = NULL;

    //Insert 1. Linked list should be 1->NULL
    insertEnd(&head, 1);

    //Insert 3 at the beginning. List should be 3->1->NULL
    insertFront(&head, 3);

    //Insert 4 at the beginning. List should be 4->3->1->NULL
    insertFront(&head, 4);

    //Insert 5 at the beginning. List should be 5->4->3->1->NULL
    insertFront(&head, 5);

    //Insert 0 at the end. List should be 5->4->3->1->0->NULL
    insertEnd(&head, 0);

    //Insert 2, after 3. List should be 5->4->3->2->1->0->NULL
    insertAfter(head->next, 2);

    //Print linked list
    printList(head);
    printf("Blast Off!!!!\n");

    return 0;
}
