#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{

    nodeQ_t* head = EMPTYNODE;
    nodeQ_t* tail = EMPTYNODE;

    head = createNode(20);
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


    printf("%d\t\t%p\t\t%p\n", head->data, head, head->next);
    printf("%d\t\t%p\t\t%p\n", head->next->data, head->next, head->next->next);
    printf("%d\t\t%p\t\t%p\n", head->next->next->data, head->next->next, head->next->next->next);
    printf("%d\t\t%p\t\t%p\n", tail->data, tail, tail->next);

    return 0;
}