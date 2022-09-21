#include <stdio.h>

void display(int arr[], int n)
{
    // Code for Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indInsertion(int arr[], int size, int element, int capacity, int index)
{
    // code for Insertion
    if (size >= capacity)
    {
        return 0;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main()
{
    int arr[6] = {7, 8, 12, 27, 88};
    int capacity = sizeof(arr) / sizeof(int);
    int size = 5, element = 45, index = 1;
    display(arr, size);
    int res = indInsertion(arr, size, element, capacity, index);
    if (res)
    {
        size += 1;
        printf("New Array is: ");
        display(arr, size);
    }
    else
    {
        printf("Insertion failed\n");
        printf("Original Array is: ");
        display(arr, size);
    }

    return 0;
}
