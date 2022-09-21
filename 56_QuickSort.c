#include <stdio.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (arr[i] <= pivot)
        {
            i++; // finding the element larger than pivot
        }

        while (arr[j] > pivot)
        {
            j--; // finding the element smaller than pivot
        }

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    arr[low] = arr[j];
    arr[j] = pivot;
    return j;
}

void quickSort(int arr[], int low, int high)
{
    int partitiionIndex; // Index of pivot after partition
    if (low < high)
    {
        partitiionIndex = partition(arr, low, high);
        quickSort(arr, low, partitiionIndex - 1);  // sort left subarray
        quickSort(arr, partitiionIndex + 1, high); // sort right subarray
    }
}

int main()
{
    int arr[] = {12, 54, 65, 7, 23, 9,32};
    int size = 7;
    printArray(arr, size);
    quickSort(arr, 0, size - 1);
    printArray(arr, size);
    return 0;
}
