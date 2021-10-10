#include <stdio.h>
#include <stdlib.h>
#include "csl102lab1.h"
#define MAX_ROWS 5 
#define MAX_COLUMNS 5

void csl102_lab1_populate(int* array, int R, int C, unsigned short seed)
{
  for (int r=0; r<R; r++){
    for (int c=0; c<C; c++){
      array[r*C+c]=seed*r*c;
    }
  }
}

int csl102_lab1_get(int *array, int r, int c, int C){
    return array[r*C+c];
}

void csl102_lab1_replace_zeros(int* array, int R, int C){
    for (int r=0; r<R; r++){
        for (int c=0; c<C; c++){
            if(0 == array[r*C+c])
                array[r*C+c] = 1;
        }
    }
}

unsigned long csl102_lab1_product(int* array, int R, int C){
    unsigned long product = 1;
    for (int r=0; r<R; r++){
        for (int c=0; c<C; c++){
            product = product * array[r*C+c];
        }
    }
    return product;
}

void create2DArrayAs1D(int **array, int R, int C){
    *array = (int*)malloc(R * C * sizeof(int));
}


int main()
{
  system("CLS");

  int *array = NULL;
  int seed = 4;

  create2DArrayAs1D(&array, MAX_ROWS, MAX_COLUMNS);
  csl102_lab1_populate(array, MAX_ROWS, MAX_COLUMNS, seed);
  printf("%d\n", csl102_lab1_get(array, 2, 3, MAX_COLUMNS));
  printf("%d\n", csl102_lab1_get(array, 3, 4, MAX_COLUMNS));
  printf("%d\n", csl102_lab1_get(array, 4, 2, MAX_COLUMNS));
  csl102_lab1_replace_zeros(array, MAX_ROWS, MAX_COLUMNS);
  printf("%lu\n", csl102_lab1_product(array, MAX_ROWS, MAX_COLUMNS));
  free(array);
}
