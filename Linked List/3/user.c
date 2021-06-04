#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{
    
    system("CLS");

    nodeQ_t* head = EMPTYNODE;
    nodeQ_t* tail = EMPTYNODE;
    
    head = createNode(20);
    printf("%p\n", head);

    tail = head;

    for(short i=1; i < 6; i++)
    {
        nodeQ_t* newNode = createNode(20+i);
        if(appendNode(tail, newNode))
            tail = newNode;
    }

    for(short i=1; i < 6; i++)
    {
        nodeQ_t* newNode = createNode(20-i);
        if(prependNode(head, newNode))
            head = newNode;
    }

    #if 0
    printf("%d\t\t%p\t\t%p\n", head->data, head, head->next);
    printf("%d\t\t%p\t\t%p\n", head->next->data, head->next, head->next->next);
    printf("%d\t\t%p\t\t%p\n", head->next->next->data, head->next->next, head->next->next->next);
    printf("%d\t\t%p\t\t%p\n", tail->data, tail, tail->next);
    #endif

    printList(head);

    if(LIST_TRUE == insertNode(head, createNode(100), 5))
    {
        printList(head);
    }

    if(LIST_TRUE == insertNode(head, createNode(101), 10))
    {
        printList(head);
    }

    if(LIST_TRUE == insertNode(head, createNode(450),20))
    {
        printList(head);
    }

    if(LIST_TRUE == removeNode(head, &head, 8))
    {
        printList(head);
    }

    if(LIST_TRUE == removeNode(head, &head, 0))
    {
        printList(head);
    }

    if(LIST_TRUE == removeNode(head, &head, 800))
    {
        printList(head);
    }

    head = reverseList(head);
    printList(head);

    //printf("dataPresent = %d \n", isDataPresent(head, 225));

    //destroyList(head);
    //head = EMPTYNODE;

    //printf("%d\n", head->data);

    return 0;
}