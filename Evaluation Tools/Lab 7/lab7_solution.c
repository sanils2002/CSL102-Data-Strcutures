#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "csl102_lab7.h"
#include <time.h>

#define SZ_LLIST 40

nodeQ_t* head = EMPTYNODE;

void printList(nodeQ_t* head){
		if(EMPTYNODE == head) return;

		nodeQ_t* node = head;
		nodeQ_t* tail = EMPTYNODE;

		while(node){
				printf("%d, %d, %d, %d --> ", node->data[0], node->data[1], node->data[2], node->data[3]);
				tail = node;
				node = node->next;
		}
		printf("EMPTYNODE\n");

		while(tail){
				printf("%d, %d, %d, %d --> ", tail->data[0], tail->data[1], tail->data[2], tail->data[3]);
				tail = tail->prev;
		}
		printf("EMPTYNODE\n\n");

}

nodeQ_t* createNode(short values[4]){
		nodeQ_t *node = (nodeQ_t *)malloc(sizeof(nodeQ_t));
		node->next = EMPTYNODE;
		node->prev = EMPTYNODE;
		for (int i = 0; i < 4; i++){
				node->data[i] = values[i];
		}
		return node;
}

status_t appendNode(nodeQ_t *head, nodeQ_t *newNode){
		if (head && newNode){    
				while (head->next)  head = head->next; // this will work even if the input is tail node.
				head->next = newNode;
				newNode->prev = head;
				return LIST_TRUE;
		}
		return LIST_FALSE;
}

status_t prependNode(nodeQ_t *head, nodeQ_t *newNode){
		if (head && newNode){    
				newNode->next = head;
				head->prev = newNode;
				return LIST_TRUE;
		}
		return LIST_FALSE;
}

status_t isPresent(short arr[4], short value){
		for (int i = 0; i < 4; i++){
				if (arr[i] == value)
						return LIST_TRUE;
		}
		return LIST_FALSE;
}

status_t deleteNode(nodeQ_t *head, nodeQ_t **out_newHead, short value){

		if (EMPTYNODE == head) return LIST_FALSE;

		nodeQ_t *ptr = head;
		*out_newHead = head;

		while(ptr){
				if(LIST_TRUE == isPresent(ptr->data, value)){

						short isHead = 0;
						if (EMPTYNODE == ptr->prev) isHead = 1;

						nodeQ_t *prev = ptr->prev;
						ptr = ptr->next;
						ptr->prev = prev;

						if(ptr->prev) ptr->prev->next = ptr;

						if(isHead) {
								*out_newHead = ptr;
								ptr->prev = EMPTYNODE;
						}
				}
				else ptr = ptr->next;
		}    
		return LIST_TRUE;
}