#include "tree.h"

int initialize_tree(NODE *node){
	sprintf(node->name,"/");
	node->father=NULL;
	node->child=NULL;
	node->sibiling=NULL;
	if (node->name == NULL)
		return -1;
	else
		return 0;
}

QNODE* newNode(NODE *node){ 
    QNODE* temp = (QNODE*)malloc(sizeof(QNODE)); 
    temp->current = node; 
    temp->next = NULL; 
    return temp; 
} 

QUEUE* createQueue(){
	QUEUE* q = (QUEUE*)malloc(sizeof(struct Queue)); 
    q->front = q->rear = NULL; 
    return q; 
}

void enQueue(QUEUE* q, NODE *node){
	// Create a new LL node 
    QNODE* temp = newNode(node); 
  
    // If queue is empty, then new node is front and rear both 
    if (q->rear == NULL) { 
        q->front = q->rear = temp; 
        return; 
    } 
  
    // Add the new node at the end of queue and change rear 
    q->rear->next = temp; 
    q->rear = temp; 
}

int deQueue(QUEUE* q){
	    // If queue is empty, return NULL. 
    if (q->front == NULL){
        return -1; 
    }
  
    // Store previous front and move front one node ahead 
    struct QNode* temp = q->front; 
  
    q->front = q->front->next; 
  
    // If front becomes NULL, then change rear also as NULL 
    if (q->front == NULL){
        q->rear = NULL; 
        return -1; 
    }
  
    free(temp);
    return 0; 	
}