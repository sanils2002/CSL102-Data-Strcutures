#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "csl102_lab6.h"
#include <time.h>

#define MAX_SIZE_STACK_NRPAX 1024
#define TRUE_NRPAX 1
#define FALSE_NRPAX 0

nodeQ_t* stack_nrpax[MAX_SIZE_STACK_NRPAX] = {0};
short tos_nrpax = -1;
struct node* root_nrpax = EMPTYNODE;

nodeQ_t* createNode_nrpax(short data){
	nodeQ_t* node = (nodeQ_t*)malloc(sizeof(nodeQ_t));
	node->data = data;

	node->left = EMPTYNODE;
	node->right = EMPTYNODE;
	return node;
}

/*
void printTree(nodeQ_t* root, short space){
    if (root == NULL)
        return;
  
    space += 15;
  
    printTree(root->right, space);
  
    printf("\n\n\n");
    for (int i = 15; i < space; i++)
        printf(" ");
    printf("%d\n\n\n", root->data);
  
    printTree(root->left, space);
}

void printInorder(nodeQ_t* node){
    if(!node) 
        return;

    printInorder(node->left); // left
    printf("%d\t", node->data); // root
    printInorder(node->right); // right

}

void printPreorder(nodeQ_t* node){
    if(!node) 
        return;

    printf("%d\t", node->data); // root
    printPreorder(node->left); // left
    printPreorder(node->right); // right

}

void printPostorder(nodeQ_t* node){
    if(!node) 
        return;

    printPostorder(node->left); // left
    printPostorder(node->right); // right
    printf("%d\t", node->data); // root

}
*/

void push_nrpax(nodeQ_t* p_nd){
    if(MAX_SIZE_STACK_NRPAX == tos_nrpax + 1) return;
    stack_nrpax[++tos_nrpax] = p_nd;
    //printf("%d\n", p_nd->data);
}

unsigned short isEmpty_nrpax(){
    if(-1 == tos_nrpax)
        return TRUE_NRPAX;

    return FALSE_NRPAX;
}

nodeQ_t* pop_nrpax(){
    if(FALSE_NRPAX == isEmpty_nrpax()) return stack_nrpax[tos_nrpax--];
    return EMPTYNODE;
}

nodeQ_t* peek_nrpax(){
    if(FALSE_NRPAX == isEmpty_nrpax()) return stack_nrpax[tos_nrpax];
    return EMPTYNODE;
}


void getInorder_nrpax(nodeQ_t* node, short **out_array, short *out_size){
 
    if(EMPTYNODE == node) return;
    if(EMPTYNODE == *out_array) return;
    tos_nrpax = -1;

    nodeQ_t* curr = node;
    short counter = 0;
 
    while(TRUE_NRPAX){
        if(EMPTYNODE != curr){
            push_nrpax(curr);                                              
            curr = curr->left; 
        }    
        else{
            curr = pop_nrpax();
            if(EMPTYNODE != curr){
                (*out_array)[counter++] = curr->data;
                // this will work too: *(*out_array + counter) = curr->data;
                // this will not work: *out_array[counter]
                curr = curr->right;
            }
            else{
                *out_size = counter;
                tos_nrpax = -1;
                return;
            }
        }
    } 
}

void getPreorder_nrpax(nodeQ_t* node, short **out_array, short *out_size){

    if(EMPTYNODE == node) return;
    if(EMPTYNODE == *out_array) return;

    tos_nrpax = -1;
    short counter = 0;

    nodeQ_t* curr = node;
    push_nrpax(curr);

    while(TRUE_NRPAX){

        if(TRUE_NRPAX == isEmpty_nrpax()){
            *out_size = counter;
            tos_nrpax = -1;
            return;
        }

        curr = pop_nrpax();
        if(EMPTYNODE != curr){
            (*out_array)[counter++] = curr->data;
            // this will work too: *(*out_array + counter) = curr->data;
            // this will not work: *out_array[counter]
        }        

        if(EMPTYNODE != curr->right) push_nrpax(curr->right);
        if(EMPTYNODE != curr->left) push_nrpax(curr->left);
    }

    return;
}

void getPostorder_nrpax(nodeQ_t* node, short **out_array, short *out_size){
    
    if(EMPTYNODE == node) return;
    if(EMPTYNODE == *out_array) return;

    tos_nrpax = -1;
    short counter = 0;
    nodeQ_t* curr = node;

    while(TRUE_NRPAX){ 

        while (EMPTYNODE != curr){
            if (EMPTYNODE != curr->right) push_nrpax(curr->right);
            push_nrpax(curr);
            curr = curr->left;
         }

         curr = pop_nrpax();

        if(EMPTYNODE == curr){ 
            // this case should not happen ideally
            *out_size = counter;
            tos_nrpax = -1;
            return;
        } 

        if(EMPTYNODE != curr->right && peek_nrpax() == curr->right){
            pop_nrpax();
            push_nrpax(curr);
            curr = curr->right;
        }
        else{
            (*out_array)[counter++] = curr->data;
            // this will work too: *(*out_array + counter) = curr->data;
            // this will not work: *out_array[counter]
            curr = EMPTYNODE;
        }

        if(TRUE_NRPAX == isEmpty_nrpax()){
            *out_size = counter;
            tos_nrpax = -1;
            return;
        }
      } 
}

