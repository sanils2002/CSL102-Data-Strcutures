#include <stdio.h>

int main()
{
    system("CLS");

    int a = 111;
    printf("Value of a = %d.\nAddress of a = %p.\n", a, &a);

    int* ptr = NULL; /* initialize a ptr to NULL */
    ptr = &a; /* variable ptr now contains address of a */
    printf("\nValue of ptr = %p.\nValue at address pointed by p = %d.\n", ptr, *ptr);

    /* Working with Pointer to Pointers*/
    int **dblPtr = NULL; /* double pointer */
    dblPtr = &ptr; /* dblPtr points to the address where ptr is located.
    '*dblPtr' will point to the address pointed by ptr, i.e. address of a */
    if(ptr == *dblPtr)
    {
        printf("ptr == *dblPtr is true.\n");
        printf("Address of 'dblPtr' = %p. \n", &dblPtr);
        printf("Address of 'ptr' and value in dblPtr = %p. \n", dblPtr);
        printf("Address of 'a' = %p. \n", *dblPtr);
        printf("Value at address pointed by 'ptr' = %d. \n", **dblPtr);
    }
    return 0;
}