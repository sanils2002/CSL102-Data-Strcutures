#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "csl102_lab8.h"
#include <time.h>

#define TRUE_QWERTY 1
#define FALSE_QWERTY 0
#define NUM_NODES_QWERTY 12

nodeQ_t* createNode_qwerty(short value);
nodeQ_t* buildTreeFromArr (short inorder[], short start, short end);

short isValidFlippedBST_qwerty(nodeQ_t* node)
{
		if (EMPTYNODE == node)
				return TRUE_QWERTY;

		if ((EMPTYNODE != node->left && node->left->data < node->data) ||  
						(EMPTYNODE != node->right && node->right->data > node->data))
				return FALSE_QWERTY;

		if (FALSE_QWERTY == isValidFlippedBST_qwerty(node->left) || FALSE_QWERTY == isValidFlippedBST_qwerty(node->right))
				return FALSE_QWERTY;

		return TRUE_QWERTY;
}

short isValidBST_qwerty(nodeQ_t* node)
{
		if (EMPTYNODE == node)
				return TRUE_QWERTY;

		if ((EMPTYNODE != node->left && node->left->data > node->data) ||  
						(EMPTYNODE != node->right && node->right->data < node->data))
				return FALSE_QWERTY;

		if (FALSE_QWERTY == isValidBST_qwerty(node->left) || FALSE_QWERTY == isValidBST_qwerty(node->right))
				return FALSE_QWERTY;

		return TRUE_QWERTY;
}

void printTree_qwerty(nodeQ_t* root, short space){
		if (root == EMPTYNODE)
				return;

		space += 10;

		printTree_qwerty(root->right, space);

		printf("\n\n");
		for (short i = 10; i < space; i++)
				printf(" ");
		printf("%d\n\n", root->data);

		printTree_qwerty(root->left, space);
}

nodeQ_t* createNode_qwerty(short value){
		nodeQ_t *node = (nodeQ_t *)malloc(sizeof(nodeQ_t));
		node->data = value;
		node->left = EMPTYNODE;
		node->right = EMPTYNODE;
		return node;
}

short maxInArray (short arr[], short strt, short end)
{
		short i, max = arr[strt], maxind = strt;
		for(i = strt+1; i <= end; i++)
		{
				if(arr[i] > max)
				{
						max = arr[i];
						maxind = i;
				}
		}
		return maxind;
}

nodeQ_t* buildTreeFromArr (short inorder[], short start, short end){
		if (start > end)
				return EMPTYNODE;

		short i = maxInArray(inorder, start, end);

		nodeQ_t*  root = createNode_qwerty(inorder[i]);

		if (start == end)
				return root;

		root->left  = buildTreeFromArr (inorder, start, i-1);
		root->right = buildTreeFromArr (inorder, i+1, end);

		return root;
}

void inorderToArray_qwerty(nodeQ_t* node, short inorder_arr[], unsigned short* pIdx){
		if (EMPTYNODE == node) return;
		inorderToArray_qwerty(node->left, inorder_arr, pIdx);
		inorder_arr[*pIdx] = node->data; (*pIdx)++;
		inorderToArray_qwerty(node->right, inorder_arr, pIdx);
}

void swap_qwerty(short *a, short *b){
		short temp = *a;
		*a = *b;
		*b = temp;
}

void sort_qwerty(short arr[], unsigned short n){
		for (short i = 0; i < n-1; i++){	
				for (short j = 0; j < n-i-1; j++){
						if (arr[j] > arr[j+1]){
								swap_qwerty(&arr[j], &arr[j+1]);
						}
				}
		}
}

nodeQ_t* arrayToBST_qwerty(nodeQ_t* root, short inorder_arr[], unsigned short* pIdx)
{
		if (EMPTYNODE == root) return EMPTYNODE;
		arrayToBST_qwerty(root->left, inorder_arr, pIdx);
		root->data = inorder_arr[*pIdx];
		(*pIdx)++;
		arrayToBST_qwerty(root->right, inorder_arr, pIdx);

		return root;
}

nodeQ_t* convertBinaryTree2BST_qwerty(nodeQ_t* binTreeRoot){

		if(EMPTYNODE == binTreeRoot) return EMPTYNODE;

		short inorder_arr[64] = {0};
		unsigned short outSz = 0;

		inorderToArray_qwerty(binTreeRoot, inorder_arr, &outSz);
		sort_qwerty(inorder_arr, outSz);

		outSz = 0;
		binTreeRoot = arrayToBST_qwerty(binTreeRoot, inorder_arr, &outSz);

		return binTreeRoot;
}

nodeQ_t *flipBST_qwerty(nodeQ_t *bstRoot){
		if (EMPTYNODE == bstRoot) return EMPTYNODE;
		nodeQ_t *tmp = EMPTYNODE;
		tmp = bstRoot->left;
		bstRoot->left = bstRoot->right;
		bstRoot->right = tmp;
		flipBST_qwerty(bstRoot->left);
		flipBST_qwerty(bstRoot->right);
		return bstRoot;
}

short removeDuplicatesFromArr_qwerty(short arr[], short sz){
    if (sz < 2) return sz;

    short ret_idx = 0;

    for (short i = 0; i < sz - 1; i++){
        if (arr[i] != arr[i + 1]){
            arr[ret_idx] = arr[i];
			ret_idx++;
		}
	}

    arr[ret_idx++] = arr[sz - 1];

    return ret_idx;
}

