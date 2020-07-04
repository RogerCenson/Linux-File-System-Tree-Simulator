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