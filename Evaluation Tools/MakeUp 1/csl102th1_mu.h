/**
 * This make up assignment is intended for those who had compilation error or were listed for plagiarism
 * 
 * Total grade points: 50% deduction on 8
 * 
 * In this assignment you will be given a 2D array of characters - twoD_arr
 * In addition, you will be given another 1D array of characters - inp_str
 * For every row in twoD_arr, find a contiguous subarray with exact sequence of characters in inp_str
 * Return the row number and maximum length of a continous subarray
 * 
 * Consider the following example:
 * 
 * twoD_arr
 *   row
 *   0	    f, c, e, a, c, e, x, y, z	<-- row 0
 *   1	    a, g, e, a, v, e, e, c, a	<-- row 1
 *   2	    a, c, e, a, c, e, x, y, o	<-- row 2
 *   3	    a, c, e, h, c, e, x, u, z	<-- row 3
 *   4	    a, c, e, a, i, e, x, t, z	<-- row 4
 *   5	    r, c, e, v, c, e, t, y, a	<-- row 5
 * 
 * let inp_str be [a, c, e]
 * 
 * In this example,
 * -    at row #0, #3, #4  a, c, e (inp_str) appear in the exact sequence only once
 * -    at row #2, a, c, e (inp_str) appear in the exact sequence twice
 * -    at row #1 and #5 a, c, e (inp_str) does not appear in exact sequence
 * 
 * Thus, row #2 has maximum length of a continuous subarray
 * 
 * A similar problem is available at https://leetcode.com/problems/contiguous-array/ 
 *
 * */

/**
 * What to submit:
 * - YourRollNumber.c file (no spaces, no special characters, no names in the filename)
 * - DO NOT implement main function inside YourRollNumber.c
 * - Implement main function in a separate file and DO NOT submit it.
 */

/**
 * Grading policy:
 * - Total grade points: 4
 * - Plagiarism (copying from each other): 100% penalty.
 * - Compilation/Linker error: 100% penalty
 */ 

#define CSL102_NUM_ROWS 5
#define CSL102_NUM_COLUMNS 8
#define CSL102_INP_LEN 3

/**
 * For every row in twoD_arr, find a contiguous subarray with exact sequence of characters in inp_str
 * Values to be output by updating values at given address:
 * - out_rowNum: row number that has maximum length of a continous subarray (inp_str) 
 * - out_maxLen: maximum length of a continous subarray (inp_str) at out_rowNum
 * */
void csl102_continuous_subarray(
    char twoD_arr[CSL102_NUM_ROWS][CSL102_NUM_COLUMNS],
    char inp_str[CSL102_INP_LEN],
    unsigned short* out_rowNum,
    unsigned short* out_maxLen
);