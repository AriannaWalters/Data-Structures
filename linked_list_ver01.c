// Data Structures Part 1: Linked Lists
// Implementing Simple Linked List in C programming language - 7/4/2020

#include <stdio.h>
#include <stdlib.h>

//Node structure
//Node contains data and pointer to the next node
struct Node {
  int data;
  struct Node* next;
};

//Function to print linked List
void printList(struct Node* n)
{
  //Traverse through linked list
  while (n != NULL){
    printf(" %d \n", n->data);
    n = n->next;
  }
}

//Main Function
int main()
{
  //Create 3 nodes for linked List
  struct Node* head = NULL;
  struct Node* second = NULL;
  struct Node* third = NULL;

  //Allocate memory to the 3 nodes
  head = (struct Node*)malloc(sizeof(struct Node));
  second = (struct Node*)malloc(sizeof(struct Node));
  third = (struct Node*)malloc(sizeof(struct Node));

  //Assign data to head node
  //Link head node to second node
  head->data = 3;
  head->next = second;

  //Assign data to second node
  //Link second node to third node
  second->data = 2;
  second->next = third;

  //Assign data to third node
  //Link third node to NULL since its the last node
  third->data = 1;
  third->next = NULL;

  //Print linked list
  printList(head);

  return 0;
}
