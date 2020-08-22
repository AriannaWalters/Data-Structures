// Data Structures Part 3: Binary Tree
// Implementation of a simple four node tree in C programming language

#include <stdio.h>
#include <stdlib.h>

//Create a tree node structure
struct node
{
    int data;

    //Each element in a binary tree can have only 2 children
    struct node *left;
    struct node *right;
};

//Function to create new node with given data
struct node* newNode(int data)
{
    //Allocate memory for new node
    struct node* node = (struct node*)malloc(sizeof(struct node));

    //Assign data to new node
    node->data = data;

    //Initialize left and right children as NULL
    node->left = NULL;
    node->right = NULL;

    return(node);
};

//Main Function
int main()
{
    //Create root
    struct node *root = newNode(1);

    //Add 2 and 3 as left and right children of 1
    root->left = newNode(2);
    root->right = newNode(3);

    //Add 4 as the left child of 2
    root->left->left = newNode(4);

    /* Tree should look like:
                 1
            /        \
            2         3
           / \      /   \
          4  NULL  NULL NULL
    */

    getchar();
    return 0;
}
