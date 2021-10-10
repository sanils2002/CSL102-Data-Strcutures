/**
 *
Instructions:
0. Failure to follow instructions will lead to ZERO marks

1. You must implement following functions.

2. DO NOT change function names, output type, input type etc.

3. Comment out the main function before submitting, or simply delete the main function. 

4. Implement all the functions in this C file. Rename it as YourRollNo.c - e.g., bt20cse019.c. 
- NO SPACES, name or any other characters
- Entire filename is LOWER CASE only
- Submit only this c file. 

5. The header file csl102lab2.h must be in the same folder/directory as your C file when you
implement. DO NOT submit the header file.

6. Failure to do 3 and 4 will result in ZERO marks.

7. Compilation error will result in ZERO marks.

8. Late submission will result in ZERO marks.

9. IF and ONLY IF Moodle does not let you upload the file, email me immediately 
- email subject: CSL 102 Lab assignment 2

10. DO NOT delete any comments in the file.

11. Failure in submitting the correct file will result in a ZERO.

12. You can add a new function in the file. If you do so, DO NOT delete the function while submission.

13. If you add a printf or scanf statement in the code, comment/delete before submitting
 **/

#include <stdio.h> /*removing stdio.h is fine*/
#include "csl102th1.h" /*do not remove*/

/**
 * In this exercise, you must sort the first half of the array in ascending order
 * and the second half of the array in descending order.
 * 
 * For example, [21, 0, 6, -3, 56, -2, 8, 99] must be sorted into
 * [-3, 0, 6, 21, 99, 56, 8, -2]
 * 
 * You can use any sorting technique taught in the class. You can reuse the code.
 * 
 * Assume that the size of the array will be even.
 * 
 * arr = input array to be sorted 
 * sz = number of elements in the array. Assume sz to be even and greater than 4.
 * 
 * */
void csl102_left_right_sort(int arr[], unsigned short sz){

}

/**
 * In this function, a character array will be given to you. In addition, a series of strings (2d character array) will be given. For each string in this series, find if there exists an exact match in the character array. If yes, replace the entire match in the character array with the given replacement character.
 * 
 * For example, 
 * Original arrToUpdate = "the hero of this movie looked like a monk who sold his ferrari"
 * And a series of string =  "hero", "monk", "sole" is given
 * And the replacement character 'x' is also given, here is the updated string
 * Updated arrToUpdate = "the xxxx of this movie looked like a xxxx who sold his ferrari"
 * 
 * In the example above, the original arrToUpdate has the words - hero and monk. They are replaced with character 'x'
 * The string "sole" does not have exact match (although it has partial match sol in "sole" & "sold"). Thus no replacement in done.
 * 
 * Function parameters:
 * arrToUpdate = input array that will be updated if match is found in strings.
 * szArr = size of arrToUpdate
 * multiple_strings = array of strings to be compared for match. NUM_COLUMNS is defined in csl102th1.h
 * rows = number of rows in the 2d array multiple_strings
 * replacementChar = character using which arrToUpdate will be updated.
 * */
void csl102_update_string(char arrToUpdate[], 
				unsigned short szArr, 
				char multiple_strings[][NUM_COLUMNS], 
				unsigned short rows, 
				char replacementChar){
}

/**
 * Comment out the main function (or delete it entirely) before submitting
 * No marks will be awarded if the main function is left uncommented
 * All code in main is sample code for your reference
 * You can change it as per your wish
 * */
int main(){
		char arr[] = "the hero of this movie looked like a monk who sold his ferrari";
		/*NUM_COLUMNS is defined in csl102th1.h*/
		char string[3][NUM_COLUMNS] = {
				"hero",
				"monk",
				"sole"
		};

		printf("original array = %s\n", arr);
		csl102_update_string(arr, sizeof(arr)/sizeof(arr[0]), string, 3, 'x');
		printf("updated array = %s\n", arr);

		return 0;
}