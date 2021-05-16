#include <stdio.h>

void insertionSort(int [], int);

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

    insertionSort(arr, n);

    printf("\nSorted Array:\t");

    for(int idx=0; idx<n; idx++)
    {
        printf("%d\t", arr[idx]);
    }

    return 0;

}

void insertionSort(int arr[], int n)
{
	int key = 0;
    int j = 0;
	for (int i = 1; i < n; i++) 
    {
	   key = arr[i];
	   j = i - 1;

	   while (j >= 0 && arr[j] > key)
       {
		arr[j + 1] = arr[j];
		j = j - 1;
	   }
	   arr[j + 1] = key;
	}
}