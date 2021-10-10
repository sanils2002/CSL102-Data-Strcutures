#include <stdio.h>
#include "csl102th1_mu.h"

short isMatch(char* arr1, short startIdx, char arr2[CSL102_INP_LEN])
{
		for(short i=0; i<CSL102_INP_LEN; i++){

				if(arr1[startIdx + i] != arr2[i])
						return 0;
		}

		return 1;
}

void csl102_continuous_subarray(
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
