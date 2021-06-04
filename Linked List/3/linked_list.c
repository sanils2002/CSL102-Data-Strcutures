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

status_t insertNode(nodeQ_t* head, nodeQ_t* newNode, unsigned short index)
{
    if(EMPTYNODE == head || EMPTYNODE == newNode) return LIST_FALSE;

    if(0 == index) return prependNode(head, newNode);  

    nodeQ_t* curr = head;

    unsigned short counter = 0;
    while(curr)
    {
        counter++;
        if(index == counter)
        {
            // 56
            // 14 -> 16 -> 17
            newNode->next = curr->next;
            // 56 ->16
            curr->next = newNode;
            // 14->56->16>17
            return LIST_TRUE;
        }
        curr = curr->next;
    }

    return LIST_FALSE;
}

status_t removeNode(nodeQ_t* head, nodeQ_t** newHead, unsigned short index)
{
    if(EMPTYNODE == head) return LIST_FALSE;

    if(0 == index)
    {
        *newHead = head->next;
        free(head);
        return LIST_TRUE;
    }

    nodeQ_t* prev = head;
    nodeQ_t* curr = head->next;

    // 15 -> EMPTYNODE
    unsigned short counter = 0;
    while(curr)
    {
        counter++;
        if(index == counter)
        {
            
            // 15 = prev
            // 16 = curr
            // 17 = curr->next
            prev->next = curr->next;
            free(curr);
            return LIST_TRUE;
        }

        // 15->16->17->18
        // 16 = prev
        // curr = 17
        prev = curr;
        curr = curr->next;
    }
    return LIST_FALSE;
}

nodeQ_t* reverseList(nodeQ_t* head)
{
    if(EMPTYNODE == head) return EMPTYNODE;

    nodeQ_t* prev = head;
    nodeQ_t* tmp = EMPTYNODE;
    nodeQ_t* curr = head->next;
    head->next = EMPTYNODE;

    while(curr){
        // 15 -> 16 -> 17 -> 18 -> 19
        // store curr->next into a tmp variable
        tmp = curr->next;
        // tmp = 17

        // update next for the curr node
        curr->next = prev;
        // curr = 16
        // curr->next = 15
         // 15 <- 16 <- 17 ??? 18 -> 19
         
        prev = curr;
        // prev = 16
        curr = tmp;
        // curr = 17
    }

    return prev;
}


