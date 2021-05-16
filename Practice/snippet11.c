#include <stdio.h>

void selectionSort(int [], int);

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

    selectionSort(arr, n);

    printf("\nSorted Array:\t");

    for(int idx=0; idx<n; idx++)
    {
        printf("%d\t", arr[idx]);
    }

    return 0;

}

void selectionSort(int arr[], int n)
{
    int minIdx = 0;
    for (int i = 0; i < n-1; i++)
    {
        minIdx = i;
        for (int j = i+1; j < n; j++)
        {
          if (arr[j] < arr[minIdx])
          {
            minIdx = j;
          }
        }

        swap(&arr[minIdx], &arr[i]);
    }
  }

void swap(int *m, int *n)
{
    int temp = *m;
    *m = *n;
    *n = temp;
}