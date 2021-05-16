#include <stdio.h>
#include <stdlib.h>
#define ROWS 6
#define COLUMNS 8

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int arr[], int left_index, int right_index)
{
    int pivot = arr[right_index];
	int pivot_index = right_index;
	right_index--; 
	while(left_index <= right_index)
    {
		if(arr[left_index] < pivot)
        {
			left_index++;
			continue;
		}
		else if(arr[right_index] > pivot)
        {
			right_index--;
			continue;
		}
		else
        {
			swap(&arr[left_index], &arr[right_index]);
		}
	}

	swap(&arr[left_index], &arr[pivot_index]);
	return left_index;
}

void quick_sort_func(int arr[], int left_index, int right_index)
{
	if (left_index < right_index) 
    {
		int partition_index = partition(arr, left_index, right_index);

		quick_sort_func(arr, left_index, partition_index - 1);
		quick_sort_func(arr, partition_index + 1, right_index);
	}
}

void print_array_func(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
    system("CLS");
    
	int arr[ROWS][COLUMNS];

    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLUMNS; j++)
        {
            printf("Enter element [%d][%d]:", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

	for(int i=0; i<ROWS; i++)
    {
		int arr_size = sizeof(arr[i]) / sizeof(arr[i][0]);
		printf("\nGiven array is \n");
		print_array_func(arr[i], arr_size);

		quick_sort_func(arr[i], 0, arr_size - 1);

		printf("Sorted array is\n");
		print_array_func(arr[i], arr_size);
	}
	return 0;
}