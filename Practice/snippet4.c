#include<stdio.h>

void swap(int *ptr_x, int *ptr_y)
{
    int temp = *ptr_x;
    *ptr_x = *ptr_y;
    *ptr_y = temp;
}
  
int main()
{
    system("CLS");

    int x = 10; int y = 20;
    /*The addresses of variable x and y are passed as arguments to the swap function*/
    swap(&x, &y);
    printf("Swapped values are: x = %d, y = %d\n", x, y);
    return 0;
}