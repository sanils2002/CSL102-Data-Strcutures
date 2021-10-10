#include <stdio.h>
#include <stdlib.h>
#include "csl102_lab8.h"

#define TRUE 1
#define FALSE 0
#define NUM_NODES 12

nodeQ_t* createNode(short value);
nodeQ_t* buildTreeFromArr (short inorder[], short start, short end);

short isValidFlippedBST(nodeQ_t* node)
{
		if (EMPTYNODE == node)
				return TRUE;

		if ((EMPTYNODE != node->left && node->left->data < node->data) ||  
						(EMPTYNODE != node->right && node->right->data > node->data))
				return FALSE;

		if (FALSE == isValidFlippedBST(node->left) || FALSE == isValidFlippedBST(node->right))
				return FALSE;

		return TRUE;
}

short isValidBST(nodeQ_t* node)
{
		if (EMPTYNODE == node)
				return TRUE;

		if ((EMPTYNODE != node->left && node->left->data > node->data) ||  
						(EMPTYNODE != node->right && node->right->data < node->data))
				return FALSE;

		if (FALSE == isValidBST(node->left) || FALSE == isValidBST(node->right))
				return FALSE;

		return TRUE;
}

void printTree(nodeQ_t* root, short space){
		if (root == EMPTYNODE)
				return;

		space += 10;

		printTree(root->right, space);

		printf("\n\n");
		for (short i = 10; i < space; i++)
				printf(" ");
		printf("%d\n\n", root->data);

		printTree(root->left, space);
}

nodeQ_t* createNode(short value){
		nodeQ_t *node = (nodeQ_t *)malloc(sizeof(nodeQ_t));
		node->data = value;
		node->left = EMPTYNODE;
		node->right = EMPTYNODE;
		return node;
}

short maxArray (short arr[], short strt, short end)
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

nodeQ_t* buildTree (short inorder[], short start, short end){
		if (start > end)
				return EMPTYNODE;

		short i = maxArray(inorder, start, end);

		nodeQ_t*  root = createNode(inorder[i]);

		if (start == end)
				return root;

		root->left  = buildTreeFromArr (inorder, start, i-1);
		root->right = buildTreeFromArr (inorder, i+1, end);

		return root;
}

void inorderToArray(nodeQ_t* node, short inorder_arr[], unsigned short* pIdx){
		if (EMPTYNODE == node) return;
		inorderToArray(node->left, inorder_arr, pIdx);
		inorder_arr[*pIdx] = node->data; (*pIdx)++;
		inorderToArray(node->right, inorder_arr, pIdx);
}

void swap(short *a, short *b){
		short temp = *a;
		*a = *b;
		*b = temp;
}

void sort(short arr[], unsigned short n){
		for (short i = 0; i < n-1; i++){	
				for (short j = 0; j < n-i-1; j++){
						if (arr[j] > arr[j+1]){
								swap(&arr[j], &arr[j+1]);
						}
				}
		}
}

nodeQ_t* arrayToBST(nodeQ_t* root, short inorder_arr[], unsigned short* pIdx)
{
		if (EMPTYNODE == root) return EMPTYNODE;
		arrayToBST(root->left, inorder_arr, pIdx);
		root->data = inorder_arr[*pIdx];
		(*pIdx)++;
		arrayToBST(root->right, inorder_arr, pIdx);

		return root;
}

nodeQ_t* convertBinaryTree2BST(nodeQ_t* binTreeRoot){

		if(EMPTYNODE == binTreeRoot) return EMPTYNODE;

		short inorder_arr[64] = {0};
		unsigned short outSz = 0;

		inorderToArray(binTreeRoot, inorder_arr, &outSz);
		sort(inorder_arr, outSz);

		outSz = 0;
		binTreeRoot = arrayToBST(binTreeRoot, inorder_arr, &outSz);

		return binTreeRoot;
}

nodeQ_t *flipBST(nodeQ_t *bstRoot){
		if (EMPTYNODE == bstRoot) return EMPTYNODE;
		nodeQ_t *tmp = EMPTYNODE;
		tmp = bstRoot->left;
		bstRoot->left = bstRoot->right;
		bstRoot->right = tmp;
		flipBST(bstRoot->left);
		flipBST(bstRoot->right);
		return bstRoot;
}

short removeDuplicatesFromArr(short arr[], short sz){
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

nodeQ_t* mergeTwoBSTs(nodeQ_t* bst1Root, nodeQ_t* bst2Root){
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
    inorderToArray(bst1Root, mergedArr, &mergedSz);

	sort(mergedArr, mergedSz);
	
	short newSz = removeDuplicatesFromArr(mergedArr, mergedSz);

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

	return convertBinaryTree2BST(newRoot);
}