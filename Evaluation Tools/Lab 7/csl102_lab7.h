/**
 * CSL 102 Lab 7
 * Submission deadline Thursday July 1 @ 6am
 * 
 * Compilation error = ZERO
 * Submission filename not having your roll no = ZERO
 * Pleading for marks despite compilation error = NEGATIVE FOUR
 * Pleading for marks without running evalution tool = NEGATIVE FOUR
 * Copying code from each other = NEGATIVE FOUR
 * Keeping main function in the submission code = NEGATIVE FOUR
 * Keep the file extension in lower case c
 * 
 * * 
 * Suggestion:
 * * Implement the main function in a separate c file and not in the submission c file
 * */

#define EMPTYNODE 0

struct node {
	short data[4]; // pay attention
	struct node* next;
	struct node* prev;
};

typedef struct node nodeQ_t;

typedef enum{
    LIST_FALSE = 0,
    LIST_TRUE = 1,
} status_t;

/**
 * Example doubly linked list
 * 	   HEAD						   			    TAIL
 * 		|										 |
 * [2,5,1,6] <=> [4,7,8,9] <=> [0,3,6,3] <=> [43,7,32,7] <=> EMPTYNODE
 * */

/**
 * Method to create a node by passing an array. 
 * Create a node on the heap memory and return the address
 **/
nodeQ_t* createNode(short values[4]);

/**
 * Method to append a node after the tail
 * Pointers to head node and new node will be provided as input
 * If the operation is successful return LIST_TRUE, else LIST_FALSE 
 * For invalid address as input, return LIST_FALSE
 **/
status_t appendNode(nodeQ_t* head, nodeQ_t* newNode);

/**
 * Method to prepend a node before the head
 * Pointers to head node and new node will be provided as input
 * If the operation is successful return LIST_TRUE, else LIST_FALSE 
 * For invalid address as input, return LIST_FALSE
 **/
status_t prependNode(nodeQ_t* head, nodeQ_t* newNode);

/**
 * Method to delete a node
 * Instead of the array, only a single value is provided as input.
 * Delete all nodes where data[4] consists of value
 * If the head changes, update the new head using the out_newHead variable
 * If the operation is successful return LIST_TRUE, else LIST_FALSE 
 * For invalid address as input, return LIST_FALSE
 **/
status_t deleteNode(nodeQ_t* head, nodeQ_t** out_newHead, short value);