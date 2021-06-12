#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

int main()
{

    system("CLS");

    nodeQ_t* root = createNode(11);

    root->left = createNode(22);
    root->right = createNode(33);

    root->left->left = createNode(44);
    root->left->right = createNode(55); 

    root->right->left = createNode(66);
    root->right->right = createNode(77); 

    printf("%d\n", root->data);
    printf("%d\n", root->left->data);
    printf("%d\n", root->right->data);
    printf("%d\n", root->left->left->data);
    printf("%d\n", root->left->right->data);

    return 0;
}