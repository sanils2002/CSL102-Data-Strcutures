#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "csl102_lab5.h"

int queue_fvdgq[MAX_SIZE_QUEUE];
short frontIdx_fvdgq = -1;
short backIdx_fvdgq = -1;

status_t isEmpty_unity(){
    status_t s;
    s = (-1 == frontIdx_fvdgq) ? QUEUE_TRUE : QUEUE_FALSE;
    return s;
}

status_t isFull_unity(){
    status_t s;
    s = ((backIdx_fvdgq + 1 == frontIdx_fvdgq) || (0 == frontIdx_fvdgq && MAX_SIZE_QUEUE - 1 == backIdx_fvdgq)) ? QUEUE_TRUE : QUEUE_FALSE;
    return s;
}

void create_unity(){
	for(short i=0; i<MAX_SIZE_QUEUE; i++)
        queue_fvdgq[i] = -1;
    return;
}

status_t enqueueAtIndex_unity(int value, int index){
	if((index > MAX_SIZE_QUEUE - 1) || 
		(QUEUE_TRUE == isFull_unity()) ||
		(index > backIdx_fvdgq + 1) || // this case will not be tested
		(index < frontIdx_fvdgq)) // this case will not be tested
		return QUEUE_FALSE;

		if(-1 == frontIdx_fvdgq) 
			frontIdx_fvdgq = 0;

		for(short i = backIdx_fvdgq; i >= index; i--){
			queue_fvdgq[i+1] = queue_fvdgq[i];
		}
	
		queue_fvdgq[index] = value;
		backIdx_fvdgq++;

	return QUEUE_TRUE;
}

status_t dequeueFromIndex_unity(int index, int *out_value){
	if((index > MAX_SIZE_QUEUE - 1) || 
		(QUEUE_TRUE == isEmpty_unity()) ||
		(index < frontIdx_fvdgq) || // this case will not be tested
		(index > backIdx_fvdgq)) // this case will not be tested
		return QUEUE_FALSE;

		*out_value = queue_fvdgq[index];
		for(short i = index; i <= backIdx_fvdgq; i++){
			queue_fvdgq[i] = queue_fvdgq[i+1];
		}
	
		if(index == frontIdx_fvdgq)
			frontIdx_fvdgq++;
		else
			--backIdx_fvdgq;

	return QUEUE_TRUE;
}

status_t front_unity(int *out_value){
	if(QUEUE_FALSE == isEmpty_unity()){
        *out_value = queue_fvdgq[frontIdx_fvdgq];
        return QUEUE_TRUE;
    }
    return QUEUE_FALSE;
}

status_t back_unity(int *out_value){
	if(QUEUE_FALSE == isEmpty_unity()){
        *out_value = queue_fvdgq[backIdx_fvdgq];
        return QUEUE_TRUE;
    }
    return QUEUE_FALSE;
}

int* getQueue_unity(){
	return queue_fvdgq;
}

void test1(){
	TEST_ASSERT_EQUAL_UINT16(enqueueAtIndex_unity(23, 0), enqueueAtIndex(23, 0));
	TEST_ASSERT_EQUAL_UINT16(enqueueAtIndex_unity(3, 1), enqueueAtIndex(3, 1));
	TEST_ASSERT_EQUAL_UINT16(enqueueAtIndex_unity(56, 2), enqueueAtIndex(56, 2));
	TEST_ASSERT_EQUAL_UINT16(enqueueAtIndex_unity(12, 1), enqueueAtIndex(12, 1));
	TEST_ASSERT_EQUAL_UINT16(enqueueAtIndex_unity(9, 0), enqueueAtIndex(9, 0));
	TEST_ASSERT_EQUAL_UINT16(enqueueAtIndex_unity(92, 3), enqueueAtIndex(92, 3));
	TEST_ASSERT_EQUAL_UINT16(enqueueAtIndex_unity(36, 4), enqueueAtIndex(36, 4));

	//int *arr = getQueue_unity();
	//for(short i=0; i<MAX_SIZE_QUEUE; i++){
	//		printf("%d\t", arr[i]);
	//}
	//printf("\n");
}

void test2(){

	int out_value_unity = 0;
	int out_value = 0;

	TEST_ASSERT_EQUAL_UINT16(front_unity(&out_value_unity), front(&out_value));
	//printf("%d\t%d\n", out_value_unity, out_value);
	TEST_ASSERT_EQUAL_INT32(out_value_unity, out_value);

	TEST_ASSERT_EQUAL_UINT16(back_unity(&out_value_unity), back(&out_value));
	//printf("%d\t%d\n", out_value_unity, out_value);
	TEST_ASSERT_EQUAL_INT32(out_value_unity, out_value);

	TEST_ASSERT_EQUAL_UINT16(enqueueAtIndex_unity(312, 7), enqueueAtIndex(312, 7));

	TEST_ASSERT_EQUAL_UINT16(back_unity(&out_value_unity), back(&out_value));
	//printf("%d\t%d\n", out_value_unity, out_value);
	TEST_ASSERT_EQUAL_INT32(out_value_unity, out_value);

	/*
	{
	int *arr = getQueue_unity();
	for(short i=0; i<MAX_SIZE_QUEUE; i++){
			printf("%d\t", arr[i]);
	}
	printf("\n");
	}
	*/
} 