void test_inorder(){
	short *out_array_test = (short*)malloc(1024 * sizeof(short));
	short out_size_test = 0;
	
	getInorder_nrpax(root_nrpax, &out_array_test, &out_size_test);

	short *out_array_submission = (short*)malloc(1024 * sizeof(short));
	short out_size_submission = 0;

	getInorder(root_nrpax, &out_array_submission, &out_size_submission);

	TEST_ASSERT_EQUAL_INT16(out_size_test, out_size_submission);
	TEST_ASSERT_EQUAL_UINT16_ARRAY(out_array_test, out_array_submission, out_size_test);

	
	free(out_array_test);
	free(out_array_submission);
}

void test_preorder(){
	short *out_array_test = (short*)malloc(1024 * sizeof(short));
	short out_size_test = 0;
	
	getPreorder_nrpax(root_nrpax, &out_array_test, &out_size_test);

	short *out_array_submission = (short*)malloc(1024 * sizeof(short));
	short out_size_submission = 0;

	getPreorder(root_nrpax, &out_array_submission, &out_size_submission);

	TEST_ASSERT_EQUAL_INT16(out_size_test, out_size_submission);
	TEST_ASSERT_EQUAL_UINT16_ARRAY(out_array_test, out_array_submission, out_size_test);
	
	free(out_array_test);
	free(out_array_submission);
}

void test_postorder(){
	short *out_array_test = (short*)malloc(1024 * sizeof(short));
	short out_size_test = 0;
	
	getPostorder_nrpax(root_nrpax, &out_array_test, &out_size_test);

	short *out_array_submission = (short*)malloc(1024 * sizeof(short));
	short out_size_submission = 0;

	getPostorder(root_nrpax, &out_array_submission, &out_size_submission);

	TEST_ASSERT_EQUAL_INT16(out_size_test, out_size_submission);
	TEST_ASSERT_EQUAL_UINT16_ARRAY(out_array_test, out_array_submission, out_size_test);
	
	free(out_array_test);
	free(out_array_submission);
}

void setUp (void) {} 
void tearDown (void) {} 

int main(void){

	srand(time(0));
	short random_array[64] = {0};

	for(short i=0; i<64; i++){
		random_array[i] = rand() % 512;
	}

	UNITY_BEGIN();

	short idx = 0;

	root_nrpax = createNode_nrpax(random_array[idx++]);
	root_nrpax->left = createNode_nrpax(random_array[idx++]);
	root_nrpax->right = createNode_nrpax(random_array[idx++]);
	
	root_nrpax->left->left = createNode_nrpax(random_array[idx++]);
    root_nrpax->left->right = createNode_nrpax(random_array[idx++]);
    
	root_nrpax->right->left = createNode_nrpax(random_array[idx++]);
    root_nrpax->right->right = createNode_nrpax(random_array[idx++]);
    
	root_nrpax->right->left->left = createNode_nrpax(random_array[idx++]);
    root_nrpax->right->right->right = createNode_nrpax(random_array[idx++]);
    root_nrpax->right->left->right = createNode_nrpax(random_array[idx++]);
    root_nrpax->right->right->left = createNode_nrpax(random_array[idx++]);
    
	root_nrpax->left->left->left = createNode_nrpax(random_array[idx++]);
    root_nrpax->left->right->right = createNode_nrpax(random_array[idx++]);
	root_nrpax->left->left->right = createNode_nrpax(random_array[idx++]);
    root_nrpax->left->right->left = createNode_nrpax(random_array[idx++]);

	root_nrpax->left->left->left->left = createNode_nrpax(random_array[idx++]);
    root_nrpax->left->right->right->left = createNode_nrpax(random_array[idx++]);
	root_nrpax->left->left->right->left = createNode_nrpax(random_array[idx++]);
    root_nrpax->left->right->left->left = createNode_nrpax(random_array[idx++]);

	RUN_TEST(test_inorder);
	RUN_TEST(test_preorder);
	RUN_TEST(test_postorder);

	/*
	printf("Node values:\n");
	for(short i=0; i<idx; i++){
		printf("%d\t", random_array[i]);
	}
	printf("\n\n");

	//printTree(root, 0);

	short *out_array = (short*)malloc(1024 * sizeof(short));
	short out_size = 0;
	
	printf("Inorder: \n");
	printInorder(root);
	printf("\nInorder interative: \n");
	getInorder(root, &out_array, &out_size);
	for(short i =0; i< out_size; i++){
		printf("%d\t", out_array[i]);
	}
	printf("\n\n");

	printf("Preorder: \n");
	printPreorder(root);
	printf("\nPreorder iterative: \n");
	getPreorder(root, &out_array, &out_size);
	for(short i =0; i< out_size; i++){
		printf("%d\t", out_array[i]);
	}
	printf("\n\n");

	printf("Postorder: \n");
	printPostorder(root);
	printf("\nPostorder iterative: \n");
	getPostorder(root, &out_array, &out_size);
	for(short i =0; i< out_size; i++){
		printf("%d\t", out_array[i]);
	}
	printf("\n\n");
	
	free(out_array);
	*/
	
	UNITY_END();

	return 0;
}
