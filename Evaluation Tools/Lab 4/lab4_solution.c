#include <stdio.h>
#include "csl102lab4.h"

unsigned long size(stackRow_t row);
status_t isEmpty(stackRow_t row);
status_t isFull(stackRow_t row);

int elementsStack_N920D71VNW[NUM_STACK_ROWS][MAX_SIZE_EACH_STACK];
short tosArr_N920D71VNW[NUM_STACK_ROWS];


void reset()
{
    for(short i=0; i<NUM_STACK_ROWS; i++)
        tosArr_N920D71VNW[i] = -1;
    return;
}

void init()
{
   reset();
}

status_t push(int val, stackRow_t row)
{

    if(row >= NUM_STACK_ROWS)
		return STACK_FALSE;

    if(STACK_FALSE == isFull(row))
    {
        tosArr_N920D71VNW[row] = tosArr_N920D71VNW[row] + 1;
        elementsStack_N920D71VNW[row][tosArr_N920D71VNW[row]] = val;
        return STACK_TRUE;
    }
    return STACK_FALSE;
}

status_t pop(int* ptrVal, stackRow_t row)
{

    if(row >= NUM_STACK_ROWS)
		return STACK_FALSE;

    if(STACK_FALSE == isEmpty(row))
    {
        *ptrVal = elementsStack_N920D71VNW[row][tosArr_N920D71VNW[row]];
        tosArr_N920D71VNW[row] = tosArr_N920D71VNW[row] - 1;
        return STACK_TRUE;
    }
    return STACK_FALSE;
}

status_t peek(int* ptrVal, stackRow_t row)
{

    if(row >= NUM_STACK_ROWS)
		return STACK_FALSE;

     if(STACK_FALSE == isEmpty(row))
     {
        *ptrVal = elementsStack_N920D71VNW[row][tosArr_N920D71VNW[row]];
        //topOfStack--;
        return STACK_TRUE;
    }
    return STACK_FALSE;
}

unsigned long size(stackRow_t row)
{
    return tosArr_N920D71VNW[row] + 1;
}

status_t isEmpty(stackRow_t row)
{
    if(-1 == tosArr_N920D71VNW[row])
        return STACK_TRUE;

    return STACK_FALSE;
}

status_t isFull(stackRow_t row)
{
    if(MAX_SIZE_EACH_STACK == tosArr_N920D71VNW[row] + 1)
        return STACK_TRUE;

    return STACK_FALSE;
}