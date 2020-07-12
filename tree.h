#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>


typedef struct node{
	char name[64];
	struct node *father;
	struct node *sibiling;
	struct node *child;
} NODE;

typedef struct QNode { 
    struct node* current; 
    struct QNode* next; 
} QNODE; 

typedef struct Queue { 
    struct QNode *front, *rear; 
} QUEUE; 


int initialize_tree(NODE *node);
QNODE* newNode(NODE *node);
QUEUE* createQueue();
void enQueue(QUEUE* q, NODE *node);
int deQueue(QUEUE* q); 
#endif //TREE_H
