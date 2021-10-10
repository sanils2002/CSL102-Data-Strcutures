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
**/

#include "csl102lab2.h"

void sort_arr(int arr[], unsigned short sz){
		int key = 0;
		int j = 0;
		for (int i = 1; i < sz; i++) {
				key = arr[i];
				j = i - 1;

				while (j >= 0 && arr[j] > key) {
						arr[j + 1] = arr[j];
						j = j - 1;
				}
				arr[j + 1] = key;
		}
}

/**
 * In this exercise, you find the second largest and second smallest element.
 * The function must return the difference between second largest and second smallest.
 * For example, in the array [21, 7, 6, 13, 56, 2, 8, 99], 
 * 56 is the second largest element and 7 is the second smallest element. 
 * Thus, the function must return 56 - 7 = 49.
 * You can reuse the code @ https://github.com/aniket-acad/csl102_ds_iiitn.
 * arr = starting address of the array. 
 * sz = number of elements in the array. Assume sz will be greater than 4.
 * */
int csl102_diff_2smallest_2biggest(int arr[], unsigned short sz){
		sort_arr(arr, sz);
		/*for (int idx = 0; idx < sz; idx++){
			printf("%d\t", arr[idx]);
			}

			printf("\n");*/

		int smallest2 = arr[0]; 
		int biggest2 = arr[sz-1];
		int foundSmallest2 = 0;
		int foundBiggest2 = 0;

		for (int idx = 1; idx < sz; idx++){

				if(1 == foundSmallest2 && 1 == foundBiggest2){
						break;
				}

				if(0 == foundSmallest2){
						if(arr[idx] > arr[idx - 1]){
								smallest2 = arr[idx];
								foundSmallest2 = 1;
						}
				}

				if(0 == foundBiggest2){
						if(arr[sz-idx-1] < arr[sz-idx]){
								biggest2 = arr[sz-idx-1];
								foundBiggest2 = 1;
						}
				}
		}

		/*printf("big = %d, small = %d, big2 = %d, small2 = %d\n", arr[sz-1], arr[0], biggest2, smallest2);*/

		return biggest2 - smallest2;

}

/**
 * In this exercise you will find if the input array is in a sorted order
 * arr = starting address of the array.
 * If the array is not sorted, return 0
 * If the array is sorted in ascending order, return 1
 * If the array is sorted in descending order, return 2
 * */
unsigned short csl102_is_array_sorted(int arr[], unsigned short sz){
		unsigned short val = 0;
		unsigned short cntAsc = 0;
		unsigned short cntDsc = 0;
		for (int idx = 1; idx < sz; idx++){
				if(arr[idx] >= arr[idx-1])
						cntAsc++;

				if(arr[idx] <= arr[idx-1])
						cntDsc++;
		}

		/*printf("%d, %d\n", cntAsc, cntDsc);*/

		if(cntAsc == cntDsc)
			val = 0;
		else if(sz-1 == cntAsc)
			val = 1;
		else if(sz-1 == cntDsc)
			val = 2;

		return val;
}

/**
 * In this exercise you will find if the input array has duplicate elements
 * Assume maximum one duplicate value
 * For example, in the array [21, 7, 99, 13, 56, 2, 8, 99], 99 is duplicate
 * arr = starting address of the array (has positive values only).
 * If the array has duplicate return the value/element (99 in the example)
 * If the array does not have duplicate return -1.
 * */
int csl102_find_duplicate(int arr[], unsigned short sz){
		sort_arr(arr, sz);
		for(int i=1; i<=sz; i++){
				if (arr[i] == arr[i-1]){
						return arr[i];
				}
		}
		return -1;
}