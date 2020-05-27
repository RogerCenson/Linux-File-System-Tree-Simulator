#include "commands.h"

int mkdir(NODE *tree, NODE *p){
	NODE *q = tree;
	if (q->child == NULL)
		q->child=p;
	else{
		q=q->child;
		if (q->sibiling==NULL)
			q->sibiling=p;
		else{
			while (q->sibiling)
				q=q->sibiling;
			q->sibiling=p;
		} 
	}

	return 0;
}

int ls(NODE *tree){
	NODE *q = tree;
	if (q->child){
		q=q->child;
		printf("%s\n",q->name);

		if (q->sibiling){
			while (q->sibiling){
				q=q->sibiling;
				printf("%s\n",q->name);
			}
		}
	}
}

NODE *cd(NODE *tree, char *name){
	NODE *q = tree;
	if (q->child==NULL){
		printf ("There is no child\n");
		return q;
	}
	else{
		q=q->child;
		if (!strcmp(q->name,name))
			return q;
		else{
			while(q->sibiling){
				q=q->sibiling;
				if(!strcmp(q->name,name))
					return q;
			}
			printf("There is no file with this name\n");
			return q;
		}
	}
}