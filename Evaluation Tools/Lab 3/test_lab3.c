#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "csl102_lab3.h"


void csl102_swap_unity(short* a, short* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void csl102_merge_unity(short arr[], int left_index, int middle_index, int right_index)
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

void csl102_merge_sort_unity(short arr[], int left_index, int right_index)
{
	if (left_index < right_index) {
		int middle_index = (left_index + right_index) / 2;

		/*recursively sort first and second halves*/
		csl102_merge_sort_unity(arr, left_index, middle_index);
		csl102_merge_sort_unity(arr, middle_index + 1, right_index);

		csl102_merge_unity(arr, left_index, middle_index, right_index);
	}
}

unsigned long csl102_diff_k_median_unity(
    short array[], 
    unsigned short szArr,
    unsigned short k){
    unsigned long ret = UINT32_MAX;
    //csl102_bubbleSort_unity(array, 0, szArr, 0);
	csl102_merge_sort_unity(array, 0, szArr-1);
    unsigned short idx = 0;
    
    for (unsigned short i = 0; i < szArr-1; i++){
        if(array[i+1] > array[i]){
            /*printf("idx = %d\n", idx);*/
            idx++;
            if(k == idx){
                ret = (unsigned long)abs(array[szArr/2] - array[i]);
                break;
            }
        }
    }
    return ret;
}

void csl102_sort_lab3_unity(
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
    csl102_merge_sort_unity(combinedArray, 0, (int)(szArrOne + szArrTwo - 1));
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
        csl102_swap_unity(&arrayTwo[start++], &arrayTwo[end--]);
    }

	return;
}


void test1_csl102_diff_k_median(void){
	short arr[]={11,2,3,4,5,6,7,8,9,10,1}; // 6 is median unsorted or sorted 
	TEST_ASSERT_EQUAL_UINT32(
	csl102_diff_k_median_unity(arr, sizeof(arr)/sizeof(arr[0]), 3), 
	csl102_diff_k_median(arr, sizeof(arr)/sizeof(arr[0]), 3)
	);
}

void test2_csl102_diff_k_median(void){
	short arr[]={-11,12,13,-11,-50,16,50,51,51,51,100}; // 16 is median unsorted or sorted 
	TEST_ASSERT_EQUAL_UINT32(
	csl102_diff_k_median_unity(arr, sizeof(arr)/sizeof(arr[0]), 6), 
	csl102_diff_k_median(arr, sizeof(arr)/sizeof(arr[0]), 6)
	);
}

void test3_csl102_diff_k_median(void){
	short arr[]={-1,1,-1,1,-1,1,-1,1,-1,1,2,3,4,4,4,4,4,4,5,6,6}; // 2 is median unsorted or sorted
	TEST_ASSERT_EQUAL_UINT32(
	csl102_diff_k_median_unity(arr, sizeof(arr)/sizeof(arr[0]), 1), 
	csl102_diff_k_median(arr, sizeof(arr)/sizeof(arr[0]), 1)
	);
}

void test4_csl102_diff_k_median(void){
	short arr[]={1,1,1,1,1,1,1,1,1,1,5,22,22,33,33,14,14,15,15,66,66}; // 5 is median unsorted or sorted 
	TEST_ASSERT_EQUAL_UINT32(
	csl102_diff_k_median_unity(arr, sizeof(arr)/sizeof(arr[0]), 6), 
	csl102_diff_k_median(arr, sizeof(arr)/sizeof(arr[0]), 6)
	);

}

void test5_csl102_sort_lab3(void){
	short arrayOne[] = {1,5,2,9,19,-4, 747};
    short arrayTwo[] = {6,-113,57,-52,74, -634, 0};
	short arrayOneUnity[] = {1,5,2,9,19,-4, 747};
    short arrayTwoUnity[] = {6,-113,57,-52,74, -634, 0};
	csl102_sort_lab3(arrayOne, sizeof(arrayOne)/sizeof(arrayOne[0]), 
    arrayTwo, sizeof(arrayTwo)/sizeof(arrayTwo[0]));
	csl102_sort_lab3_unity(arrayOneUnity, sizeof(arrayOneUnity)/sizeof(arrayOneUnity[0]), 
    arrayTwoUnity, sizeof(arrayTwoUnity)/sizeof(arrayTwoUnity[0]));
	TEST_ASSERT_EQUAL_INT16_ARRAY(arrayOne, arrayOneUnity, sizeof(arrayOne)/sizeof(arrayOne[0]));
	TEST_ASSERT_EQUAL_INT16_ARRAY(arrayTwo, arrayTwoUnity, sizeof(arrayTwo)/sizeof(arrayTwo[0]));
}

