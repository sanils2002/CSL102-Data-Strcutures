#include <stdio.h>
#include "csl102th1.h"

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int start, int n, int dsc){
    for (int i = start; i < n-1; i++){	
	    for (int j = start; j < start+n-i-1; j++){
            /*printf("%d\t%d\n", i, j);*/
            
            if(1 == dsc){
                 if (arr[j] < arr[j+1]){
			        swap(&arr[j], &arr[j+1]);
                }
            }
            else{
		        if (arr[j] > arr[j+1]){
			        swap(&arr[j], &arr[j+1]);
                }
            }
        }
    }
    /*printf("\n");*/
}

void print_array_func(int arr[], int size){
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void csl102_left_right_sort(int arr[], unsigned short n){
    bubbleSort(arr, 0, n/2, 0);
    bubbleSort(arr, n/2, n, 1);
}

void csl102_update_string(char arr[], unsigned short szArr, char strings[][NUM_COLUMNS], unsigned short rows, char replacementChar){
    for(int r = 0; r < rows; r++){
        int c = 0;
        for (int i=0; i<szArr; i++){
            if(arr[i] ==  strings[r][c]){
                c++;
                if(NUM_COLUMNS == c){
                    while(c > 0){
                        --c;
                        arr[i - c] =  replacementChar;
                    }
                }
            }
            else{
                c = 0;
            }
        }
    }
}




/*
int main(){

    int arr[8] = {21, 0, 6, -3, 56, -2, 8, 99};
    print_array_func(arr, 8);
    csl102_left_right_sort(arr, 8);
    print_array_func(arr, 8);

    
    char arr1[] = "the hero of this movie looked like a monk who sold his ferrari";
    char string[4][NUM_COLUMNS] = {
                        "hero",
                        "monk",
                        "sole",
                        "like"
                        };

    csl102_update_string(arr1, sizeof(arr1)/sizeof(arr1[0]), string, 4, 'x');

    printf("%s\n", arr1);


    return 0;
}
*/