#include <stdio.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = arr[i];
        int index = -1;
        for (int j = i; j < size; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                index = j;
            }
        }
        arr[index] = arr[i];
        arr[i] = min;
    }
}

int main()
{
    int arr[] = {12, 54, 65, 7, 23, 9};
    int size = 6;
    printArray(arr, size);
    selectionSort(arr, size);
    printArray(arr, size);

    return 0;
}
