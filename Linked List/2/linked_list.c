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

void printList(nodeQ_t* head)
{
    if(EMPTYNODE == head) return;

    nodeQ_t* node = head;
    while(node)
    {
        printf("%d --> ", node->data);
        node = node->next;
    }
    printf("EMPTYNODE\n");
}

void destroyList(nodeQ_t* ptr)
{
    if(EMPTYNODE == ptr) return;

    while(ptr)
    {
        nodeQ_t* current = ptr;
        printList(current);
        ptr = ptr->next;
        free(current);    
    }

    printf("EMPTYNODE\n");
}

status_t isDataPresent(nodeQ_t* ptr, short data)
{
    if(EMPTYNODE == ptr) return LIST_FALSE;

    while(ptr)
    {
        if(data == ptr->data) return LIST_TRUE;
        ptr = ptr->next;
    }

    return LIST_FALSE;
}

