#include <stdio.h>

int main()
{
    system("CLS");
    
    int a = 5, b = 0;
    printf("\nValue of a = %d.\nAddress of a = %p.\n", a, &a);

    int* ptr = NULL; /* initialize a ptr to NULL */
    ptr = &a; /* variable ptr now contains address of a */
    printf("Value of ptr = %p.\nValue at address pointed by p = %d.\n", ptr, *ptr);

    b = *ptr; /* the value of b is now overwritten with value of a*/
              /* this is equivalent to writing b = a; */
    printf("Value of b = %d.\n", b);

    return 0;
}
