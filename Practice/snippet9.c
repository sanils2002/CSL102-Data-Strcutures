#include <stdio.h>

int linearSearch(int [], int, int);

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

    int index = linearSearch(arr, sz, key);

    printf("\nIndex value:%d", index);

    return 0;

}

int linearSearch(int arr[], int sz, int key)
{
    int index = -1;
    for(int idx = 0; idx < sz; idx++)
    {
        if (key == arr[idx])
        {
            index = idx;
            break;
        }
    }
    return index;
  }
  
