/**
 * In this lab for CSL 102, you will implement inorder, preorder and postorder traversal
 * using iterative logic (non-recursion).
 * 
 * To verify that no recursive logic is used, all submissions will be made open to all 
 * students of CSL 102 after the submission deadline. It will responsibility of students
 * to bring to instructor's attention if somebody has used recursion.
 * 
 * Instructor will keep it anonymous if students reports use of recursion by other students.
 * 
 * Students are free to lookup code over the Internet. 
 * 
 * Submission acceptable only via Moodle. If Moodle is down, take screenshot and email the 
 * submission along with the screenshot. The subject of email must contain roll no and 
 * the lab number (lab 6). If you submit without the screenshot for Moodle down, your submission
 * will not be accepted.
 * 
 * Submission deadline Monday June 21 @ 6am.
 * 
 * Compilation error = ZERO
 * Submission filename not having your roll no = ZERO
 * Pleading for marks despite compilation error = NEGATIVE FOUR
 * Pleading for marks without running evalution tool = NEGATIVE FOUR
 * Copying code from each other = NEGATIVE FOUR
 * Keeping main function in the submission code = NEGATIVE FOUR
 * Keep the file extension in lower case c
 * 
 * Note: 
 * * The stack implementation demonstrated in the lecture is limited to single array only
 * * 
 * * You can use the implementation for createnode function as shown in the class or 
 * * implement on your own
 * *
 * * For non-recursive implementation, you can use any data structure of your choice 
 * * 
 * Suggestion:
 * * Implement the main function in a separate c file and not in the submission c file
 * */

#define EMPTYNODE 0

struct node {
	short data;
	struct node* left;
	struct node* right;
};

typedef struct node nodeQ_t;

/**
 * Function for getting inorder traversal of tree
 * Assume unique values in each node
 * Don't assume the tree to be binary search tree
 * Node can have positive or negative values
 * 
 * The input node could be root of the entire tree or a root of a subtree
 * 
 * out_array must contain the inorder traversal order of the tree
 * out_array will be updated by your implementation
 * The contents of out_array will be compared to correct traversal order
 * Assume the size of out_array to be large (e.g., 1024)
 * 
 * out_size must contain the number of elements in the traversal order.
 * In other words, out_size will the value of total number of nodes in the tree.
 * out_size will be updated by your implementation
 **/
void getInorder(nodeQ_t* node, short **out_array, short *out_size);

/**
 * Function for getting preorder traversal of tree
 * Assume unique values in each node
 * Don't assume the tree to be binary search tree
 * Node can have positive or negative values
 * 
 * The input node could be root of the entire tree or a root of a subtree
 * 
 * out_array must contain the preorder traversal order of the tree
 * out_array will be updated by your implementation
 * The contents of out_array will be compared to correct traversal order
 * Assume the size of out_array to be large (e.g., 1024)
 * 
 * out_size must contain the number of elements in the traversal order.
 * In other words, out_size will the value of total number of nodes in the tree.
 * out_size will be updated by your implementation
 **/
void getPreorder(nodeQ_t* node, short **out_array, short *out_size);

/**
 * Function for getting postorder traversal of tree
 * Assume unique values in each node
 * Don't assume the tree to be binary search tree
 * Node can have positive or negative values
 * 
 * The input node could be root of the entire tree or a root of a subtree
 * 
 * out_array must contain the postorder traversal order of the tree
 * out_array will be updated by your implementation
 * The contents of out_array will be compared to correct traversal order
 * Assume the size of out_array to be large (e.g., 1024)
 * 
 * out_size must contain the number of elements in the traversal order.
 * In other words, out_size will the value of total number of nodes in the tree.
 * out_size will be updated by your implementation
 **/
void getPostorder(nodeQ_t* node, short **out_array, short *out_size);