#include <stdio.h>
#include "unity.h"
#include "csl102th1.h"

void swap_th1(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort_th1(int arr[], int start_index, int end_index, unsigned short isDescending){
	for (int i = start_index; i < end_index-1; i++){	
	    for (int j = start_index; j < start_index+end_index-i-1; j++){
            /*printf("%d\t%d\n", i, j);*/
            
            if(1 == isDescending){
                 if (arr[j] < arr[j+1]){
			        swap_th1(&arr[j], &arr[j+1]);
                }
            }
            else{
		        if (arr[j] > arr[j+1]){
			        swap_th1(&arr[j], &arr[j+1]);
                }
            }
        }
    }
    /*printf("\n");*/
}

void csl102_left_right_sort_th1(int arr[], unsigned short sz){
    bubbleSort_th1(arr, 0, sz/2, 0);
    bubbleSort_th1(arr, sz/2, sz, 1);
}

void csl102_update_string_th1(char arr[], unsigned short szArr, char strings[][NUM_COLUMNS], unsigned short rows, char replacementChar){
    for(int r = 0; r < rows; r++){
        int c = 0;
        for (int i=0; i<szArr; i++){
            if(arr[i] ==  strings[r][c]){
                c++;
                if(NUM_COLUMNS == c){
                    while(c > 0){
                        --c;
                        arr[i - c] =  replacementChar;
                    }
                }
            }
            else{
                c = 0;
            }
        }
    }
}

void print_array_th1(int arr[], int size){
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void test1(void){
		int arr[] = {4,65,87,13,78,89,6,75,9,5,54,7};
		int arr1[] = {4,65,87,13,78,89,6,75,9,5,54,7};

		/*print_array_th1(arr, sizeof(arr)/sizeof(arr[0]));*/
		csl102_left_right_sort_th1(arr, sizeof(arr)/sizeof(arr[0]));
		csl102_left_right_sort(arr1, sizeof(arr1)/sizeof(arr1[0]));
		/*print_array_th1(arr, sizeof(arr)/sizeof(arr[0]));*/

		TEST_ASSERT_EQUAL_INT32_ARRAY(arr, arr1, sizeof(arr)/sizeof(arr[0]));	
}

void test2(void){
		int arr[] = {-4,-65,-87,-13,-78,-89}; 
		int arr1[] = {-4,-65,-87,-13,-78,-89}; 

		/*print_array_th1(arr, sizeof(arr)/sizeof(arr[0]));*/
		csl102_left_right_sort_th1(arr, sizeof(arr)/sizeof(arr[0]));
		csl102_left_right_sort(arr1, sizeof(arr1)/sizeof(arr1[0]));
		/*print_array_th1(arr, sizeof(arr)/sizeof(arr[0]));*/

		TEST_ASSERT_EQUAL_INT32_ARRAY(arr, arr1, sizeof(arr)/sizeof(arr[0]));	

}

void test3(void){
		int arr[] = {4,65,-87,13,-78,89,-6,75}; 
		int arr1[] = {4,65,-87,13,-78,89,-6,75}; 

		csl102_left_right_sort_th1(arr, sizeof(arr)/sizeof(arr[0]));
		csl102_left_right_sort(arr1, sizeof(arr1)/sizeof(arr1[0]));
		/*print_array_th1(arr, sizeof(arr)/sizeof(arr[0]));*/

		TEST_ASSERT_EQUAL_INT32_ARRAY(arr, arr1, sizeof(arr)/sizeof(arr[0]));	
}

void test4(void){
		int arr[] = {3,0,0,INT_MAX,0,0,0,0,0,0,0,3,0,INT_MAX,0,0,0,1,1,0,1,1,1,-INT_MAX,1,1,1,1}; 
		int arr1[] = {3,0,0,INT_MAX,0,0,0,0,0,0,0,3,0,INT_MAX,0,0,0,1,1,0,1,1,1,-INT_MAX,1,1,1,1};

		csl102_left_right_sort_th1(arr, sizeof(arr)/sizeof(arr[0]));
		csl102_left_right_sort(arr1, sizeof(arr1)/sizeof(arr1[0]));
		/*print_array_th1(arr, sizeof(arr)/sizeof(arr[0]));*/

		TEST_ASSERT_EQUAL_INT32_ARRAY(arr, arr1, sizeof(arr)/sizeof(arr[0]));		

}

void test5(void){
		int arr[] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX,INT_MAX}; 
		int arr1[] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX,INT_MAX}; 

		csl102_left_right_sort_th1(arr, sizeof(arr)/sizeof(arr[0]));
		csl102_left_right_sort(arr1, sizeof(arr1)/sizeof(arr1[0]));
		/*print_array_th1(arr, sizeof(arr)/sizeof(arr[0]));*/

		TEST_ASSERT_EQUAL_INT32_ARRAY(arr, arr1, sizeof(arr)/sizeof(arr[0]));	
}

