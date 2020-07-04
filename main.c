#include "main.h"

NODE *myFileSystem;

void main(){
	myFileSystem = (NODE *)malloc(sizeof(NODE));
	NODE *p;
	NODE *current = myFileSystem;
	char line[128], name[64], command[10];
	int ret = NO_ERROR;

	ret=initialize_tree(myFileSystem);
	if (ret<0){
		printf("Error \n");
		return;
	}
	while(1){

		printf("\nEnter command\n");

		fgets(line, 128, stdin);  // get an input line
		line[strlen(line)-1] = 0; // kill \n at end
		sscanf(line, "%s %s", command, name); // extract name string and id value

		if (line[0] == 0){ // break out on empty input line
		}
		else if (!strcmp(command,"exit")){ // end program
			return;
		}  
		else if (!strcmp(command,"mkdir")){
			p = (NODE *)malloc(sizeof(NODE));
			strcpy(p->name,name);
			p->sibiling=NULL;
			p->child=NULL;
			mkdir(current,p);
		}
		else if (!strcmp(command,"ls")){
			if (!strcmp(name,""))
				ls(current);
			else{
				NODE *q =malloc(sizeof(NODE));
				memcpy(q,current,sizeof(NODE));
				q=cd(myFileSystem,q,name);
				ls(q);
			}
		}
		else if (!strcmp(command,"cd")){
	      	current=cd(myFileSystem, current, name);
		}	
		else if (!strcmp(command,"pwd")){
			pwd(current);
		}
		memset(&name[0], 0, sizeof(name));
	}
}
