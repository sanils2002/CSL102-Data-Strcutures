#include <stdio.h>
#include "unity.h"
#include "csl102th1_mu.h"


short isMatch(char* arr1, short startIdx, char arr2[CSL102_INP_LEN]){
		for(short i=0; i<CSL102_INP_LEN; i++){

				if(arr1[startIdx + i] != arr2[i])
						return 0;
		}

		return 1;
}

void csl102_continuous_subarray_unity(
				char twoD_arr[CSL102_NUM_ROWS][CSL102_NUM_COLUMNS],
				char inp_str[CSL102_INP_LEN],
				unsigned short* out_rowNum,
				unsigned short* out_maxLen
				)
{
		*out_rowNum = 0;
		*out_maxLen = 0;

		for(short row = 0; row < CSL102_NUM_ROWS; row++){
				short contiguousLen = 0;

				short prevCol = -1;

				for (short col = 0; col < CSL102_NUM_COLUMNS; ){

						if(col + CSL102_INP_LEN <= CSL102_NUM_COLUMNS){

								if(1 == isMatch(twoD_arr[row], col, inp_str)){

										contiguousLen = contiguousLen + CSL102_INP_LEN;

										if(*out_maxLen < contiguousLen){
												*out_maxLen = contiguousLen;
												*out_rowNum = row;
										}

										col = col + CSL102_INP_LEN;

										continue;
								}
								else
										contiguousLen = 0;
						}

						col++;
				}
		}
}

void test1(void){
		char twoD_arr[CSL102_NUM_ROWS][CSL102_NUM_COLUMNS] =
		{
				"qwertyui",
				"asdfghjk",
				"acefqwey",
				"qmqweqwe",
				"qwxevfrt"
		};

		char inp_str[CSL102_INP_LEN] = "qwe";

		unsigned short out_rowNum = 65535;
		unsigned short out_maxLen = 65535;

		csl102_continuous_subarray(twoD_arr, inp_str, &out_rowNum, &out_maxLen);

		unsigned short out_rowNum_unity = 65535;
		unsigned short out_maxLen_unity = 65535;

		csl102_continuous_subarray_unity(twoD_arr, inp_str, &out_rowNum_unity, &out_maxLen_unity);

		printf("out_rowNum_unity = %d, out_maxLen_unity =%d\n", out_rowNum_unity, out_maxLen_unity);

		TEST_ASSERT_EQUAL_UINT16(out_rowNum_unity, out_rowNum);	
		TEST_ASSERT_EQUAL_UINT16(out_maxLen_unity, out_maxLen);	

}

void test2(void){
		char twoD_arr[CSL102_NUM_ROWS][CSL102_NUM_COLUMNS] =
		{
				"qwertyur",
				"yuifghjk",
				"aceyuthy",
				"qmdjyusp",
				"yuicvyui"
		};

		char inp_str[CSL102_INP_LEN] = "yui";

		unsigned short out_rowNum = 65535;
		unsigned short out_maxLen = 65535;

		csl102_continuous_subarray(twoD_arr, inp_str, &out_rowNum, &out_maxLen);

		unsigned short out_rowNum_unity = 65535;
		unsigned short out_maxLen_unity = 65535;

		csl102_continuous_subarray_unity(twoD_arr, inp_str, &out_rowNum_unity, &out_maxLen_unity);

		printf("out_rowNum_unity = %d, out_maxLen_unity =%d\n", out_rowNum_unity, out_maxLen_unity);

		TEST_ASSERT_EQUAL_UINT16(out_rowNum_unity, out_rowNum);	
		TEST_ASSERT_EQUAL_UINT16(out_maxLen_unity, out_maxLen);	
}

void test3(void){
		char twoD_arr[CSL102_NUM_ROWS][CSL102_NUM_COLUMNS] =
		{
				"qwertyui",
				"asdfghjk",
				"acefbthy",
				"qmdjtusp",
				"edxcvvcx"
		};

		char inp_str[CSL102_INP_LEN] = "vcx";

		unsigned short out_rowNum = 65535;
		unsigned short out_maxLen = 65535;

		csl102_continuous_subarray(twoD_arr, inp_str, &out_rowNum, &out_maxLen);

		unsigned short out_rowNum_unity = 65535;
		unsigned short out_maxLen_unity = 65535;

		csl102_continuous_subarray_unity(twoD_arr, inp_str, &out_rowNum_unity, &out_maxLen_unity);

		printf("out_rowNum_unity = %d, out_maxLen_unity =%d\n", out_rowNum_unity, out_maxLen_unity);

		TEST_ASSERT_EQUAL_UINT16(out_rowNum_unity, out_rowNum);	
		TEST_ASSERT_EQUAL_UINT16(out_maxLen_unity, out_maxLen);	

}