void test6(void){
		int arr[] = {INT_MIN, INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN, -881, -879, -757, -401, -396, -301, -290, 186, 359, 951};
		int arr1[] = {INT_MIN, INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN, -881, -879, -757, -401, -396, -301, -290, 186, 359, 951};
		
		
		csl102_left_right_sort_th1(arr, sizeof(arr)/sizeof(arr[0]));
		csl102_left_right_sort(arr1, sizeof(arr1)/sizeof(arr1[0]));
		/*print_array_th1(arr, sizeof(arr)/sizeof(arr[0]));*/

		TEST_ASSERT_EQUAL_INT32_ARRAY(arr, arr1, sizeof(arr)/sizeof(arr[0]));		
}

void test7(void){
		int arr[] = {-881, -879, -757, -401, -396, -301, -290, 186, 359, 951};
		int arr1[] = {-881, -879, -757, -401, -396, -301, -290, 186, 359, 951};

		/*print_array_th1(arr, sizeof(arr)/sizeof(arr[0]));*/
		csl102_left_right_sort_th1(arr, sizeof(arr)/sizeof(arr[0]));
		csl102_left_right_sort(arr1, sizeof(arr1)/sizeof(arr1[0]));
		/*print_array_th1(arr, sizeof(arr)/sizeof(arr[0]));*/

		TEST_ASSERT_EQUAL_INT32_ARRAY(arr, arr1, sizeof(arr)/sizeof(arr[0]));	
}

void test8(void){

		int arr[] = {-834265799, -704944547, -562330306, -122169078, -64204554, -49312836, -38634888, 21662496, 257277388, 343092515, 356894963, 400285722, 420600524, 518078994, 527509489, 601594903, 727447488, 743007031, 812248053, 850007108}; 

		int arr1[] = {-834265799, -704944547, -562330306, -122169078, -64204554, -49312836, -38634888, 21662496, 257277388, 343092515, 356894963, 400285722, 420600524, 518078994, 527509489, 601594903, 727447488, 743007031, 812248053, 850007108};  

		csl102_left_right_sort_th1(arr, sizeof(arr)/sizeof(arr[0]));
		csl102_left_right_sort(arr1, sizeof(arr1)/sizeof(arr1[0]));
		/*print_array_th1(arr, sizeof(arr)/sizeof(arr[0]));*/

		TEST_ASSERT_EQUAL_INT32_ARRAY(arr, arr1, sizeof(arr)/sizeof(arr[0]));	
}


void test9(void){
	char arr1[] = "the hero of this movie looked like a monk who sold his ferrari";
	char arr2[] = "the hero of this movie looked like a monk who sold his ferrari";

    char string[4][NUM_COLUMNS] = {
                        "hero",
                        "monk",
                        "sole",
                        "like"
                        };

    csl102_update_string_th1(arr1, sizeof(arr1)/sizeof(arr1[0]), string, 4, 'x');
	csl102_update_string(arr2, sizeof(arr2)/sizeof(arr2[0]), string, 4, 'x');

	TEST_ASSERT_EQUAL_CHAR_ARRAY(arr1, arr2, sizeof(arr1)/sizeof(arr1[0]));
}

void test10(void){
	char arr1[] = "the hero of this movie looked lime a monkey who sole his ferrari";
	char arr2[] = "the hero of this movie looked lime a monkey who sole his ferrari";

    char string[4][NUM_COLUMNS] = {
                        "hero",
                        "monk",
                        "sole",
                        "like"
                        };

    csl102_update_string_th1(arr1, sizeof(arr1)/sizeof(arr1[0]), string, 4, 'x');
	csl102_update_string(arr2, sizeof(arr2)/sizeof(arr2[0]), string, 4, 'x');
	/*printf("%s\n", arr1);*/

	TEST_ASSERT_EQUAL_CHAR_ARRAY(arr1, arr2, sizeof(arr1)/sizeof(arr1[0]));
}

void test11(void){
	char arr1[] = "In a day, when you dont come across any problems, you can be sure that you are travelling in a wrong path";
	char arr2[] = "In a day, when you dont come across any problems, you can be sure that you are travelling in a wrong path";

    char string[5][NUM_COLUMNS] = {
                        "dont",
                        "sure",
                        "that",
                        "rong",
						"path"
                        };

    csl102_update_string_th1(arr1, sizeof(arr1)/sizeof(arr1[0]), string, 5, 'r');
	csl102_update_string(arr2, sizeof(arr2)/sizeof(arr2[0]), string, 5, 'r');
	/*printf("%s\n", arr1);*/

	TEST_ASSERT_EQUAL_CHAR_ARRAY(arr1, arr2, sizeof(arr1)/sizeof(arr1[0]));
}