void test6_csl102_sort_lab3(void){
	short arrayOne[] = {1,5,2,9,19,-4, 747};
    short arrayTwo[] = {6,-113,57,-52,74, -634, 0};
	short arrayOneUnity[] = {1,5,2,9,19,-4, 747};
    short arrayTwoUnity[] = {6,-113,57,-52,74, -634, 0};
	csl102_sort_lab3(arrayOne, sizeof(arrayOne)/sizeof(arrayOne[0]), 
    arrayTwo, sizeof(arrayTwo)/sizeof(arrayTwo[0]));
	csl102_sort_lab3_unity(arrayOneUnity, sizeof(arrayOneUnity)/sizeof(arrayOneUnity[0]), 
    arrayTwoUnity, sizeof(arrayTwoUnity)/sizeof(arrayTwoUnity[0]));
	TEST_ASSERT_EQUAL_INT16_ARRAY(arrayOne, arrayOneUnity, sizeof(arrayOne)/sizeof(arrayOne[0]));
	TEST_ASSERT_EQUAL_INT16_ARRAY(arrayTwo, arrayTwoUnity, sizeof(arrayTwo)/sizeof(arrayTwo[0]));
}

void test7_csl102_sort_lab3(void){
	short arrayOne[] = {1,5,2,9,19,-4, 747};
    short arrayTwo[] = {6,-113,57,-52,74, -634, 0};
	short arrayOneUnity[] = {1,5,2,9,19,-4, 747};
    short arrayTwoUnity[] = {6,-113,57,-52,74, -634, 0};
	csl102_sort_lab3(arrayOne, sizeof(arrayOne)/sizeof(arrayOne[0]), 
    arrayTwo, sizeof(arrayTwo)/sizeof(arrayTwo[0]));
	csl102_sort_lab3_unity(arrayOneUnity, sizeof(arrayOneUnity)/sizeof(arrayOneUnity[0]), 
    arrayTwoUnity, sizeof(arrayTwoUnity)/sizeof(arrayTwoUnity[0]));
	TEST_ASSERT_EQUAL_INT16_ARRAY(arrayOne, arrayOneUnity, sizeof(arrayOne)/sizeof(arrayOne[0]));
	TEST_ASSERT_EQUAL_INT16_ARRAY(arrayTwo, arrayTwoUnity, sizeof(arrayTwo)/sizeof(arrayTwo[0]));
}


void test8_csl102_sort_lab3(void){
	short arrayOne[] = {1,5,2,9,19,-4, 747};
    short arrayTwo[] = {6,-113,57,-52,74, -634, 0};
	short arrayOneUnity[] = {1,5,2,9,19,-4, 747};
    short arrayTwoUnity[] = {6,-113,57,-52,74, -634, 0};
	csl102_sort_lab3(arrayOne, sizeof(arrayOne)/sizeof(arrayOne[0]), 
    arrayTwo, sizeof(arrayTwo)/sizeof(arrayTwo[0]));
	csl102_sort_lab3_unity(arrayOneUnity, sizeof(arrayOneUnity)/sizeof(arrayOneUnity[0]), 
    arrayTwoUnity, sizeof(arrayTwoUnity)/sizeof(arrayTwoUnity[0]));
	TEST_ASSERT_EQUAL_INT16_ARRAY(arrayOne, arrayOneUnity, sizeof(arrayOne)/sizeof(arrayOne[0]));
	TEST_ASSERT_EQUAL_INT16_ARRAY(arrayTwo, arrayTwoUnity, sizeof(arrayTwo)/sizeof(arrayTwo[0]));
}

void test9_csl102_sort_lab3(void){
	short arrayOne[] = {1,5,2,9,19,-4, 747};
    short arrayTwo[] = {6,-113,57,-52,74, -634, 0};
	short arrayOneUnity[] = {1,5,2,9,19,-4, 747};
    short arrayTwoUnity[] = {6,-113,57,-52,74, -634, 0};
	csl102_sort_lab3(arrayOne, sizeof(arrayOne)/sizeof(arrayOne[0]), 
    arrayTwo, sizeof(arrayTwo)/sizeof(arrayTwo[0]));
	csl102_sort_lab3_unity(arrayOneUnity, sizeof(arrayOneUnity)/sizeof(arrayOneUnity[0]), 
    arrayTwoUnity, sizeof(arrayTwoUnity)/sizeof(arrayTwoUnity[0]));
	TEST_ASSERT_EQUAL_INT16_ARRAY(arrayOne, arrayOneUnity, sizeof(arrayOne)/sizeof(arrayOne[0]));
	TEST_ASSERT_EQUAL_INT16_ARRAY(arrayTwo, arrayTwoUnity, sizeof(arrayTwo)/sizeof(arrayTwo[0]));
}

