#include<stdio.h>
#define ROWS 3
#define COLUMNS 4
  
  int main()
  {
      
      system("CLS");

      /*
      The general pattern for declaration of 2d array:
      data_type var_name[num_rows][num_columns] where 
          - data_type is a valid data type in C language
          - var_name is the name of the variable
      */
      int twoD_arr[ROWS][COLUMNS]; /* declaration without initialization*/
  
      /*Initialization*/
      /*First row: values 0 through 3*/
      /*Second row: values 4 through 7*/
      /*Third row: values 8 through 11*/
      int twoD_arr2[ROWS][COLUMNS] = {0,1,2,3,4,5,6,7,8,9,10,11}; 
  
      /*Clearer way to initialize*/
      int twoD_arr3[ROWS][COLUMNS] = {{0,1,2,3}, {4,5,6,7}, {8,9,10,11}};
  
      /*Accessing the elements in two dimensional array*/
      for (short i = 0; i < ROWS; i++)
      {
          for (short j = 0; j < COLUMNS; j++)
          {
              printf("twoD_arr3[%d][%d] = %d\n", i, j, twoD_arr3[i][j]);
          }
      }
  
      return 0;

  }