void test3(){

	//printf("test3: %d\t%d\n", frontIdx_fvdgq, backIdx_fvdgq);

	TEST_ASSERT_EQUAL_UINT16(enqueueAtIndex_unity(652, 8), enqueueAtIndex(652, 8));
	TEST_ASSERT_EQUAL_UINT16(enqueueAtIndex_unity(799, 8), enqueueAtIndex(799, 8));
	TEST_ASSERT_EQUAL_UINT16(enqueueAtIndex_unity(971, 4), enqueueAtIndex(971, 4));
	TEST_ASSERT_EQUAL_UINT16(enqueueAtIndex_unity(971, 0), enqueueAtIndex(971, 0));

	TEST_ASSERT_EQUAL_INT32_ARRAY(getQueue_unity(), getQueue(), MAX_SIZE_QUEUE);

	//printf("test3: %d\t%d\n", frontIdx_fvdgq, backIdx_fvdgq);
}

void test4(){
	int out_value_unity = 0;
	int out_value = 0;

	/*printf("%d\t%d\n", frontIdx_fvdgq, backIdx_fvdgq);

	{
	int *arr = getQueue_unity();
	for(short i=0; i<MAX_SIZE_QUEUE; i++){
			printf("%d\t", arr[i]);
	}
	printf("\n");
	}*/

	TEST_ASSERT_EQUAL_UINT16(dequeueFromIndex_unity(8, &out_value_unity), dequeueFromIndex(8, &out_value));
	TEST_ASSERT_EQUAL_INT32(out_value_unity, out_value);

	/*printf("%d\t%d\n", frontIdx_fvdgq, backIdx_fvdgq);
	{
	int *arr = getQueue_unity();
	for(short i=0; i<MAX_SIZE_QUEUE; i++){
			printf("%d\t", arr[i]);
	}
	printf("\n");
	}*/

	TEST_ASSERT_EQUAL_UINT16(dequeueFromIndex_unity(3, &out_value_unity), dequeueFromIndex(3, &out_value));
	TEST_ASSERT_EQUAL_INT32(out_value_unity, out_value);

	/*printf("%d\t%d\n", frontIdx_fvdgq, backIdx_fvdgq);
	{
	int *arr = getQueue_unity();
	for(short i=0; i<MAX_SIZE_QUEUE; i++){
			printf("%d\t", arr[i]);
	}
	printf("\n");
	}*/

	/*TEST_ASSERT_EQUAL_UINT16(dequeueFromIndex_unity(0, &out_value_unity), dequeueFromIndex(0, &out_value));
	TEST_ASSERT_EQUAL_INT32(out_value_unity, out_value);

	printf("%d\t%d\n", frontIdx_fvdgq, backIdx_fvdgq);
	{
	int *arr = getQueue_unity();
	for(short i=0; i<MAX_SIZE_QUEUE; i++){
			printf("%d\t", arr[i]);
	}
	printf("\n");
	}*/

	TEST_ASSERT_EQUAL_UINT16(front_unity(&out_value_unity), front(&out_value));
	//printf("%d\t%d\n", out_value_unity, out_value);
	TEST_ASSERT_EQUAL_INT32(out_value_unity, out_value);

	TEST_ASSERT_EQUAL_UINT16(back_unity(&out_value_unity), back(&out_value));
	//printf("%d\t%d\n", out_value_unity, out_value);
	TEST_ASSERT_EQUAL_INT32(out_value_unity, out_value);

	//printf("%d\t%d\n", frontIdx_fvdgq, backIdx_fvdgq);
	
	TEST_ASSERT_EQUAL_UINT16(enqueueAtIndex_unity(971, 4), enqueueAtIndex(971, 4));
	TEST_ASSERT_EQUAL_UINT16(enqueueAtIndex_unity(111, 2), enqueueAtIndex(111, 2));

	/*
	{
	int *arr = getQueue_unity();
	for(short i=0; i<MAX_SIZE_QUEUE; i++){
			printf("%d\t", arr[i]);
	}
	printf("\n");
	}
	*/

	TEST_ASSERT_EQUAL_INT32_ARRAY(getQueue_unity(), getQueue(), MAX_SIZE_QUEUE);
}

void setUp (void) {} 
void tearDown (void) {} 

int main(void){

		UNITY_BEGIN();
		create();
		create_unity();

		RUN_TEST(test1);
		RUN_TEST(test2);
		RUN_TEST(test3);
		RUN_TEST(test4);

		UNITY_END();

		return 0;
}
