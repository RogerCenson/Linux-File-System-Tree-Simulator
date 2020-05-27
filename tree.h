#define __TREE_H__

typedef struct node{
	char name[10];
	struct node *sibiling;
	struct node *child;
}NODE;

int initialize_tree(NODE *node);