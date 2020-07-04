#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stddef.h>

typedef struct node{
	char name[64];
	struct node *father;
	struct node *sibiling;
	struct node *child;
}NODE;

int initialize_tree(NODE *node);
#endif //TREE_H
