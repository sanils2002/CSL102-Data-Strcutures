/**
 * We have seen how to implement stack ADT in C
 * In Lab 4 assignment, you will implement an advanced stack ADT
 * Instead of implementing a single stack, you will implement a 2D stack ADT,
 * i.e., a stack ADT that uses 2D arrays for implementation.
 * How you implement a 2D array in this lab is your choice.
 * 
 * 
 * Shown Example visualization of 2D Stacks ADT
 * In this example there are a total of 7 stacks.
 * Each stack is identified using the row number in the 2D array.
 * Every stack in the example has its own Top Of Stack.
 * The numbers separated by comma are elements in the respective stack.	
 * This is just one example.					
 *   rows							
 *   0	    2,  23, 757, 57, 52, 542	<-- stack 0
 *   1	    54, 75,	57				    <-- stack 1
 *   2	    45,	6,	76,	57			    <-- stack 2
 *   3	    54,	63					    <-- stack 3
 *   4	    46,	71,	7,	17			    <-- stack 4
 *   5	    3,	63,	1,	6,	3		    <-- stack 5
 *   6	    25,	6,	2,	2,	9,	7	    <-- stack 6
 * 
 * 
 * In Lab 4 assignment, you will implement a 2D stack ADT with the following public operations.
 * You are allowed to have as many private operations as you may like. 
 * 
*/

/**
 * What to submit:
 * - YourRollNumber.c file (no spaces, no special characters, no names in the filename)
 * - DO NOT implement main function inside YourRollNumber.c
 * 
 * What NOT to submit:
 * - main.c is provided with the this header file. Implement your main function in main.c
 */

/**
 * Grading policy:
 * - Total grade points: 4
 * - Plagiarism (copying from each other): 100% penalty.
 * - Compilation/Linker error: 100% penalty
 */ 

/**
 * The total number of elements that each stack can hold
 * */
#define MAX_SIZE_EACH_STACK 10

/**
 * The total number of stacks in the 2D stack ADT
 * */
#define NUM_STACK_ROWS 5

/**
 * The type stackRow_t can be used instead of unsigned short
 */ 
typedef unsigned short stackRow_t;

/**
 * This enumeration is used for 
 * */
typedef enum{
    STACK_TRUE = 0,
    STACK_FALSE = 1
} status_t;

/**
 * This function will initiliaze the 2D stack ADT in memory
 * */
void init();

/**
 * This function will reset the 2D stack ADT in memory to its original state
 * */
void reset();

/**
 * Insert element on top of all the current elements inside the stack. The newly pushed element become top of the stack.
 * in_val: Value to be pushed.
 * row: The index value of the stack in the 2D stack
 * return STACK_TRUE if the operation is successful
 * return STACK_FALSE if the stack is already full  
 * */
status_t push(int in_val, stackRow_t row);

/**
 * Remove and return the element at the top of the stack (if the stack is not empty).
 * out_val: Address of the variable to be updated with the value at top of the stack
 * row: The index value of the stack in the 2D stack 
 * return STACK_TRUE if the operation is successful
 * return STACK_FALSE if the stack is already empty 
 * */
status_t pop(int* out_val, stackRow_t row);

/**
 * Get (return) the top data element of the stack, without removing it (if the stack is not empty).
 * out_val: Address of the variable to be updated with the value at top of the stack
 * row: The index value of the stack in the 2D stack 
 * return STACK_TRUE if the operation is successful
 * return STACK_FALSE if the stack is already empty 
 * */
status_t peek(int* out_val, stackRow_t row);