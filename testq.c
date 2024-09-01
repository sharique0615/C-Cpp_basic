#include <stdio.h>
#include <stdlib.h>
void maxHeapify(int arr[], int n, int i) 
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])

        largest = left;

    if (right < n && arr[right] > arr[largest])

        largest = right;

    if (largest != i)
     {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, n,largest);
    }
}
void buildMaxHeap(int arr[], int n) 
{
    for (int i = n / 2 - 1; i >= 0; i--)
     {
        maxHeapify(arr, n, i);
    }
}

void printLargerElements(int arr[], int n, int element) 
{
    printf("Elements larger than %d in the max heap: ", element);
    for (int i = 0; i < n; i++)
     {
        if (arr[i] > element)
         {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}
void deleteSecondLargest(int arr[], int *n) {
    if (*n < 2)
     {
        printf("Heap don't contain larg elemnts \n");
        return;
    }
     int largest = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    maxHeapify(arr, *n, 0);

    printf("Second largest element deleted: %d\n", largest);
}
int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    buildMaxHeap(arr, n);
    printf("Max Heap: ");
    for (int i = 0; i < n; i++)
     {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int elementToCompare = 3;
    printLargerElements(arr, n, elementToCompare);

    deleteSecondLargest(arr, &n);
    printf("Max Heap after deleting the second largest element: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}


 