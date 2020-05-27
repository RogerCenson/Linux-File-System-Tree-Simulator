#include "tree.h"

int initialize_tree(NODE *node){
	sprintf(node->name,"/");
	node->child=NULL;
	node->sibiling=NULL;
	if (node->name == NULL)
		return ERROR;
	else
		return NO_ERROR;
}