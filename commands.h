#ifndef COMMANDS_H
#define COMMANDS_H

#include "tree.h"
#include <string.h>

int mkdir(NODE *tree, NODE *p);
int ls(NODE *tree);
NODE *cd(NODE *tree, char *name);

#endif //COMMANDS_H
