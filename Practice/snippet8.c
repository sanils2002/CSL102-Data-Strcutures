#include<stdio.h>
#define DEPTH 3
#define ROWS 3
#define COLUMNS 4

int main()
{
    system("CLS");
    printf("\n");

    /*series of 3 two dimensional arrays*/
    int threeD_arr3[DEPTH][ROWS][COLUMNS] = 
    {
        {{0,1,2,3}, {4,5,6,7}, {8,9,10,11}},
        {{0,-1,-2,-3}, {-4,-5,-6,-7}, {-8,-9,-10,-11}},
        {{2,4,6,8}, {-2,-4,-6,-8}, {12,13,14,15}}
        };

    for (short i = 0; i < DEPTH; i++)
    {
        for (short j = 0; j < ROWS; j++)
        {
            for (short k = 0; k < COLUMNS; k++)
            {
                printf("threeD_arr3[%d][%d][%d] = %d\n", i,j,k, threeD_arr3[i][j][k]);
            }
        }
    }

    return 0;

}