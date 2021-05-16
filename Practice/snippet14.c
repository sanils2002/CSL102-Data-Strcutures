#include <stdio.h>
#include <stdlib.h>
#define ROWS 5
#define COLUMNS 8


void merge(int arr[], int left_index, int middle_index, int right_index)
{
	int sz_left_arr = middle_index - left_index + 1;
	int sz_right_arr = right_index - middle_index;

	int left_arr[sz_left_arr], right_arr[sz_right_arr];

	for (int i = 0; i < sz_left_arr; i++)
		left_arr[i] = arr[left_index + i];

	for (int j = 0; j < sz_right_arr; j++)
		right_arr[j] = arr[middle_index + 1 + j];

	int i, j, k;

	i = 0; 
	j = 0; 
	k = left_index; 
	while (i < sz_left_arr && j < sz_right_arr) 
    {
		if (left_arr[i] <= right_arr[j]) 
        {
			arr[k] = left_arr[i];
			i++;
		}
		else 
        {
			arr[k] = right_arr[j];
			j++;
		}
		k++;
	}

	while (i < sz_left_arr)
    {
		arr[k] = left_arr[i];
		i++;
		k++;
	}

	while (j < sz_right_arr)
    {
		arr[k] = right_arr[j];
		j++;
		k++;
	}
}

void merge_sort_func(int arr[], int left_index, int right_index)
{
	if (left_index < right_index) 
    {
		int middle_index = (left_index + right_index) / 2;

		/*recursively sort first and second halves*/
		merge_sort_func(arr, left_index, middle_index);
		merge_sort_func(arr, middle_index + 1, right_index);

		merge(arr, left_index, middle_index, right_index);
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

		merge_sort_func(arr[i], 0, arr_size - 1);

		printf("Sorted array is\n");
		print_array_func(arr[i], arr_size);
	}
	return 0;
}