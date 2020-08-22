// Data Structures Part 1: Linked Lists
// Implementing ability to search for an element in a linked list - 7/11/2020

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Create node structure
struct Node
{
    int data;
    struct Node *next;
};

//Function to print linked List
void printList(struct Node* n)
{
    while (n != NULL)
    {
        printf("  %d  ", n->data);

        n = n->next;
    }
}

//Function to insert node at the front of the linked list
void insertFront(struct Node** head_ref, int new_data)
{
    //Create a new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    //Place the new data into the new node
    new_node->data = new_data;

    //Make the head node the next of the new node
    new_node->next = (*head_ref);

    //Move the head reference to point to the new head node
    (*head_ref) = new_node;
}

//Function to insert a new node after a given node
void insertAfter(struct Node* previous, int new_data)
{
    //Create a new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    //Place the new data in the new node
    new_node->data = new_data;

    //Make the  next of new node the next of previous node
    new_node->next = previous->next;

    //Set next of the previous node to the new node
    previous->next = new_node;
}

//Function to insert a node at the end of the linked list
void insertEnd(struct Node** head_ref, int new_data)
{
    //Create a new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    //Create temporary pointer to help find the last node
    struct Node* last = (*head_ref);

    //Place the new data in the new node
    new_node->data = new_data;

    //The new node should be the last node so it should point to NULL
    new_node->next = NULL;

    //If the link list is empty, then the new node is the head
    if (*head_ref == NULL)
    {
        (*head_ref) = new_node;
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

//Function to delete a node from the linked list
void deleteNode(struct Node** head_ref, int deleteData)
{
    //Store head node
    struct Node* temp = *head_ref, *prev;

    //If the Node to be deleted is in the head node
    if (temp != NULL && temp->data == deleteData)
    {
        //Change the head to the temporary node
        *head_ref = temp->next;

        //Free the old head node
        free(temp);

        return;
    }

    //Search for the data to be deleted
    //Keep track of the previous node to change it
    while (temp != NULL && temp->data != deleteData)
    {
        prev = temp;
        temp = temp->next;
    }

    //If the data to delete is not present
    if (temp == NULL)
        return;

    //Unlink the node from the linked list
    prev->next = temp->next;

    //Free temporary node
    free(temp);

}

//Function to delete the entire linked list
void deleteList(struct Node** head_ref)
{
    //Dereference the head reference to get the actual head node
    struct Node* current = *head_ref;
    struct Node* next;

    //Go through the linked list and free the nodes one by one
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    //Dereference the head reference to affect the actual head node
    *head_ref = NULL;
}

//Function to find length of linked list recursively
int findLength(struct Node* head)
{
    //Base case
    //If head is NULL, return 0
    if (head == NULL)
    {
        return 0;
    }

    //Else keep counting nodes
    else
    {
        return 1 + findLength(head->next);
    }
}

/*
//Function to search an element in linked list iteratively
bool search(struct Node* head, int element)
{
    //Create node to keep track of the current node
    struct Node* current = head;

    //Go through list and search for the element
    while (current != NULL)
    {
        //Return true if the current node equals the element
        if (current->data == element)
        {
            return true;
        }

        //Check the next node
        current = current->next;
    }

    //If element is not in the linked list
    return false;
}
*/

//Function to search an element in linked list recursively
bool search(struct Node* head, int element)
{
    //Base case
    //If the linked list is empty
    if (head == NULL)
    {
        return false;
    }

    //If head node is the element were searching for
    if (head->data == element)
    {
        return true;
    }

    //Else call function again
    return search(head->next, element);
}

//Main function
int main()
{
    //Create a empty linked list
    struct Node* head = NULL;

    //Insert data into the linked list
    insertFront(&head, 1);
    insertFront(&head, 2);
    insertFront(&head, 3);
    insertFront(&head, 4);

    //print original linked list
    printf("Created Linked List: ");
    printList(head);
    printf("\n");

    //Find the length of the list
    printf("Length of the Linked list is %d", findLength(head));
    printf("\n");

    //Search node for element
    search(head, 4)? printf("The element 4 is in the list!") : printf("The element 4 is NOT in the list!");
    printf("\n");

    //Delete a node from the list
    deleteNode(&head, 4);
    printf("\n");

    //Print new linked list
    printf("Linked List after Deletion of 4: ");
    printList(head);
    printf("\n");

    //Find the length of the list
    printf("Length of the Linked list is %d", findLength(head));
    printf("\n");

    //Search node for element
    search(head, 4)? printf("The element 4 is in the list!") : printf("The element 4 is NOT in the list!");
    printf("\n");

    //Delete the linked list
    printf("\nDeleting linked list");
    deleteList(&head);
    printf("\nLinked list deleted");
    printf("\n");

    return 0;
}