nodeQ_t* mergeTwoBSTs_qwerty(nodeQ_t* bst1Root, nodeQ_t* bst2Root){
	// it is assumed that bst1Root and bst2Root is not true
	
	nodeQ_t* node = bst1Root;

	while(EMPTYNODE != node){
		if(EMPTYNODE == node->left){
			node->left = bst2Root;
			break;
		}

		if(EMPTYNODE == node->right){
			node->right = bst2Root;
			break;
		}

		node = node->left;
	}

	short mergedArr[1024] = {0};
    unsigned short mergedSz = 0;
    inorderToArray_qwerty(bst1Root, mergedArr, &mergedSz);

	sort_qwerty(mergedArr, mergedSz);
	
	short newSz = removeDuplicatesFromArr_qwerty(mergedArr, mergedSz);

	// this randomization is optional. without this, the tree will be degenrate
	short tmp = mergedArr[0];
	mergedArr[0] = mergedArr[mergedSz/2];
	mergedArr[mergedSz/2] = tmp;

	tmp = mergedArr[mergedSz-1];
	mergedArr[mergedSz-1] = mergedArr[mergedSz/3];
	mergedArr[mergedSz/3] = tmp;

	tmp = mergedArr[mergedSz-2];
	mergedArr[mergedSz-2] = mergedArr[mergedSz/4];
	mergedArr[mergedSz/4] = tmp;
	/////////

    nodeQ_t* newRoot = buildTreeFromArr(mergedArr, 0, newSz-1);

	return convertBinaryTree2BST_qwerty(newRoot);
}

void test_convertBinaryTree2BST_qwerty(){

		for(short counter = 0; counter < 5; counter++){

				short random_array[NUM_NODES_QWERTY] = {0};
				for(short i=0; i<NUM_NODES_QWERTY; i++){
						random_array[i] = rand() % 4096;
				}

				nodeQ_t* root_qwerty = buildTreeFromArr(random_array, 0, NUM_NODES_QWERTY-1);

				//generateTree_qwerty();
				//printf("%d\n", isValidBST_qwerty(root_qwerty));
				//printTree_qwerty(root_qwerty, 0);
				//printf("\n\n===============================\n\n");
				root_qwerty = convertBinaryTree2BST(root_qwerty);
				//printTree_qwerty(root_qwerty, 0);
				//printf("\n\n===============================\n\n");
				//printf("%d\n", isValidBST_qwerty(root_qwerty));
				TEST_ASSERT_EQUAL_INT16(TRUE_QWERTY, isValidBST_qwerty(root_qwerty));
		}
}

void test_mergeTwoBSTs_qwerty(){

		for(short counter = 0; counter < 5; counter++){

				short random_array[NUM_NODES_QWERTY] = {0};
				for(short i=0; i<NUM_NODES_QWERTY; i++){
						random_array[i] = rand() % 4096;
				}

				nodeQ_t* root_qwerty1 = buildTreeFromArr(random_array, 0, NUM_NODES_QWERTY-1);

				for(short i=0; i<NUM_NODES_QWERTY; i++){
						random_array[i] = rand() % 4096;
				}

				nodeQ_t* root_qwerty2 = buildTreeFromArr(random_array, 0, NUM_NODES_QWERTY-1);

				root_qwerty1 = convertBinaryTree2BST_qwerty(root_qwerty1);
				root_qwerty2 = convertBinaryTree2BST_qwerty(root_qwerty2);

				nodeQ_t* merged_qwerty = mergeTwoBSTs(root_qwerty1, root_qwerty2);

				//printTree_qwerty(merged_qwerty, 0);
				//printf("\n\n===============================\n\n");

				TEST_ASSERT_EQUAL_INT16(TRUE_QWERTY, isValidBST_qwerty(merged_qwerty));
		}
}

void test_flipBST_qwerty(){

		for(short counter = 0; counter < 5; counter++){

				short random_array[NUM_NODES_QWERTY] = {0};
				for(short i=0; i<NUM_NODES_QWERTY; i++){
						random_array[i] = rand() % 4096;
				}

				nodeQ_t* root_qwerty = buildTreeFromArr(random_array, 0, NUM_NODES_QWERTY-1);

				//generateTree_qwerty();
				//printf("%d\n", isValidBST_qwerty(root_qwerty));
				//printTree_qwerty(root_qwerty, 0);
				//printf("\n\n\n\n\n\n\n\n\n\n\n\n");

				root_qwerty = convertBinaryTree2BST_qwerty(root_qwerty);
				//printTree_qwerty(root_qwerty, 0);
				//printf("\n\n===============================\n\n");

				root_qwerty = flipBST(root_qwerty);
				//printTree_qwerty(root_qwerty, 0);
				//printf("\n\n===============================\n\n");
				//printf("%d\n", isValidBST_qwerty(root_qwerty));
				TEST_ASSERT_EQUAL_INT16(TRUE_QWERTY, isValidFlippedBST_qwerty(root_qwerty));
		}
}

void setUp (void) {} 
void tearDown (void) {} 

int main(void){

		srand(time(0));

		UNITY_BEGIN();

		RUN_TEST(test_convertBinaryTree2BST_qwerty);
		RUN_TEST(test_flipBST_qwerty);
		RUN_TEST(test_mergeTwoBSTs_qwerty);

		UNITY_END();

		return 0;
}
