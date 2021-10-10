#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "csl102lab1.h"
#define MAX_ROWS 5 
#define MAX_COLUMNS 5

int *arrayTest1 = NULL;
int *arrayUnity1 = NULL;
unsigned short seed1 = 3;

int *arrayTest2 = NULL;
int *arrayUnity2 = NULL;
unsigned short seed2 = 2;

void csl102_lab1_populate_unity(int* array, int R, int C, unsigned short seed){
  for (int r=0; r<R; r++){
    for (int c=0; c<C; c++){
      array[r*C+c]=seed*r*c;
    }
  }
}

int csl102_lab1_get_unity(int *array, int r, int c, int C){
    return array[r*C+c];
}

void csl102_lab1_replace_zeros_unity(int* array, int R, int C){
    for (int r=0; r<R; r++){
        for (int c=0; c<C; c++){
            if(0 == array[r*C+c])
                array[r*C+c] = 1;
        }
    }
}

unsigned long csl102_lab1_product_unity(int* array, int R, int C){
    unsigned long product = 1;
    for (int r=0; r<R; r++){
        for (int c=0; c<C; c++){
            product = product * array[r*C+c];
        }
    }
    return product;
}

void create2DArrayAs1D_unity(int **array, int R, int C){
    *array = (int*)malloc(R * C * sizeof(int));
}

void test1(void){
    for (int r=0; r<MAX_ROWS; r++){
        for (int c=0; c<MAX_COLUMNS; c++){
            TEST_ASSERT_EQUAL_INT(arrayUnity1[r*MAX_COLUMNS+c], arrayTest1[r*MAX_COLUMNS+c]);
            TEST_ASSERT_EQUAL_INT(arrayUnity2[r*MAX_COLUMNS+c], arrayTest2[r*MAX_COLUMNS+c]);
        }
    }
}

void test2(void){
	TEST_ASSERT_EQUAL_INT(csl102_lab1_get(arrayTest1, 1, 4, MAX_COLUMNS), csl102_lab1_get_unity(arrayTest1, 1, 4, MAX_COLUMNS));
    TEST_ASSERT_EQUAL_INT(csl102_lab1_get(arrayTest1, 2, 2, MAX_COLUMNS), csl102_lab1_get_unity(arrayTest1, 2, 2, MAX_COLUMNS));
    TEST_ASSERT_EQUAL_INT(csl102_lab1_get(arrayTest1, 3, 0, MAX_COLUMNS), csl102_lab1_get_unity(arrayTest1, 3, 0, MAX_COLUMNS));
    TEST_ASSERT_EQUAL_INT(csl102_lab1_get(arrayTest1, 1, 1, MAX_COLUMNS), csl102_lab1_get_unity(arrayTest1, 1, 1, MAX_COLUMNS));
    TEST_ASSERT_EQUAL_INT(csl102_lab1_get(arrayTest1, 4, 3, MAX_COLUMNS), csl102_lab1_get_unity(arrayTest1, 4, 3, MAX_COLUMNS));

    TEST_ASSERT_EQUAL_INT(csl102_lab1_get(arrayTest2, 1, 4, MAX_COLUMNS), csl102_lab1_get_unity(arrayTest2, 1, 4, MAX_COLUMNS));
    TEST_ASSERT_EQUAL_INT(csl102_lab1_get(arrayTest2, 2, 2, MAX_COLUMNS), csl102_lab1_get_unity(arrayTest2, 2, 2, MAX_COLUMNS));
    TEST_ASSERT_EQUAL_INT(csl102_lab1_get(arrayTest2, 3, 0, MAX_COLUMNS), csl102_lab1_get_unity(arrayTest2, 3, 0, MAX_COLUMNS));
    TEST_ASSERT_EQUAL_INT(csl102_lab1_get(arrayTest2, 1, 1, MAX_COLUMNS), csl102_lab1_get_unity(arrayTest2, 1, 1, MAX_COLUMNS));
    TEST_ASSERT_EQUAL_INT(csl102_lab1_get(arrayTest2, 4, 3, MAX_COLUMNS), csl102_lab1_get_unity(arrayTest2, 4, 3, MAX_COLUMNS));
}

void test3(void){
    for (int r=0; r<MAX_ROWS; r++){
        for (int c=0; c<MAX_COLUMNS; c++){
            TEST_ASSERT_EQUAL_INT(arrayUnity1[r*MAX_COLUMNS+c], arrayTest1[r*MAX_COLUMNS+c]);
            TEST_ASSERT_EQUAL_INT(arrayUnity2[r*MAX_COLUMNS+c], arrayTest2[r*MAX_COLUMNS+c]);
        }
    }
}

void test4(void){

	TEST_ASSERT_EQUAL_UINT64(csl102_lab1_product_unity(arrayUnity1, MAX_ROWS, MAX_COLUMNS), csl102_lab1_product(arrayTest1, MAX_ROWS, MAX_COLUMNS));

    TEST_ASSERT_EQUAL_UINT64(csl102_lab1_product_unity(arrayUnity2, MAX_ROWS, MAX_COLUMNS), csl102_lab1_product(arrayTest2, MAX_ROWS, MAX_COLUMNS));

    /*printf("%lu\t%lu", csl102_lab1_product_unity(arrayUnity1, MAX_ROWS, MAX_COLUMNS), csl102_lab1_product_unity(arrayUnity2, MAX_ROWS, MAX_COLUMNS));*/
}

void setUp (void) {} 
void tearDown (void) {} 

int main(void){

	UNITY_BEGIN();
    create2DArrayAs1D_unity(&arrayTest1, MAX_ROWS, MAX_COLUMNS);
    create2DArrayAs1D_unity(&arrayUnity1, MAX_ROWS, MAX_COLUMNS);
    create2DArrayAs1D_unity(&arrayTest2, MAX_ROWS, MAX_COLUMNS);
    create2DArrayAs1D_unity(&arrayUnity2, MAX_ROWS, MAX_COLUMNS);

    csl102_lab1_populate(arrayTest1, MAX_ROWS, MAX_COLUMNS, seed1);
    csl102_lab1_populate(arrayTest2, MAX_ROWS, MAX_COLUMNS, seed2);   

    csl102_lab1_populate_unity(arrayUnity1, MAX_ROWS, MAX_COLUMNS, seed1);
    csl102_lab1_populate_unity(arrayUnity2, MAX_ROWS, MAX_COLUMNS, seed2);

	RUN_TEST(test1);
	RUN_TEST(test2);

    csl102_lab1_replace_zeros(arrayTest1, MAX_ROWS, MAX_COLUMNS);
    csl102_lab1_replace_zeros(arrayTest2, MAX_ROWS, MAX_COLUMNS);

    csl102_lab1_replace_zeros_unity(arrayUnity1, MAX_ROWS, MAX_COLUMNS);
    csl102_lab1_replace_zeros_unity(arrayUnity2, MAX_ROWS, MAX_COLUMNS);
 
    RUN_TEST(test3);
    RUN_TEST(test4);
    
	UNITY_END();

    free(arrayUnity1);
    free(arrayTest1);
    free(arrayUnity2);
    free(arrayTest2);

	return 0;
}
