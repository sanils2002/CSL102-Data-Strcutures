#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "csl102_lab7.h"
#include <time.h>

#define SZ_LLIST_QWERTY 40

nodeQ_t* head_qwerty = EMPTYNODE;
nodeQ_t* head_submission = EMPTYNODE;

void printList_qwerty(nodeQ_t* head){
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

nodeQ_t* createNode_qwerty(short values[4]){
		nodeQ_t *node = (nodeQ_t *)malloc(sizeof(nodeQ_t));
		node->next = EMPTYNODE;
		node->prev = EMPTYNODE;
		for (int i = 0; i < 4; i++){
				node->data[i] = values[i];
		}
		return node;
}

status_t appendNode_qwerty(nodeQ_t *head, nodeQ_t *newNode){
		if (head && newNode){    
				while (head->next)  head = head->next; // this will work even if the input is tail node.
				head->next = newNode;
				newNode->prev = head;
				return LIST_TRUE;
		}
		return LIST_FALSE;
}

status_t prependNode_qwerty(nodeQ_t *head, nodeQ_t *newNode){
		if (head && newNode){    
				newNode->next = head;
				head->prev = newNode;
				return LIST_TRUE;
		}
		return LIST_FALSE;
}

status_t isPresent_qwerty(short arr[4], short value){
		for (int i = 0; i < 4; i++){
				if (arr[i] == value)
						return LIST_TRUE;
		}
		return LIST_FALSE;
}

status_t deleteNode_qwerty(nodeQ_t *head, nodeQ_t **out_newHead, short value){

		if (EMPTYNODE == head) return LIST_FALSE;

		nodeQ_t *ptr = head;
		*out_newHead = head;

		while(ptr){
				if(LIST_TRUE == isPresent_qwerty(ptr->data, value)){

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

void compareLists(nodeQ_t* ptr1, nodeQ_t* ptr2){

		nodeQ_t* tail1 = EMPTYNODE;
		nodeQ_t* tail2 = EMPTYNODE;

		while(ptr1 && ptr2){
				for(short j=0; j<4; j++){
						TEST_ASSERT_EQUAL_INT16(ptr1->data[j], ptr2->data[j]);
				}

				tail1 = ptr1;
				tail2 = ptr2;

				ptr1 = ptr1->next;
				ptr2 = ptr2->next;
		}

		while(tail1 && tail2){
				for(short j=0; j<4; j++){
						TEST_ASSERT_EQUAL_INT16(tail1->data[j], tail2->data[j]);
				}

				tail1 = tail1->prev;
				tail2 = tail2->prev;
		}
}

void test_createNode(){
		short random_array[SZ_LLIST_QWERTY] = {0};

		for(short i=0; i<SZ_LLIST_QWERTY; i++){
				random_array[i] = rand() % 512;
		}

		short input[10][4] = {0};
		for(short i=0; i<10; i++){
				for(short j=0; j<4; j++){
						input[i][j] = random_array[i * 4 + j];
				}
		}    

		nodeQ_t* ptr_qwerty = createNode_qwerty(input[0]);
		head_qwerty = ptr_qwerty;

		nodeQ_t* ptr_submission = createNode(input[0]);
		head_submission = ptr_submission;

		for(short i=1; i<10; i++){
				ptr_qwerty->next = createNode_qwerty(input[i]);
				ptr_qwerty->next->prev = ptr_qwerty;
				ptr_qwerty = ptr_qwerty->next;

				ptr_submission->next = createNode(input[i]);
				ptr_submission->next->prev = ptr_submission;
				ptr_submission = ptr_submission->next;
		}

		TEST_ASSERT_NOT_NULL(head_submission);

		//printList_qwerty(head_qwerty);
		//printList_qwerty(head_submission);

		nodeQ_t* ptr1 = head_qwerty;
		nodeQ_t* ptr2 = head_submission;

		compareLists(ptr1, ptr2);
}

void test_appendNode(){
		short input0[4] = {rand() % 512, rand() % 512, rand() % 512, rand() % 512};

		//printList_qwerty(head_qwerty);
		//printList_qwerty(head_submission);

		status_t st1 = appendNode_qwerty(head_qwerty, createNode_qwerty(input0));
		status_t st2 = appendNode(head_submission, createNode(input0));
		TEST_ASSERT_EQUAL_UINT16(st1, st2);

		short input1[4] = {rand() % 512, rand() % 512, rand() % 512, rand() % 512};
		st1 = appendNode_qwerty(head_qwerty, createNode_qwerty(input1));
		st2 = appendNode(head_submission, createNode(input1));
		TEST_ASSERT_EQUAL_UINT16(st1, st2);

		short input2[4] = {rand() % 512, rand() % 512, rand() % 512, rand() % 512};
		st1 = appendNode_qwerty(head_qwerty, createNode_qwerty(input2));
		st2 = appendNode(head_submission, createNode(input2));
		TEST_ASSERT_EQUAL_UINT16(st1, st2);

		//printList_qwerty(head_qwerty);
		//printList_qwerty(head_submission);

		nodeQ_t* ptr1 = head_qwerty;
		nodeQ_t* ptr2 = head_submission;

		compareLists(ptr1, ptr2);
}

void test_prependNode(){

		//printList_qwerty(head_qwerty);
		//printList_qwerty(head_submission);

		short input0[4] = {rand() % 512, rand() % 512, rand() % 512, rand() % 512};
		nodeQ_t* node0 = createNode_qwerty(input0);
		status_t st1 = prependNode_qwerty(head_qwerty, node0);
		if(LIST_TRUE == st1) head_qwerty = node0;
		status_t st2 = prependNode(head_submission, node0);
		if(LIST_TRUE == st2) head_submission = node0;
		TEST_ASSERT_EQUAL_UINT16(st1, st2);
		//printList_qwerty(head_qwerty);
		//printList_qwerty(head_submission);

		short input1[4] = {rand() % 512, rand() % 512, rand() % 512, rand() % 512};
		nodeQ_t* node1 = createNode_qwerty(input1);
		st1 = prependNode_qwerty(head_qwerty, node1);
		if(LIST_TRUE == st1) head_qwerty = node1;
		st2 = prependNode(head_submission, node1);
		if(LIST_TRUE == st2) head_submission = node1;
		TEST_ASSERT_EQUAL_UINT16(st1, st2);
		//printList_qwerty(head_qwerty);
		//printList_qwerty(head_submission);

		short input2[4] = {rand() % 512, rand() % 512, rand() % 512, rand() % 512};
		nodeQ_t* node2 = createNode_qwerty(input2);
		st1 = prependNode_qwerty(head_qwerty, node2);
		if(LIST_TRUE == st1) head_qwerty = node2;
		st2 = prependNode(head_submission, node2);
		if(LIST_TRUE == st2) head_submission = node2;
		TEST_ASSERT_EQUAL_UINT16(st1, st2);
		//printList_qwerty(head_qwerty);
		//printList_qwerty(head_submission);

		nodeQ_t* ptr1 = head_qwerty;
		nodeQ_t* ptr2 = head_submission;

		compareLists(ptr1, ptr2);
}

void test_deleteNode(){

		{
				nodeQ_t* node0 = head_qwerty;
				short value = 6;
				head_qwerty->next->next->next->data[1] = value;
				head_qwerty->next->next->next->next->next->data[0] = value;
				head_qwerty->next->next->next->next->next->next->next->next->next->data[0] = value;
				head_qwerty->data[3] = value;
				head_qwerty->next->data[3] = value;

				//printList_qwerty(head_qwerty);

				//printf("%p\n", head_qwerty);
				status_t st = deleteNode_qwerty(head_qwerty, &node0, value);
				//printf("%p\n", node0);

				if(LIST_TRUE == st) head_qwerty = node0;

				//printList_qwerty(head_qwerty);
		}

		{
				nodeQ_t* node0 = head_submission;
				short value = 6;
				head_submission->next->next->next->data[1] = value;
				head_submission->next->next->next->next->next->data[0] = value;
				head_submission->next->next->next->next->next->next->next->next->next->data[0] = value;
				head_submission->data[3] = value;
				head_submission->next->data[3] = value;

				//printList_qwerty(head_submission);

				//printf("%p\n", head_submission);
				status_t st = deleteNode(head_submission, &node0, value);
				//printf("%p\n", node0);

				if(LIST_TRUE == st) head_submission = node0;

				//printList_qwerty(head_submission);
		}

        nodeQ_t* ptr1 = head_qwerty;
		nodeQ_t* ptr2 = head_submission;

		compareLists(ptr1, ptr2);
}

void setUp (void) {} 
void tearDown (void) {} 

int main(void){

		srand(time(0));

		UNITY_BEGIN();

		RUN_TEST(test_createNode);
		RUN_TEST(test_appendNode);
		RUN_TEST(test_prependNode);
		RUN_TEST(test_deleteNode);

		UNITY_END();

		return 0;
}
