#include <stdio.h>
#include "unity.h"
#include "csl102lab2.h"

void sort_arr_unity(int arr[], unsigned short sz){
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

int csl102_diff_2smallest_2biggest_unity(int arr[], unsigned short sz){
		sort_arr_unity(arr, sz);
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

unsigned short csl102_is_array_sorted_unity(int arr[], unsigned short sz){
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

int csl102_find_duplicate_unity(int arr[], unsigned short sz){
		sort_arr_unity(arr, sz);
		for(int i=1; i<=sz; i++){
				if (arr[i] == arr[i-1]){
						return arr[i];
				}
		}
		return -1;
}

void test1(void){
		int arr[] = {4,65,87,13,78,89,6,75,9,5,54,7,85};
		TEST_ASSERT_EQUAL_INT(csl102_diff_2smallest_2biggest_unity(arr, sizeof(arr)/sizeof(arr[0])), csl102_diff_2smallest_2biggest(arr, sizeof(arr)/sizeof(arr[0])));
}

void test2(void){
		int arr[] = {-4,-65,-87,-13,-78,-89,-6,-75,-9,-5,-54,-7,-85}; 
		TEST_ASSERT_EQUAL_INT(csl102_diff_2smallest_2biggest_unity(arr, sizeof(arr)/sizeof(arr[0])), csl102_diff_2smallest_2biggest(arr, sizeof(arr)/sizeof(arr[0])));

}

void test3(void){
		int arr[] = {4,65,-87,13,-78,89,-6,75,-9,5,-54,7,85}; 
		TEST_ASSERT_EQUAL_INT(csl102_diff_2smallest_2biggest_unity(arr, sizeof(arr)/sizeof(arr[0])), csl102_diff_2smallest_2biggest(arr, sizeof(arr)/sizeof(arr[0])));
}

void test4(void){
		int arr[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1}; 
		TEST_ASSERT_EQUAL_INT(csl102_diff_2smallest_2biggest_unity(arr, sizeof(arr)/sizeof(arr[0])), csl102_diff_2smallest_2biggest(arr, sizeof(arr)/sizeof(arr[0])));

}

void test5(void){
		int arr[] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX,INT_MAX}; 
		TEST_ASSERT_EQUAL_INT(csl102_diff_2smallest_2biggest_unity(arr, sizeof(arr)/sizeof(arr[0])), csl102_diff_2smallest_2biggest(arr, sizeof(arr)/sizeof(arr[0])));
}

void test6(void){
		int arr[] = {INT_MIN, INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN};
		TEST_ASSERT_EQUAL_INT(csl102_diff_2smallest_2biggest_unity(arr, sizeof(arr)/sizeof(arr[0])), csl102_diff_2smallest_2biggest(arr, sizeof(arr)/sizeof(arr[0])));
}

void test7(void){
		int arr[] = {INT_MIN, 0,INT_MIN,0,INT_MIN,1,INT_MIN,1,INT_MIN,2};
		TEST_ASSERT_EQUAL_INT(csl102_diff_2smallest_2biggest_unity(arr, sizeof(arr)/sizeof(arr[0])), csl102_diff_2smallest_2biggest(arr, sizeof(arr)/sizeof(arr[0])));
}


void test8(void){

		int arr[] = {INT_MIN, INT_MAX,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MAX,INT_MIN,INT_MIN,-INT_MAX};  
		TEST_ASSERT_EQUAL_INT(csl102_diff_2smallest_2biggest_unity(arr, sizeof(arr)/sizeof(arr[0])), csl102_diff_2smallest_2biggest(arr, sizeof(arr)/sizeof(arr[0])));
}

void test9(void){
	int arr[] = {1,2,3,4,5,6,7,8,9,10}; 
	TEST_ASSERT_EQUAL_INT(csl102_find_duplicate_unity(arr, sizeof(arr)/sizeof(arr[0])), csl102_find_duplicate(arr, sizeof(arr)/sizeof(arr[0])));

}

void test10(void){
	int arr[] = {1,2,3,4,5,6,7,8,1,10}; 
	TEST_ASSERT_EQUAL_INT(csl102_find_duplicate_unity(arr, sizeof(arr)/sizeof(arr[0])), csl102_find_duplicate(arr, sizeof(arr)/sizeof(arr[0])));
}

void test11(void){
	int arr[] = {1,2,3,4,5,6,2,8,9,10}; 
	TEST_ASSERT_EQUAL_INT(csl102_find_duplicate_unity(arr, sizeof(arr)/sizeof(arr[0])), csl102_find_duplicate(arr, sizeof(arr)/sizeof(arr[0])));
}

void test12(void){
	int arr[] = {23,354,43,6,5,74,476,26,247,2457,24766,2457}; 
	TEST_ASSERT_EQUAL_INT(csl102_find_duplicate_unity(arr, sizeof(arr)/sizeof(arr[0])), csl102_find_duplicate(arr, sizeof(arr)/sizeof(arr[0])));
}

void test13(void){
	int arr[] = {1,2,3,4,5,6,7,8,9,10}; 
	TEST_ASSERT_EQUAL_INT(csl102_is_array_sorted_unity(arr, sizeof(arr)/sizeof(arr[0])), csl102_is_array_sorted(arr, sizeof(arr)/sizeof(arr[0])));

}

void test14(void){
	int arr[] = {10,9,8,7,6,5,3,2,1}; 
	TEST_ASSERT_EQUAL_INT(csl102_is_array_sorted_unity(arr, sizeof(arr)/sizeof(arr[0])), csl102_is_array_sorted(arr, sizeof(arr)/sizeof(arr[0])));
}

void test15(void){
	int arr[] = {INT_MIN, INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MAX,INT_MAX}; 
	TEST_ASSERT_EQUAL_INT(csl102_is_array_sorted_unity(arr, sizeof(arr)/sizeof(arr[0])), csl102_is_array_sorted(arr, sizeof(arr)/sizeof(arr[0])));
}

void test16(void){
	int arr[] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10}; 
	TEST_ASSERT_EQUAL_INT(csl102_is_array_sorted_unity(arr, sizeof(arr)/sizeof(arr[0])), csl102_is_array_sorted(arr, sizeof(arr)/sizeof(arr[0])));
}

void test17(void){
	int arr[] = {32,5742,75,4527,745,745,57,57317,77,7,7,7,75,135,7135,23}; 
	TEST_ASSERT_EQUAL_INT(csl102_is_array_sorted_unity(arr, sizeof(arr)/sizeof(arr[0])), csl102_is_array_sorted(arr, sizeof(arr)/sizeof(arr[0])));
}

void test18(void){
	int arr[] = {INT_MIN, -INT_MAX, INT_MAX-2, INT_MAX-1, INT_MAX}; 
	TEST_ASSERT_EQUAL_INT(csl102_is_array_sorted_unity(arr, sizeof(arr)/sizeof(arr[0])), csl102_is_array_sorted(arr, sizeof(arr)/sizeof(arr[0])));
}

void test19(void){
	int arr[] = {-2,-2,-2,-2,-2,-3}; 
	TEST_ASSERT_EQUAL_INT(csl102_is_array_sorted_unity(arr, sizeof(arr)/sizeof(arr[0])), csl102_is_array_sorted(arr, sizeof(arr)/sizeof(arr[0])));
}

void test20(void){
	int arr[] = {0,0,0,0,0,0,0,0,0,0,0,0,1,1}; 
	TEST_ASSERT_EQUAL_INT(csl102_is_array_sorted_unity(arr, sizeof(arr)/sizeof(arr[0])), csl102_is_array_sorted(arr, sizeof(arr)/sizeof(arr[0])));
}

void setUp (void) {} 
void tearDown (void) {} 

int main(void){

		UNITY_BEGIN();

		RUN_TEST(test1);
		RUN_TEST(test2);
		RUN_TEST(test3);
		RUN_TEST(test4);
		RUN_TEST(test5);
		RUN_TEST(test6);
		RUN_TEST(test7);
		RUN_TEST(test8);
		RUN_TEST(test9);
		RUN_TEST(test10);
		RUN_TEST(test11);
		RUN_TEST(test12);
		RUN_TEST(test13);
		RUN_TEST(test14);
		RUN_TEST(test15);
		RUN_TEST(test16);
		RUN_TEST(test17);
		RUN_TEST(test18);
		RUN_TEST(test19);
		RUN_TEST(test20);

		UNITY_END();

		return 0;
}
