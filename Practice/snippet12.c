#include <stdio.h>

void bubbleSort(int [], int);

int main()
{
    system("CLS");
    
    int n;

    printf("\nEnter size of array:");
    scanf("%d", &n);

    printf("\n");
    
    int arr[n];

    for(int idx=0; idx<n; idx++)
    {
        printf("Enter element [%d]:",idx);
        scanf("%d", &arr[idx]);
    }

    bubbleSort(arr, n);

    printf("\nSorted Array:\t");

    for(int idx=0; idx<n; idx++)
    {
        printf("%d\t", arr[idx]);
    }

    return 0;

}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {	
	    for (int j = 0; j < n-i-1; j++)
        {
		    if (arr[j] > arr[j+1])
            {
			    swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void swap(int *m, int *n)
{
    int temp = *m;
    *m = *n;
    *n = temp;
}