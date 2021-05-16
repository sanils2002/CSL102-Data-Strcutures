#include <stdio.h>

int main()
{
    system("CLS");
    
    int intArr[5] = {34, 25, 7, -8, 45};
    double doubleArr[5] = {2.6, -9.7, 4, 56, 34.2}; 

    /*get the starting address of array using pointers*/
    int *ptrArrInt = intArr; 
    double *ptrArrDouble = doubleArr;

    /*print values in an array using pointer arithmetic*/
    for(unsigned short idx = 0; idx < 5; idx++)
    {
        printf("intArr[%d] = %d\n", idx, *(ptrArrInt + idx));
        printf("doubleArr[%d] = %f\n", idx, *(ptrArrDouble + idx));
    }

     /*Rewrite values in an array
     Access next element in an array using increment operator on pointers*/
    for(unsigned short idx = 0; idx < 5; idx++)
    {
        *intArr = *intArr * -1;
        *doubleArr = *doubleArr * -1;
        ++ptrArrInt; /*point to the next address in the array*/
        ++ptrArrDouble;
    }
    
    /*reinitialize the pointers to address of second element in the array*/
    ptrArrInt = intArr + 1; 
    ptrArrDouble = doubleArr + 1;
    /*to point to third element in the array, simply do
    ptrArrInt = intArr + 2; 
    ptrArrDouble = doubleArr + 2;
    */

    printf("\n\n");

    /*print values in an array using for loop*/
    for(unsigned short idx = 0; idx < 4; idx++)
    {
        printf("intArr[%d] = %d\n", idx, *ptrArrInt);
        printf("doubleArr[%d] = %f\n", idx, *ptrArrDouble);
        ++ptrArrInt;
        ++ptrArrDouble;
    }
}