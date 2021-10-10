#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "csl102_th2.h"
#include <time.h>

#define SZ_LLIST_NRPAX 20

short random_array[SZ_LLIST_NRPAX] = {0};
nodeQ_t *head_nrpax = EMPTYNODE;
nodeQ_t* head_submission = EMPTYNODE;

void printList_nrpax(nodeQ_t* head){
		if(EMPTYNODE == head) return;

		nodeQ_t* node = head;
		while(node){
				printf("%d --> ", node->data);
				node = node->next;
		}
		printf("EMPTYNODE\n");
}

nodeQ_t* createList_nrpax(short values[], short sz){
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

status_t deleteNodes_nrpax(nodeQ_t* head, nodeQ_t** out_newHead, short in_data){

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

status_t splitLists_nrpax(nodeQ_t* head, nodeQ_t** out_evenList, nodeQ_t** out_oddList){
		//printf("splitLists_nrpax\n");
		if(EMPTYNODE == head) return LIST_FALSE;

		short idx = 0;
		nodeQ_t* ptr = head->next;
		short vals[1024] = {0};
		while(ptr){
				vals[idx++] = ptr->data;
				ptr = ptr->next;    
		}

		nodeQ_t* dupHead = createList_nrpax(vals, idx);

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

status_t getCommonSubList_nrpax(nodeQ_t* head1, nodeQ_t* head2, nodeQ_t** out_commonSubList){

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

void compareLists(nodeQ_t* ptr1, nodeQ_t* ptr2){
	while(ptr1 && ptr2){
		TEST_ASSERT_EQUAL_INT16(ptr1->data, ptr2->data);
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
}

void test_createList(){
		// create duplicate entries

		for(short i=0; i<SZ_LLIST_NRPAX; i++){
				random_array[i] = rand() % 512;
		}

		random_array[5] = random_array[11];
		random_array[0] = random_array[1];

		head_nrpax = createList_nrpax(random_array, SZ_LLIST_NRPAX);
		head_submission = createList(random_array, SZ_LLIST_NRPAX);
		//printList_nrpax(head_nrpax);
		//printList_nrpax(head_submission);

		nodeQ_t* ptr1 = head_nrpax;
		nodeQ_t* ptr2 = head_submission;

		TEST_ASSERT_NOT_NULL(head_submission);

		compareLists(ptr1, ptr2);
}

void test_deleteNodes(){
		{
			//printList_nrpax(head_nrpax);
			nodeQ_t *newHead = EMPTYNODE;
			status_t st = deleteNodes_nrpax(head_nrpax, &newHead, random_array[5]);
			head_nrpax = newHead;
			//printList_nrpax(head_nrpax);
			//return;

			nodeQ_t *newHead_submission = EMPTYNODE;
			st = deleteNodes(head_submission, &newHead_submission, random_array[5]);
			head_submission = newHead_submission;	
			//printList_nrpax(head_submission);

			nodeQ_t* ptr1 = head_nrpax;
			nodeQ_t* ptr2 = head_submission;

			TEST_ASSERT_NOT_NULL(head_submission);

			compareLists(ptr1, ptr2);
		}

		{
			nodeQ_t *newHead = EMPTYNODE;
			status_t st = deleteNodes_nrpax(head_nrpax, &newHead, random_array[0]);
			head_nrpax = newHead;
			
			nodeQ_t *newHead_submission = EMPTYNODE;
			st = deleteNodes(head_submission, &newHead_submission, random_array[0]);
			head_submission = newHead_submission;	

			nodeQ_t* ptr1 = head_nrpax;
			nodeQ_t* ptr2 = head_submission;

			TEST_ASSERT_NOT_NULL(head_submission);

			compareLists(ptr1, ptr2);
		}
}

void test_splitLists(){
		
		//printf("test_splitLists\n");
		nodeQ_t *evenList = EMPTYNODE;
		nodeQ_t *oddList = EMPTYNODE;

		status_t st = splitLists_nrpax(head_nrpax, &evenList, &oddList);

		nodeQ_t *evenList_submission = EMPTYNODE;
		nodeQ_t *oddList_submission = EMPTYNODE;

		st = splitLists(head_submission, &evenList_submission, &oddList_submission);
		//printList_nrpax(head_nrpax);
		//printList_nrpax(evenList);
		//printList_nrpax(evenList_submission);
		//printList_nrpax(oddList);
		//printList_nrpax(oddList_submission);

		compareLists(evenList, evenList_submission);
		compareLists(oddList, oddList_submission);
}

void test_getCommonSubList(){
		{
				//printf("test_getCommonSubList\n\n");
				short randArr[10] = {0};

				for(short i=0; i<10; i++){
						randArr[i] = rand() % 512;
				}
				nodeQ_t* head1 = createList_nrpax(randArr, 10);  

				for(short i=0; i<10; i++){
						randArr[i] = rand() % 512;
				}
				nodeQ_t* head2 = createList_nrpax(randArr, 10); 

				nodeQ_t* ptr1 = head1;
				nodeQ_t* ptr2 = head2;

				while(ptr1->next && ptr2->next){
						ptr1 = ptr1->next;
						ptr2 = ptr2->next;
				}

				for(short i=0; i<10; i++) {
						randArr[i] = rand() % 512;
				}
				nodeQ_t* head3 = createList_nrpax(randArr, 10); 

				ptr1->next = head3;
				ptr2->next = head3;

				//printList_nrpax(head1);
				//printList_nrpax(head2);
				//printList_nrpax(head3);

				nodeQ_t* out_commonSubList = EMPTYNODE;
				status_t st = getCommonSubList_nrpax(head1, head2, &out_commonSubList);

				nodeQ_t* out_commonSubList_submission = EMPTYNODE;
				st = getCommonSubList(head1, head2, &out_commonSubList_submission);

				TEST_ASSERT_NOT_NULL(out_commonSubList_submission);

				compareLists(out_commonSubList, out_commonSubList_submission);

		}

		{
				//printf("test_getCommonSubList\n\n");
				short randArr[20] = {0};

				for(short i=0; i<8; i++){
						randArr[i] = rand() % 512;
				}
				nodeQ_t* head1 = createList_nrpax(randArr, 8);  

				for(short i=0; i<12; i++){
						randArr[i] = rand() % 512;
				}
				nodeQ_t* head2 = createList_nrpax(randArr, 12); 

				nodeQ_t* ptr1 = head1;
				nodeQ_t* ptr2 = head2;

				while(ptr1->next && ptr2->next){
						ptr1 = ptr1->next;
						ptr2 = ptr2->next;
				}

				for(short i=0; i<6; i++) {
						randArr[i] = rand() % 512;
				}
				nodeQ_t* head3 = createList_nrpax(randArr, 6); 

				ptr1->next = head3;
				ptr2->next = head3;

				//printList_nrpax(head1);
				//printList_nrpax(head2);
				//printList_nrpax(head3);

				nodeQ_t* out_commonSubList = EMPTYNODE;
				status_t st = getCommonSubList_nrpax(head1, head2, &out_commonSubList);

				nodeQ_t* out_commonSubList_submission = EMPTYNODE;
				st = getCommonSubList(head1, head2, &out_commonSubList_submission);

				TEST_ASSERT_NOT_NULL(out_commonSubList_submission);

				compareLists(out_commonSubList, out_commonSubList_submission);

		}


}

void setUp (void) {} 
void tearDown (void) {} 

int main(void){

		UNITY_BEGIN();

		srand(time(0));

		RUN_TEST(test_createList);
		RUN_TEST(test_deleteNodes);
		RUN_TEST(test_splitLists);
		RUN_TEST(test_getCommonSubList);


		UNITY_END();

		return 0;
}
