#ifndef LINKED_LIST_H
#define LINKED_LIST_H


    #include"utils.h"

typedef struct node
{
    int data;
    struct node *next;
}node;

    

    extern node*head;

node* createNode(int data);
void linkedListMenu();
void printList();
void insert( int data);
void deleteNode(int data );
void freeList();


#endif // LINKED_LIST_H