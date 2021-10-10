/**
 * Take home assignment 2
 * CSL 102 2021
 * Compilation error = 0
 * Late submission = 0
 * Presence of uncommented main function in the submission file = 0
 * Cheating/plagiarism = 0
 * */

#define EMPTYNODE 0

typedef enum{
    LIST_FALSE = 0,
    LIST_TRUE = 1,
} status_t;

struct nodeQ{
    short data;
    struct nodeQ* next;
};

typedef struct nodeQ nodeQ_t;

/**
 * Create a linked list from the values in the array
 * The size of the array could be anywhere from 1 to 1000
 * The data in the list must be in the same order as the input array
 * Return the head node
 * values is the input array
 * sz is the size of the array
 * */
nodeQ_t* createList(short values[], short sz);

/**
 * Delete all nodes whose data value matches the input data value
 * For example, for input data value 7 and input list 5->6->7->7->9->19->2->3->7->11->EMPTYNODE
 * the new list will be 5->6->9->19->2->3->11->EMPTYNODE
 * If the head changes, update the new head using the out_newHead variable
 * If the operation is successful return LIST_TRUE, else LIST_FALSE 
 * */
status_t deleteNodes(nodeQ_t* head, nodeQ_t** out_newHead, short in_data);

/**
 * For a given input list that starts with head, split it into two lists
 * 1) List of all even indices made available using out_evenList
 * 2) List of all odd indices made available using out_oddList
 * For example list 4->6->7->19->5->24->45->1->1->8->EMPTYNODE will be split into
 * out_evenList = 4->7->5->45->1->EMPTYNODE
 * out_oddList = 6->19->24->1->8->EMPTYNODE
 * If the operation is successful return LIST_TRUE, else LIST_FALSE 
 * */
status_t splitLists(nodeQ_t* head, nodeQ_t** out_evenList, nodeQ_t** out_oddList);

/**
 * In this example below the next for nodes 24 and 44 both point to 45
 * head1 = 4->6->7->19->5->24-> \
 *                                ->45->1->1->8->EMPTYNODE
 * head2 =         81->15->44-> /
 * This the common sublist for both the lists is 45->1->1->8->EMPTYNODE
 * 
 * It is possible that the input lists head1 and head2 do not have a sub list in common
 * 
 * If the operation is successful return LIST_TRUE, else LIST_FALSE 
 * If there does not exist a common sublist return LIST_FALSE
 * */
status_t getCommonSubList(nodeQ_t* head1, nodeQ_t* head2, nodeQ_t** out_commonSubList);