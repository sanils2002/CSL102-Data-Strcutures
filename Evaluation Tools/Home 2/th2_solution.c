#include <stdio.h>
#include <stdlib.h>
#include "csl102_th2.h"

#define SZ_LLIST 20

short random_arr[SZ_LLIST] = {0};
nodeQ_t *head = EMPTYNODE;

void printList(nodeQ_t* head) {
		if(EMPTYNODE == head) return;

		nodeQ_t* node = head;
		while(node){
				printf("%d --> ", node->data);
				node = node->next;
		}
		printf("EMPTYNODE\n");
}

nodeQ_t* createList(short values[], short sz) {
		nodeQ_t* ptr = (nodeQ_t*)malloc(sizeof(nodeQ_t));
		ptr->next = EMPTYNODE;
		ptr->data = values[0];
		nodeQ_t *head = ptr;
		for(short idx = 1; idx < sz; idx++){
				ptr->next = (nodeQ_t*)malloc(sizeof(nodeQ_t));
				ptr = ptr->next;
				ptr->next = EMPTYNODE;
				ptr->data = values[idx];
		}
		return head;
}

status_t deleteNodes(nodeQ_t* head, nodeQ_t** out_newHead, short in_data) {

		if(EMPTYNODE == head) return LIST_FALSE;

		*out_newHead = head;

		nodeQ_t* curr = head;
		while(curr && curr->data == in_data){
				*out_newHead = curr->next;
				free(curr);
				curr = *out_newHead;
		}
		
		if(EMPTYNODE == *out_newHead) return LIST_TRUE;

		nodeQ_t* prev = *out_newHead;
		curr = (*out_newHead)->next;

		while(curr){
				if(curr->data == in_data){
						prev->next = curr->next;
						free(curr);
						curr = prev->next;
				}
				else{
						prev = curr;
						curr = curr->next;
				}
		}

		return LIST_TRUE;
}

status_t splitLists(nodeQ_t* head, nodeQ_t** out_evenList, nodeQ_t** out_oddList) {
		//printf("splitLists_nrpax\n");
		if(EMPTYNODE == head) return LIST_FALSE;

		short idx = 0;
		nodeQ_t* ptr = head->next;
		short vals[1024] = {0};
		while(ptr){
				vals[idx++] = ptr->data;
				ptr = ptr->next;    
		}

		nodeQ_t* dupHead = createList(vals, idx);

		//printList_nrpax(dupHead);

		*out_evenList = head;
		*out_oddList = dupHead;

		nodeQ_t* even = *out_evenList;
		nodeQ_t* odd = *out_oddList;

		while(even && even->next){
				even->next = even->next->next;
				even = even->next;
		}

		while(odd && odd->next){
				odd->next = odd->next->next;
				odd = odd->next;
		}

		return LIST_TRUE;
}

status_t getCommonSubList(nodeQ_t* head1, nodeQ_t* head2, nodeQ_t** out_commonSubList){

		//printf("getCommonSubList_nrpax\n\n");
		if(EMPTYNODE == head1 || EMPTYNODE == head2) return LIST_FALSE;

		short counter1 = 0;
		nodeQ_t* head1_arr[1024] = {0};
		nodeQ_t* node1 = head1;
		while(node1){
				head1_arr[counter1] = node1;
				node1 = node1->next;
				counter1++;
		}
		//printList_nrpax(head1);

		short counter2 = 0;
		nodeQ_t* head2_arr[1024] = {0};
		nodeQ_t* node2 = head2;
		while(node2) {
				head2_arr[counter2] = node2;
				node2 = node2->next;
				counter2++;
		}
		//printList_nrpax(head2);

		for(short i = 0; i < counter1; i++){
				for(short j = 0; j < counter2; j++){
						//printf("%p\t\t%p\n", head1_arr[i], head2_arr[j]);
						if(head1_arr[i] == head2_arr[j]){
								*out_commonSubList = head1_arr[i];
								//printList_nrpax(*out_commonSubList);
								return LIST_TRUE;
						}   
				}
		}

		return LIST_FALSE;
}