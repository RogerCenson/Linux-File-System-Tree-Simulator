#include "commands.h"
#include <stdlib.h>


int mkdir(NODE *tree, NODE *p){
	NODE *q = tree;
	char name[64];
	unsigned short same_name=0;
	sprintf (name,"%s", p->name);
	if (q->child == NULL){
		q->child=p;
		p->father=q;
	}
	else{
		q=q->child;
		if (q->sibiling==NULL){
			if(!strcmp(q->name,name)){
				same_name++;
				memset(name, 0, sizeof name);
				sprintf(name+strlen(name), "%s(%u)",p->name, same_name);
			}
			sprintf (p->name,"%s",name);
			q->sibiling=p;
			p->father=q->father;
		}
		else{
			while (q->sibiling){
				if(!strcmp(q->name,name)){
					same_name++;
					memset(name, 0, sizeof name);
					sprintf(name+strlen(name), "%s(%u)",p->name, same_name);
				}
				q=q->sibiling;
			}
			if(!strcmp(q->name,name)){
				same_name++;
				memset(name, 0, sizeof name);
				sprintf(name+strlen(name), "%s(%u)",p->name, same_name);
				// sprintf(name, "%s(%u)",p->name, same_name);
			}
			sprintf (p->name,"%s",name);
			q->sibiling=p;
			p->father=q->father;
		} 
	}

	return 0;
}

int ls(NODE *tree){
	NODE *q = tree;
	printf("\n");
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

NODE *cd(NODE *tree, NODE *current, char *name){
	NODE *q = malloc(sizeof(NODE));
	*q=*current;
	if (!strcmp(name,"."))
		return tree;
	else{
		char * token = strtok(name, "/");
		while( token != NULL ) {
			if (!strcmp("..",token)){
				if (q->father!=NULL)
					return q->father;
				else
					return q;
			}
			if (q->child==NULL){
				printf ("There is no child\n");
				return q;
			}
			else{
				q=q->child;
				if (strcmp(q->name,token)){
					while(q->sibiling){
						q=q->sibiling;
						if(!strcmp(q->name,token))
							break;
					}
					printf("There is no file with the name %s\n",token);
					return q;
				}
			}
			token = strtok(NULL, "/");
		}
		return q;
	}
}

int pwd(NODE *tree){
	NODE *q = tree;
	char path[64];
    size_t size = 0;
    printf("\n");
    sprintf(path, "%s", q->name);
    if (q->father==NULL){
    	printf("%s", path);
    	return 0;
    }
    else{
    	char path_help[64];
    	while(q->father!=NULL){
    		q=q->father;
    		if(q->father!=NULL){
    			memset(path_help, 0, sizeof path_help);
				sprintf(path_help+strlen(path_help), "%s/%s",q->name, path);
				memcpy(path, path_help, strlen(path_help));
    		}
    		else{
    			memset(path_help, 0, sizeof path_help);
				sprintf(path_help+strlen(path_help), "/%s", path);
				memcpy(path, path_help, strlen(path_help));
    		}
    	}
    	printf("%s", path);
    	return 0;
    }
}