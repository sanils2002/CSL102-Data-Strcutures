#include <stdio.h>

int binarySearch(int [], int, int);

int main()
{
    system("CLS");
    
    int sz, key;

    printf("\nEnter size of array:");
    scanf("%d", &sz);
    
    printf("\nEnter key:");
    scanf("%d", &key);

    int arr[sz];

    for(int idx=0; idx<sz; idx++)
    {
        printf("Enter element [%d]:",idx);
        scanf("%d", &arr[idx]);
    }

    int index = binarySearch(arr, sz, key);

    printf("\nIndex value:%d", index);

    return 0;

}

int binarySearch(int arr[], int sz, int key)
{
    int index = -1;
    int left = 0, right = sz - 1, mid = 0;
    while(left <= right)
    {
        mid = (left + right)/2;
        if (key == arr[mid])
        {
            index = mid;
            break;
        }
        if(arr[mid] < key)
        {
            left = mid+1;
        }
        else
        {
            /*if(arr[mid] > key){}*/
            right = mid-1;
        }
    }

    return index;

  }