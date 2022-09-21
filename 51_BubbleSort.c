#include <stdio.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortAdaptive(int arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int isSorted = 1;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

int main()
{
    int arr[] = {12, 54, 32, 56, 21, 98, 43};
    int s_arr[] = {1, 5, 8, 12, 16, 23, 34, 45, 56, 67, 78, 89};
    int size = 7;
    int s_size = 12;
    printArray(arr, size);
    bubbleSort(arr, size);
    printArray(arr, size);

    printArray(s_arr, s_size);
    bubbleSortAdaptive(s_arr, size);
    printArray(s_arr, s_size);
    return 0;
}