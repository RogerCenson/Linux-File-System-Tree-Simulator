#include "main.h"
#include "tree.h"

NODE *myFileSystem;

void main(){
	myFileSystem = (NODE *)malloc(sizeof(NODE));
	int ret = NO_ERROR;

	ret=initialize_tree(myFileSystem);
	if (ret<0){
		printf("Error \n");
		return;
	}

	printf ("teste\n");
	printf ("%s\n",myFileSystem->name);
}
