#include "csl102_lab5.h"

int queue_qazwx[MAX_SIZE_QUEUE];
short frontIdx_qazwx = -1;
short backIdx_qazwx = -1;

status_t isEmpty(){
    status_t s;
    s = (-1 == frontIdx_qazwx) ? QUEUE_TRUE : QUEUE_FALSE;
    return s;
}

status_t isFull(){
    status_t s;
    s = ((backIdx_qazwx + 1 == frontIdx_qazwx) || (0 == frontIdx_qazwx && MAX_SIZE_QUEUE - 1 == backIdx_qazwx)) ? QUEUE_TRUE : QUEUE_FALSE;
    return s;
}

void create(){
	for(short i=0; i<MAX_SIZE_QUEUE; i++)
        queue_qazwx[i] = -1;
    return;
}

status_t enqueueAtIndex(int value, int index){
	if((index > MAX_SIZE_QUEUE - 1) || 
		(QUEUE_TRUE == isFull()) ||
		(index > backIdx_qazwx + 1) || // this case will not be tested
		(index < frontIdx_qazwx)) // this case will not be tested
		return QUEUE_FALSE;

		if(-1 == frontIdx_qazwx) 
			frontIdx_qazwx = 0;

		for(short i = backIdx_qazwx; i >= index; i--){
			queue_qazwx[i+1] = queue_qazwx[i];
		}
	
		queue_qazwx[index] = value;
		backIdx_qazwx++;

	return QUEUE_TRUE;
}

status_t dequeueFromIndex(int index, int *out_value){
	if((index > MAX_SIZE_QUEUE - 1) || 
		(QUEUE_TRUE == isEmpty()) ||
		(index < frontIdx_qazwx) || // this case will not be tested
		(index > backIdx_qazwx)) // this case will not be tested
		return QUEUE_FALSE;

		*out_value = queue_qazwx[index];
		for(short i = index; i <= backIdx_qazwx; i++){
			queue_qazwx[i] = queue_qazwx[i+1];
		}
	
			if(index == frontIdx_qazwx)
			frontIdx_qazwx++;
		else
			--backIdx_qazwx;

	return QUEUE_TRUE;
}

status_t front(int *out_value){
	if(QUEUE_FALSE == isEmpty()){
        *out_value = queue_qazwx[frontIdx_qazwx];
        return QUEUE_TRUE;
    }
    return QUEUE_FALSE;
}

status_t back(int *out_value){
	if(QUEUE_FALSE == isEmpty()){
        *out_value = queue_qazwx[backIdx_qazwx];
        return QUEUE_TRUE;
    }
    return QUEUE_FALSE;
}

int* getQueue(){
	return queue_qazwx;
}
