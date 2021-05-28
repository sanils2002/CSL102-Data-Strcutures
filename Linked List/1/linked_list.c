#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

nodeQ_t* createNode(short val)
{
    nodeQ_t* ptr = (nodeQ_t*)malloc(sizeof(nodeQ_t));
    ptr->data = val;
    ptr->next = EMPTYNODE; // NULL
    return ptr;
}

status_t appendNode(nodeQ_t* tail, nodeQ_t* newNode)
{

    if(EMPTYNODE == tail || EMPTYNODE == newNode) return LIST_FALSE;

    tail->next = newNode;
    return LIST_TRUE;
}

status_t prependNode(nodeQ_t* head, nodeQ_t* newNode)
{

    if(EMPTYNODE == head || EMPTYNODE == newNode) return LIST_FALSE;

    newNode->next = head;
    return LIST_TRUE;
}
