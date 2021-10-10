#include <stdio.h>
#include "unity.h"
#include "csl102lab4.h"

unsigned long size_unity(stackRow_t row);
status_t isEmpty_unity(stackRow_t row);
status_t isFull_unity(stackRow_t row);

int elementsStack_unity_N920D71VNW[NUM_STACK_ROWS][MAX_SIZE_EACH_STACK];
short tosArr_unity_N920D71VNW[NUM_STACK_ROWS];


void reset_unity(){
    for(short i=0; i<NUM_STACK_ROWS; i++)
        tosArr_unity_N920D71VNW[i] = -1;
    return;
}

void init_unity(){
   reset_unity();
}

status_t push_unity(int val, stackRow_t row){

    if(row >= NUM_STACK_ROWS)
		return STACK_FALSE;

    if(STACK_FALSE == isFull_unity(row)){
        tosArr_unity_N920D71VNW[row] = tosArr_unity_N920D71VNW[row] + 1;
        elementsStack_unity_N920D71VNW[row][tosArr_unity_N920D71VNW[row]] = val;
        return STACK_TRUE;
    }
    return STACK_FALSE;
}

status_t pop_unity(int* ptrVal, stackRow_t row){

    if(row >= NUM_STACK_ROWS)
		return STACK_FALSE;

    if(STACK_FALSE == isEmpty_unity(row)){
        *ptrVal = elementsStack_unity_N920D71VNW[row][tosArr_unity_N920D71VNW[row]];
        tosArr_unity_N920D71VNW[row] = tosArr_unity_N920D71VNW[row] - 1;
        return STACK_TRUE;
    }
    return STACK_FALSE;
}

status_t peek_unity(int* ptrVal, stackRow_t row){

    if(row >= NUM_STACK_ROWS)
		return STACK_FALSE;

     if(STACK_FALSE == isEmpty_unity(row)){
        *ptrVal = elementsStack_unity_N920D71VNW[row][tosArr_unity_N920D71VNW[row]];
        //topOfStack--;
        return STACK_TRUE;
    }
    return STACK_FALSE;
}

unsigned long size_unity(stackRow_t row){
    return tosArr_unity_N920D71VNW[row] + 1;
}

status_t isEmpty_unity(stackRow_t row){
    if(-1 == tosArr_unity_N920D71VNW[row])
        return STACK_TRUE;

    return STACK_FALSE;
}

status_t isFull_unity(stackRow_t row){
    if(MAX_SIZE_EACH_STACK == tosArr_unity_N920D71VNW[row] + 1)
        return STACK_TRUE;

    return STACK_FALSE;
}

void test1(void){

	status_t s1;
	status_t s2;

	for(int k=0; k<10; k++){
		for(int i=0; i<15; i++){
			s1 = push(i,k);
			s2 = push_unity(i,k);
			//printf("%d\t\t%d\n",s1, s2);
			TEST_ASSERT_EQUAL_UINT16((unsigned short) s2, (unsigned short) s1);
		}
	}
}

void test2(void){

	int val = 0;
	int val_unity = 0;

	status_t s1;
	status_t s2;

	for(int k=0; k<5; k++){
		s1 = peek(&val, k);
		s2 = peek_unity(&val_unity, k);
		TEST_ASSERT_EQUAL_UINT16((unsigned short) s2, (unsigned short) s1);
		TEST_ASSERT_EQUAL_UINT16((unsigned short) val_unity, (unsigned short) val);
	}
	
}

void test3(void){

	status_t s1;
	status_t s2;

	int val = 0;
	int val_unity = 0;

	for(int k=0; k<5; k++){

		s1 = pop(&val, k);
		s2 = pop_unity(&val_unity, k);
		TEST_ASSERT_EQUAL_UINT16((unsigned short) s2, (unsigned short) s1);
		TEST_ASSERT_EQUAL_UINT16((unsigned short) val_unity, (unsigned short) val);

		s1 = pop(&val, k);
		s2 = pop_unity(&val_unity, k);
		TEST_ASSERT_EQUAL_UINT16((unsigned short) s2, (unsigned short) s1);
		TEST_ASSERT_EQUAL_UINT16((unsigned short) val_unity, (unsigned short) val);

		s1 = pop(&val, k);
		s2 = pop_unity(&val_unity, k);
		TEST_ASSERT_EQUAL_UINT16((unsigned short) s2, (unsigned short) s1);
		TEST_ASSERT_EQUAL_UINT16((unsigned short) val_unity, (unsigned short) val);
		
	}

}

void test4(void){

	status_t s1;
	status_t s2;

	for(int k=0; k<10; k++){
		for(int i=15; i<0; i--){
			s1 = push(i,k);
			s2 = push_unity(i,k);
			//printf("%d\t\t%d\n",s1, s2);
			TEST_ASSERT_EQUAL_UINT16((unsigned short) s2, (unsigned short) s1);
		}
	}

	int val = 0;
	int val_unity = 0;

	for(int k=0; k<5; k++){

		s1 = pop(&val, k);
		s2 = pop_unity(&val_unity, k);
		TEST_ASSERT_EQUAL_UINT16((unsigned short) s2, (unsigned short) s1);
		TEST_ASSERT_EQUAL_UINT16((unsigned short) val_unity, (unsigned short) val);
		
	}
	
}

void setUp (void) {} 
void tearDown (void) {} 

int main(void){

		UNITY_BEGIN();

		init();
		init_unity();

		RUN_TEST(test1);
		RUN_TEST(test2);
		RUN_TEST(test3);
		RUN_TEST(test4);

		UNITY_END();

		return 0;
}