void test12(void){
	char arr1[] = "It is the coming together of little things in an organized manner that always goes to make a great thing. Great characters do not come up as ready made products in a day. They are built silently and their glorious heights scaled inch by inch and step by step.";

	char arr2[] = "It is the coming together of little things in an organized manner that always goes to make a great thing. Great characters do not come up as ready made products in a day. They are built silently and their glorious heights scaled inch by inch and step by step.";

    char string[5][NUM_COLUMNS] = {
                        "toge",
                        "inch",
                        "come",
                        "sent",
						"goal"
                        };

    csl102_update_string_th1(arr1, sizeof(arr1)/sizeof(arr1[0]), string, 5, 'r');
	csl102_update_string(arr2, sizeof(arr2)/sizeof(arr2[0]), string, 5, 'r');
	/*printf("%s\n", arr1);*/

	TEST_ASSERT_EQUAL_CHAR_ARRAY(arr1, arr2, sizeof(arr1)/sizeof(arr1[0]));
}

void test13(void){
	char arr1[] = "There are some, who sacrifice their lives in a flash of martyrdom. True, that is also glorious and inspiring. But to burn oneself every moment of one’s life in order to light up countless other hearts is a tapasya of the highest order";

	char arr2[] = "There are some, who sacrifice their lives in a flash of martyrdom. True, that is also glorious and inspiring. But to burn oneself every moment of one’s life in order to light up countless other hearts is a tapasya of the highest order";

    char string[5][NUM_COLUMNS] = {
                        "dont",
                        "sure",
                        "true",
                        "rong",
						"path"
                        };

    csl102_update_string_th1(arr1, sizeof(arr1)/sizeof(arr1[0]), string, 5, 'z');
	csl102_update_string(arr2, sizeof(arr2)/sizeof(arr2[0]), string, 5, 'z');
	/*printf("%s\n", arr1);*/

	TEST_ASSERT_EQUAL_CHAR_ARRAY(arr1, arr2, sizeof(arr1)/sizeof(arr1[0]));

}

void test14(void){
	char arr1[] = "Dream is not that which you see while sleeping it is something that does not let your sleep";

	char arr2[] = "Dream is not that which you see while sleeping it is something that does not let your sleep";

    char string[1][NUM_COLUMNS] = {
                        "does"
                        };

    csl102_update_string_th1(arr1, sizeof(arr1)/sizeof(arr1[0]), string, 1, '*');
	csl102_update_string(arr2, sizeof(arr2)/sizeof(arr2[0]), string, 1, '*');
	/*printf("%s\n", arr1);*/

	TEST_ASSERT_EQUAL_CHAR_ARRAY(arr1, arr2, sizeof(arr1)/sizeof(arr1[0]));
}

void test15(void){
	char arr1[] = "We shall fight on the beaches, we shall fight on the landing grounds, we shall fight in the fields and in the streets, we shall fight in the hills; we shall never surrender";

	char arr2[] = "We shall fight on the beaches, we shall fight on the landing grounds, we shall fight in the fields and in the streets, we shall fight in the hills; we shall never surrender";

    char string[2][NUM_COLUMNS] = {
                        "land",
                        "hill"
                        };

    csl102_update_string_th1(arr1, sizeof(arr1)/sizeof(arr1[0]), string, 2, '^');
	csl102_update_string(arr2, sizeof(arr2)/sizeof(arr2[0]), string, 2, '^');
	/*printf("%s\n", arr1);*/

	TEST_ASSERT_EQUAL_CHAR_ARRAY(arr1, arr2, sizeof(arr1)/sizeof(arr1[0]));
}

void test16(void){
	char arr1[] = "Genius is one percent inspiration and ninety-nine percent perspiration.";
	char arr2[] = "Genius is one percent inspiration and ninety-nine percent perspiration.";

    char string[5][NUM_COLUMNS] = {
                        "dont",
                        "sure",
                        "that",
                        "rong",
						"path"
                        };

    csl102_update_string_th1(arr1, sizeof(arr1)/sizeof(arr1[0]), string, 5, 'x');
	csl102_update_string(arr2, sizeof(arr2)/sizeof(arr2[0]), string, 5, 'x');
	/*printf("%s\n", arr1);*/

	TEST_ASSERT_EQUAL_CHAR_ARRAY(arr1, arr2, sizeof(arr1)/sizeof(arr1[0]));
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

		UNITY_END();

		return 0;
}
