#include "csl102_lab3.h"
/* Check header file for documentation on these functions*/
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

void swap(short* a, short* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(short arr[], int left_index, int middle_index, int right_index)
{
	int sz_left_arr = middle_index - left_index + 1;
	int sz_right_arr = right_index - middle_index;

	/* create temporary arrays */
	int left_arr[sz_left_arr], right_arr[sz_right_arr];

	/* Copy data to left_arr[] and right_arr[] */
	for (int i = 0; i < sz_left_arr; i++)
		left_arr[i] = arr[left_index + i];

	for (int j = 0; j < sz_right_arr; j++)
		right_arr[j] = arr[middle_index + 1 + j];

	int i, j, k;
	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; /* starting index of left_arr */
	j = 0; /* starting index of right_arr */
	k = left_index; /* starting index of merged subarray */
	while (i < sz_left_arr && j < sz_right_arr) {
		if (left_arr[i] <= right_arr[j]) {
			arr[k] = left_arr[i];
			i++;
		}
		else {
			arr[k] = right_arr[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of left_arr[], if there
	are any */
	while (i < sz_left_arr) {
		arr[k] = left_arr[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of right_arr[], if there
	are any */
	while (j < sz_right_arr) {
		arr[k] = right_arr[j];
		j++;
		k++;
	}
}

void merge_sort_func(short arr[], int left_index, int right_index)
{
	if (left_index < right_index) {
		int middle_index = (left_index + right_index) / 2;

		/*recursively sort first and second halves*/
		merge_sort_func(arr, left_index, middle_index);
		merge_sort_func(arr, middle_index + 1, right_index);

		merge(arr, left_index, middle_index, right_index);
	}
}


/*
void bubbleSort(short arr[], unsigned short start, unsigned short n, unsigned short dsc){
    for (unsigned short i = start; i < n-1; i++){	
	    for (unsigned short j = start; j < start+n-i-1; j++){
            //printf("%d\t%d\n", i, j);
            
            if(1 == dsc){
                 if (arr[j] < arr[j+1]){
			        swap(&arr[j], &arr[j+1]);
                }
            }
            else{
		        if (arr[j] > arr[j+1]){
			        swap(&arr[j], &arr[j+1]);
                }
            }
        }
    }
    //printf("\n");
}
*/


unsigned long csl102_diff_k_median(
    short array[], 
    unsigned short szArr,
    unsigned short k
){
    unsigned long ret = UINT32_MAX;
    //bubbleSort(array, 0, szArr, 0);
    merge_sort_func(array, 0, szArr-1);
    unsigned short idx = 0;
    
    for (unsigned short i = 0; i < szArr-1; i++){
        if(array[i+1] > array[i]){
            //printf("idx = %d\n", idx);
            idx++;
            if(k == idx){
                ret = (unsigned long)abs(array[szArr/2] - array[i]);
                break;
            }
        }
    }

    return ret;
}

/*
unsigned short getLargestIdx(short arr[], unsigned short sz){
    short largest = SHRT_MIN;
    unsigned short largestIdx = 0;
    for(unsigned short idx = 0; idx < sz; idx++){
        short val = arr[idx];
        if (largest < val){
            largest = val;
            largestIdx = idx;
        }
    }
    return largestIdx;
}
*/

/*
unsigned short compareArrays(short arrayOne[], 
unsigned short szArrOne,
short arrayTwo[],
unsigned short szArrTwo){
    unsigned short retVal = 1;

    for(unsigned short i = 0; i < szArrOne; i++){
        for(unsigned short j = 0; j < szArrTwo; j++){
            if(arrayOne[i] > arrayTwo[j]){
                retVal = 0;
                break;
            }
        }
    }

    return retVal;
}
*/

/*
void _print_array_func(short arr[], unsigned short size){
	for (unsigned short i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
*/

void csl102_sort_lab3(
short arrayOne[], 
unsigned short szArrOne,
short arrayTwo[],
unsigned short szArrTwo){

    short combinedArray[szArrOne + szArrTwo];

    for(unsigned short i = 0; i < szArrOne; i++){
        combinedArray[i] = arrayOne[i];
    }

    for(unsigned short i = szArrOne; i < szArrOne + szArrTwo; i++){
        combinedArray[i] = arrayTwo[i - szArrOne];
    }

    //_print_array_func(combinedArray, szArrOne + szArrTwo);
    merge_sort_func(combinedArray, 0, (int)(szArrOne + szArrTwo - 1));
    //_print_array_func(combinedArray, szArrOne + szArrTwo);

    for(unsigned short i = 0; i < szArrOne; i++){
        arrayOne[i] = combinedArray[i];
    }

    //_print_array_func(arrayOne, szArrOne);

    for(unsigned short i = szArrOne; i < szArrOne + szArrTwo; i++){
        arrayTwo[i-szArrOne] = combinedArray[i];
    }
    //_print_array_func(arrayTwo, szArrTwo);

    unsigned short start = 0;
    unsigned short end = szArrTwo - 1;

    while(start < end){
        swap(&arrayTwo[start++], &arrayTwo[end--]);
    }

    /*
    unsigned short isLeftLessThanRight = 
    compareArrays(arrayOne, szArrOne, arrayTwo, szArrTwo);

    while(!isLeftLessThanRight){
        unsigned short largestIdx = 
        getLargestIdx(arrayOne, szArrOne);

        for(unsigned short j = 0; j < szArrTwo; j++){
            if(arrayOne[largestIdx] > arrayTwo[j]){
                short temp = arrayOne[largestIdx];
                arrayOne[largestIdx] = arrayTwo[j];
                arrayTwo[j] = temp;
                break;
            }
        }

        isLeftLessThanRight = 
        compareArrays(arrayOne, szArrOne, arrayTwo, szArrTwo);
    }

    bubbleSort(arrayOne, 0, szArrOne, 0);
    bubbleSort(arrayTwo, 0, szArrTwo, 1);
    */

    return;
}