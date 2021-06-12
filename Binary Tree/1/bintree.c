#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

nodeQ_t* createNode(short val)
{
   nodeQ_t* newNode = (nodeQ_t*) malloc(sizeof(nodeQ_t));
   newNode->data = val;
   newNode->left = EMPTYNODE;
   newNode->right = EMPTYNODE;
   return newNode;
}