void test10_csl102_sort_lab3(void){
	short arrayOne[] = {1,5,2,9,19,-4, 747};
    short arrayTwo[] = {6,-113,57,-52,74, -634, 0};
	short arrayOneUnity[] = {1,5,2,9,19,-4, 747};
    short arrayTwoUnity[] = {6,-113,57,-52,74, -634, 0};
	csl102_sort_lab3(arrayOne, sizeof(arrayOne)/sizeof(arrayOne[0]), 
    arrayTwo, sizeof(arrayTwo)/sizeof(arrayTwo[0]));
	csl102_sort_lab3_unity(arrayOneUnity, sizeof(arrayOneUnity)/sizeof(arrayOneUnity[0]), 
    arrayTwoUnity, sizeof(arrayTwoUnity)/sizeof(arrayTwoUnity[0]));
	TEST_ASSERT_EQUAL_INT16_ARRAY(arrayOne, arrayOneUnity, sizeof(arrayOne)/sizeof(arrayOne[0]));
	TEST_ASSERT_EQUAL_INT16_ARRAY(arrayTwo, arrayTwoUnity, sizeof(arrayTwo)/sizeof(arrayTwo[0]));
}

void test11_csl102_sort_lab3(void){
	short arrayOne[] = {1,5,2,9,19,-4, 747};
    short arrayTwo[] = {6,-113,57,-52,74, -634, 0};
	short arrayOneUnity[] = {1,5,2,9,19,-4, 747};
    short arrayTwoUnity[] = {6,-113,57,-52,74, -634, 0};
	csl102_sort_lab3(arrayOne, sizeof(arrayOne)/sizeof(arrayOne[0]), 
    arrayTwo, sizeof(arrayTwo)/sizeof(arrayTwo[0]));
	csl102_sort_lab3_unity(arrayOneUnity, sizeof(arrayOneUnity)/sizeof(arrayOneUnity[0]), 
    arrayTwoUnity, sizeof(arrayTwoUnity)/sizeof(arrayTwoUnity[0]));
	TEST_ASSERT_EQUAL_INT16_ARRAY(arrayOne, arrayOneUnity, sizeof(arrayOne)/sizeof(arrayOne[0]));
	TEST_ASSERT_EQUAL_INT16_ARRAY(arrayTwo, arrayTwoUnity, sizeof(arrayTwo)/sizeof(arrayTwo[0]));
}

void test12_csl102_sort_lab3(void){
	short arrayOne[] = {1,5,2,9,19,-4, 747};
    short arrayTwo[] = {6,-113,57,-52,74, -634, 0};
	short arrayOneUnity[] = {1,5,2,9,19,-4, 747};
    short arrayTwoUnity[] = {6,-113,57,-52,74, -634, 0};
	csl102_sort_lab3(arrayOne, sizeof(arrayOne)/sizeof(arrayOne[0]), 
    arrayTwo, sizeof(arrayTwo)/sizeof(arrayTwo[0]));
	csl102_sort_lab3_unity(arrayOneUnity, sizeof(arrayOneUnity)/sizeof(arrayOneUnity[0]), 
    arrayTwoUnity, sizeof(arrayTwoUnity)/sizeof(arrayTwoUnity[0]));
	TEST_ASSERT_EQUAL_INT16_ARRAY(arrayOne, arrayOneUnity, sizeof(arrayOne)/sizeof(arrayOne[0]));
	TEST_ASSERT_EQUAL_INT16_ARRAY(arrayTwo, arrayTwoUnity, sizeof(arrayTwo)/sizeof(arrayTwo[0]));
}

void setUp (void) {} 
void tearDown (void) {} 

int main(void){

		UNITY_BEGIN();

		RUN_TEST(test1_csl102_diff_k_median);
		RUN_TEST(test2_csl102_diff_k_median);
		RUN_TEST(test3_csl102_diff_k_median);
		RUN_TEST(test4_csl102_diff_k_median);
		RUN_TEST(test5_csl102_sort_lab3);
		RUN_TEST(test6_csl102_sort_lab3);
		RUN_TEST(test7_csl102_sort_lab3);
		RUN_TEST(test8_csl102_sort_lab3);
		RUN_TEST(test9_csl102_sort_lab3);
		RUN_TEST(test10_csl102_sort_lab3);
		RUN_TEST(test11_csl102_sort_lab3);
		RUN_TEST(test12_csl102_sort_lab3);

		UNITY_END();

		return 0;
}