void test4(void){
		char twoD_arr[CSL102_NUM_ROWS][CSL102_NUM_COLUMNS] =
		{
				"qwertyui",
				"asdfghjk",
				"aceaceac",
				"qmdjtusp",
				"edxcvfrt"
		};

		char inp_str[CSL102_INP_LEN] = "ace";

		unsigned short out_rowNum = 65535;
		unsigned short out_maxLen = 65535;

		csl102_continuous_subarray(twoD_arr, inp_str, &out_rowNum, &out_maxLen);

		unsigned short out_rowNum_unity = 65535;
		unsigned short out_maxLen_unity = 65535;

		csl102_continuous_subarray_unity(twoD_arr, inp_str, &out_rowNum_unity, &out_maxLen_unity);

		printf("out_rowNum_unity = %d, out_maxLen_unity =%d\n", out_rowNum_unity, out_maxLen_unity);

		TEST_ASSERT_EQUAL_UINT16(out_rowNum_unity, out_rowNum);	
		TEST_ASSERT_EQUAL_UINT16(out_maxLen_unity, out_maxLen);	
}

void test5(void){
		char twoD_arr[CSL102_NUM_ROWS][CSL102_NUM_COLUMNS] =
		{
				"qwertyui",
				"asdfghjk",
				"acefbthy",
				"qmdjtusp",
				"edrtyrty"
		};

		char inp_str[CSL102_INP_LEN] = "rty";

		unsigned short out_rowNum = 65535;
		unsigned short out_maxLen = 65535;

		csl102_continuous_subarray(twoD_arr, inp_str, &out_rowNum, &out_maxLen);

		unsigned short out_rowNum_unity = 65535;
		unsigned short out_maxLen_unity = 65535;

		csl102_continuous_subarray_unity(twoD_arr, inp_str, &out_rowNum_unity, &out_maxLen_unity);

		printf("out_rowNum_unity = %d, out_maxLen_unity =%d\n", out_rowNum_unity, out_maxLen_unity);

		TEST_ASSERT_EQUAL_UINT16(out_rowNum_unity, out_rowNum);	
		TEST_ASSERT_EQUAL_UINT16(out_maxLen_unity, out_maxLen);	
}

void test6(void){
		char twoD_arr[CSL102_NUM_ROWS][CSL102_NUM_COLUMNS] =
		{
				"qwertyui",
				"asdfghjk",
				"abeabchy",
				"qmdjtusp",
				"edxcvfrt"
		};

		char inp_str[CSL102_INP_LEN] = "abc";

		unsigned short out_rowNum = 65535;
		unsigned short out_maxLen = 65535;

		csl102_continuous_subarray(twoD_arr, inp_str, &out_rowNum, &out_maxLen);

		unsigned short out_rowNum_unity = 65535;
		unsigned short out_maxLen_unity = 65535;

		csl102_continuous_subarray_unity(twoD_arr, inp_str, &out_rowNum_unity, &out_maxLen_unity);

		printf("out_rowNum_unity = %d, out_maxLen_unity =%d\n", out_rowNum_unity, out_maxLen_unity);

		TEST_ASSERT_EQUAL_UINT16(out_rowNum_unity, out_rowNum);	
		TEST_ASSERT_EQUAL_UINT16(out_maxLen_unity, out_maxLen);	
}

void test7(void){
		char twoD_arr[CSL102_NUM_ROWS][CSL102_NUM_COLUMNS] =
		{
				"qwertyui",
				"asdfghjk",
				"asdasdhy",
				"qmasdfsd",
				"edxavsrd"
		};

		char inp_str[CSL102_INP_LEN] = "asd";

		unsigned short out_rowNum = 65535;
		unsigned short out_maxLen = 65535;

		csl102_continuous_subarray(twoD_arr, inp_str, &out_rowNum, &out_maxLen);

		unsigned short out_rowNum_unity = 65535;
		unsigned short out_maxLen_unity = 65535;

		csl102_continuous_subarray_unity(twoD_arr, inp_str, &out_rowNum_unity, &out_maxLen_unity);

		printf("out_rowNum_unity = %d, out_maxLen_unity =%d\n", out_rowNum_unity, out_maxLen_unity);

		TEST_ASSERT_EQUAL_UINT16(out_rowNum_unity, out_rowNum);	
		TEST_ASSERT_EQUAL_UINT16(out_maxLen_unity, out_maxLen);	
}

void test8(void){
		char twoD_arr[CSL102_NUM_ROWS][CSL102_NUM_COLUMNS] =
		{
				"qwertyui",
				"asdfghjk",
				"acefbthy",
				"qmdjtusp",
				"edxcvfrt"
		};

		char inp_str[CSL102_INP_LEN] = "frt";

		unsigned short out_rowNum = 65535;
		unsigned short out_maxLen = 65535;

		csl102_continuous_subarray(twoD_arr, inp_str, &out_rowNum, &out_maxLen);

		unsigned short out_rowNum_unity = 65535;
		unsigned short out_maxLen_unity = 65535;

		csl102_continuous_subarray_unity(twoD_arr, inp_str, &out_rowNum_unity, &out_maxLen_unity);

		printf("out_rowNum_unity = %d, out_maxLen_unity =%d\n", out_rowNum_unity, out_maxLen_unity);

		TEST_ASSERT_EQUAL_UINT16(out_rowNum_unity, out_rowNum);	
		TEST_ASSERT_EQUAL_UINT16(out_maxLen_unity, out_maxLen);	
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

		UNITY_END();

		return 0;
}