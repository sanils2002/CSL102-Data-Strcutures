#include "csl102lab0.h" //header file for generating prototype of swap function//
#include <stdio.h>


int main()
{
    system("CLS"); //Clearing the output screen for better visibility//

    int x, y, z; //Declaring local variables//

    //inputting the 3 numbers//
    printf("\nEnter all the 3 numbers for swapping:");
    scanf("%d %d %d", &x, &y, &z);

    //Printing values before swapping//
    printf("\nBefore Swapping:\n");
    printf("Values are:\n");
    printf("x = %d \ny = %d \nz = %d \n", x, y, z);

    //Recalling the swap function//
    swap(&x, &y, &z);

    //Printing values after swapping//
    printf("\nAfter Swapping:\n");
    printf("Values are:\n");
    printf("x = %d \ny = %d \nz = %d \n", x, y, z);

    return 0; //Returning 0 as func is int//

}


void swap(int *a, int *b, int *c)
{
    int t;
    t = *a;
    *a = *c;
    *c = *b;
    *b = t;
}
